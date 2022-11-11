---
# https://github.com/vuejs/vitepress/issues/529
head:
  - - link
    - rel: stylesheet
      href: https://cdn.jsdelivr.net/npm/katex@0.16.3/dist/katex.min.css
  - - link
    - rel: stylesheet
      href: https://cdn.bootcdn.net/ajax/libs/KaTeX/0.16.3/katex.min.css
---

# 关于 Botzone Bot

## 重要说明

写在最前面：你**不应当**将大作业代码提交到 Botzone。你提交到 Botzone 的，是一份独立的单个源文件程序，其中包含你大作业中“算法部分”的代码，以及输入输出交互代码。

## 输入输出

Botzone 平台会这样使用你的算法代码：

当轮到“你的算法程序”落子的时候，会启动你的算法程序，并输入所有之前的落子历史。比如，平台向你的程序输入：

```
2
3 1
4 6
7 7
```

意思就是，现在是第 2 回合，你是白棋（后手）。之前，黑棋先下在第三列第一行（零起始，下同），然后白棋下在第四列第六行，黑棋又下在第七列第七行。

随后，你的程序应当推演出当前棋盘的状态，进行决策，并输出最终决定的落子，先列后行。比如，你的程序决定下在第八列第零行，那么就输出：

```
8 0
```

随后，你的算法程序被平台关闭，直到对手落子后，你的程序再被重新启动，输入历史落子，输出决策……这样不停地重复启动直到棋局结束。

如果你的程序执白棋（后手），那么，和刚刚描述的一样，平台会输入回合数 $n$ 和 $2n - 1$ 个历史落子点。但如果你的程序执黑棋（先手），那么平台同样会输入回合数 $n$ 和 $2n - 1$ 个历史落子点，其中第 $1$ 个历史落子点用 `-1 -1` 这个占位符表示。比如

```
2
-1 -1
3 1
4 6
```

的意思就是，程序执黑棋，之前的一个回合黑棋先下在第三列第一行，白棋下在第四列第六行。

## 示例

比如，你的大作业算法部分简化为如下的一个函数：

```cpp
struct Point {
    int x, y;
};

// board 为指向当前棋盘状态的指针
// 棋盘状态中 1 代表黑棋，-1 代表白棋
Point algorithm(int (*board)[9][9]) {
    // 进行玄奥的运算
    return /* 最终决定的落子点 */;
}
```

那么，只要结合如下的 main 函数，就可以实现平台所规定的的输入输出：

```cpp
#include <iostream>
int main() {
    // 棋盘状态
    int board[9][9]{};

    // 回合数
    int turnId;
    std::cin >> turnId;

    // Bot 是否执黑棋（先手）
    [[maybe_unused]] bool isBlack = false;

    // 轮流落子（通过历史落子推演当前状态）
    int color = 1;
    for (int i = 0; i < 2 * turnId - 1; i++) {
        int x, y;
        std::cin >> x >> y;
        if (x == -1) {
            isBlack = true;
        } else {
            board[x][y] = color;
            color *= -1;
        }
    }

    Point result = algorithm(&board);
    std::cout << result.x << ' ' << result.y << std::endl;
}
```

## 附录：简单随机算法

```cpp
#include <random>
#include <vector>
Point algorithm(int (*board)[9][9]) {
    std::vector<Point> available;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (!(*board)[i][j]) {
                available.push_back({i, j});
            }
        }
    }
    std::random_device rd;
    return available[rd() % available.size()];
}
```
