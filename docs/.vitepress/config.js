// @ts-check
import mdk from "@renbaoshuo/markdown-it-katex";

export default {
  lang: "zh-CN",
  title: "计算概论 A",
  themeConfig: {
    sidebar: [
      {
        text: "开发环境",
        items: [
          {
            text: "开发环境概述",
            link: "/ide/",
          },
          {
            text: "Visual Studio",
            link: "/ide/vs",
          },
          {
            text: "Visual Studio Code",
            link: "/ide/vscode",
          },
          {
            text: "CLion",
            link: "/ide/clion"
          },
          {
            text: "在线开发环境",
            link: "/ide/online"
          },
          {
            text: "Dev-C++",
            link: "/ide/devcpp"
          }
        ],
      },
      {
        text: "编程网格",
        items: [
          {
            text: "编程网格概述",
            link: "/grid/",
          },
          {
            text: "基本使用说明",
            link: "/grid/basic"
          },
          {
            text: "“在线 IDE”",
            link: "/grid/ide"
          },
          {
            text: "VS Code 扩展",
            link: "/grid/vscode"
          },
          {
            text: "提交结果说明",
            link: "/grid/submit_result"
          },
          {
            text: "常见问题",
            link: "/grid/faq"
          }
        ],
      },
      {
        text: "C++",
        items: [
          {
            text: "C++ 概述",
            link: "/cpp/",
          },
          {
            text: "常见问题",
            link: "/cpp/faq",
          },
          {
            text: "与 C 的关系",
            link: "/cpp/c"
          },
          {
            text: "未定义行为",
            link: "/cpp/ub"
          },
          {
            text: "EOF",
            link: "/cpp/eof"
          },
          {
            text: "编码",
            link: "/cpp/encoding"
          },
          {
            text: "展望未来",
            link: "/cpp/future"
          }
        ],
      },
      {
        text: "大作业",
        items: [
          {
            text: "概述",
            link: "/assignment/"
          },
          {
            text: "不围棋规则",
            link: "/assignment/rule"
          },
          {
            text: "评分标准",
            link: "/assignment/scoring"
          },
          {
            text: "关于 TUI 开发",
            link: "/assignment/tui"
          },
          {
            text: "关于 GUI 开发",
            link: "/assignment/gui"
          },
          {
            text: "算法提示",
            link: "/assignment/algorithm"
          },
          {
            text: "Botzone 使用方法",
            link: "/assignment/botzone"
          },
          {
            text: "关于 Botzone CLI",
            link: "/assignment/cli"
          }
        ]
      },
      {
        text: "课件勘误",
        items: [
          {
            text: "勘误列表",
            link: "/errata/",
          },
        ],
      },
      {
        text: "习题答案",
        items: [
          {
            text: "习题答案",
            link: "/answer/",
          },
          {
            text: "“抄程序”练习",
            link: "/answer/copy"
          }
        ],
      },
      {
        text: "小工具",
        items: [
          {
            text: "编译信息翻译",
            link: "/app/translation",
          },
        ],
      },
    ],
  },
  markdown: {
    config: (md) => {
      md.use(mdk);
    }
  }
};
