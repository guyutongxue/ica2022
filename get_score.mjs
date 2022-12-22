// @ts-check

import * as Cheerio from "cheerio";
import fetch from "node-fetch";
import { appendFile } from "node:fs/promises";
import { COURSE_ID, headers, loadCookie, login } from "./generate_problist.mjs";

const STUDENTS = [
  "1900011810",
  "2000012854",
  "2100011603",
  "2100013533",
  "2100015836",
  "2100017826",
  "2100094630",
  "2110305105",
  "2200010776",
  "2200010863",
  "2200011613",
  "2200011792",
  "2200012716",
  "2200012729",
  "2200012759",
  "2200012827",
  "2200012830",
  "2200012831",
  "2200012835",
  "2200012843",
  "2200012862",
  "2200012868",
  "2200012873",
  "2200012878",
  "2200012882",
  "2200012915",
  "2200012945",
  "2200012956",
  "2200012961",
  "2200012971",
  "2200013074",
  "2200013078",
  "2200013130",
  "2200013151",
  "2200013168",
  "2200013173",
  "2200013177",
  "2200013183",
  "2200013208",
  "2200013210",
  "2200013213",
  "2200013276",
  "2200013303",
  "2200015490",
  "2200017421",
  "2200017760",
  "2200017803",
  "2200017838",
  "2200017848",
  "2200017849",
  "2200090105",
  "2200094811",
  "2200094821",
  "2200094822",
];

/** @type {Map<string, Map<string, { ac: number, wa: number }>>} */
const data = new Map(STUDENTS.map(no => [no, new Map()]));

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
        return j.course.problemlists.filter(
          ({ title }) => !title.includes("不记成绩") && !title.includes("考试")
        );
      }
    );
  /** @type {{ id: string, title: string, total: number }[]} */
  const basicInfo = [];
  for (const set of setInfos) {
    await fetch(
      `https://programming.pku.edu.cn/probset/${set.id}/ranks.do`,
      {
        headers: {
          ...headers,
          ...loadCookie(),
        },
      }
    )
      .then((r) => r.text())
      .then((text) => {
        const $ = Cheerio.load(text);
        basicInfo.push({
          id: set.id,
          title: set.title,
          total: $("th a").length,
        });
        for (const tr of $("tr.resultrow")) {
          const number = $(tr).children("td").eq(2).text();
          const re = $(tr).children(".re").text();
          if (!data.has(number)) continue;
          const entry = data.get(number);
          entry.set(set.id, {
            ac: (re.match(/0/g) ?? []).length,
            wa: (re.match(/1/g) ?? []).length
          });
        }
      });
  }

  const FILENAME = "score.csv";
  await appendFile(FILENAME, Uint8Array.from([0xef, 0xbb, 0xbf])); // utf8 bom

  await appendFile(FILENAME, ",");
  for(const i of basicInfo) {
    await appendFile(FILENAME, i.title + ",,");
  }
  await appendFile(FILENAME, "\n,");
  for(const i of basicInfo) {
    await appendFile(FILENAME, i.total + ",,");
  }
  for (const [k, v] of data.entries()) {
    await appendFile(FILENAME, `\n${k},`);
    for(const i of basicInfo) {
      const entry = v.get(i.id);
      if (typeof entry === "undefined") {
        await appendFile(FILENAME, "0,0,");
      } else {
        await appendFile(FILENAME, `${entry.ac},${entry.wa},`);
      }
    }
  }
})();
