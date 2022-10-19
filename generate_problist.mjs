// @ts-check

import fetch from "node-fetch";
import * as fs from "node:fs";
import * as path from "node:path";

const ANSWER_DIRECTORY = "pg_answer_easy";
const OUTPUT_FILE = `dist/${ANSWER_DIRECTORY}.md`;

/** @type {Record<string, string>} */
let _cookie = {
  PG_client:
    "jigai_dot_tk; Max-Age=315360000; Expires=Fri, 05-Dec-2031 05:34:07 GMT; Path=/; Secure",
};
function saveCookie(/** @type {string[]} */ cookie) {
  for (const c of cookie) {
    const [key, ...value] = c.split("=");
    _cookie[key] = value.join("");
  }
}
/**
 * @returns {{ cookie?: string }}
 */
function loadCookie() {
  const cookie = Object.entries(_cookie)
    .map(([k, v]) => `${k}=${v}`)
    .join("; ");
  return {
    cookie,
  };
}
const userAgent =
  "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/92.0.4515.131 Safari/537.36 Edg/92.0.902.73";
const acceptLanguage = "zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6";
const headers = {
  "User-Agent": userAgent,
  "Accept-Language": acceptLanguage,
};

function getUsername() {
  return process.env.PG_USERNAME;
}
function getPassword() {
  return process.env.PG_PASSWORD;
}

async function login() {
  const username = getUsername();
  const password = getPassword();
  if (!username || !password) {
    console.log("Login fail: no username or password");
    return false;
  }
  const data = new URLSearchParams();
  data.append("appid", "ProgrammingGrid");
  data.append("userName", username);
  data.append("password", password);
  data.append("randCode", "");
  data.append("smsCode", "");
  data.append("otpCode", "");
  data.append("redirUrl", "https://programming.pku.edu.cn/authcallback");
  return fetch("https://iaaa.pku.edu.cn/iaaa/oauthlogin.do", {
    method: "POST",
    headers: {
      ...headers,
      "Content-Type": "application/x-www-form-urlencoded; charset=UTF-8",
    },
    redirect: "manual",
    body: data,
  })
    .then((r) => r.json())
    .then((/** @type {any} */ json) => {
      console.log(json);
      if (json.success !== true) {
        console.log("Login fail: IAAA success = false");
        return false;
      }
      return fetch(
        `https://programming.pku.edu.cn/authcallback?_rand=${Math.random()}&token=${
          json.token
        }`,
        {
          headers: {
            ...headers,
            ...loadCookie(),
          },
          redirect: "manual",
        }
      ).then((r) => {
        const cookie = r.headers.get("Set-Cookie");
        if (cookie === null) {
          console.log("Login fail: no Set-Cookie field");
          return false;
        }
        console.log("Login success.");
        saveCookie(cookie.split(', '));
        console.log(_cookie);
        return true;
      });
    })
    .catch((err) => {
      console.log(err);
      console.log("Login fail: exception");
      return false;
    });
}

const COURSE_ID = "0b0ead5e1550494cb060fca75d9e2604";

(async () => {
  if (!(await login())) process.exit();
  const setInfos = await fetch(
    `https://programming.pku.edu.cn/course/${COURSE_ID}/?type=json`,
    {
      headers: {
        ...headers,
        ...loadCookie(),
      },
    }
  )
    .then((r) => r.json())
    .then(
      (
        /** @type {{ course: { problemlists: { id: string, title: string }[] }}} */ j
      ) => {
        return j.course.problemlists.filter(({ title }) => !title.includes("所有作业") && !title.includes("（0）"));
      }
    );
  const problemInfo = await Promise.all(
    setInfos.map(async (set) => {
      console.log(`Fetch set: ${set.id}`);
      return fetch(
        `https://programming.pku.edu.cn/probset/${set.id}/?type=json`,
        {
          headers: {
            ...headers,
            ...loadCookie(),
          },
        }
      )
        .then((r) => r.json())
        .then(async (/** @type {any} */ json) => {
          /**
           * @type {{
           *  title: string,
           *  id: string
           * }[]} */
          const problems = json.problemlist.problems;
          return {
            title: set.title,
            id: set.id,
            problems: await Promise.all(
              problems.map(async ({ id }) => {
                console.log(`Set ${set.id}, Fetch problem: ${id}`);
                return fetch(
                  `https://programming.pku.edu.cn/probset/${set.id}/${id}/?type=json`,
                  {
                    headers: {
                      ...headers,
                      ...loadCookie(),
                    },
                  }
                )
                  .then((r) => r.json())
                  .then((/** @type {any} */ json) => {
                    /**
                     * @type {{
                     *  title: string,
                     *  id: string;
                     *  description: string,
                     *  aboutInput: string;
                     *  aboutOutput: string;
                     * }} */
                    const problem = json.problem;
                    function htmlify(/** @type {string} */ str) {
                      return `<p>${str
                        .replace(/\n/g, "<br>")
                        .replace(/<\/?strong>/g, "")
                        .replace(/<\/?font(\s.*?)?>/g, "")}</p>`;
                    }
                    return {
                      title: problem.title,
                      id: problem.id,
                      description: htmlify(problem.description),
                      aboutInput: htmlify(problem.aboutInput),
                      aboutOutput: htmlify(problem.aboutOutput),
                    };
                  });
              })
            ),
          };
        });
    })
  );

  fs.writeFileSync("docs/public/problist.json", JSON.stringify(problemInfo));
})();
