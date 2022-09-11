# 关于 EOF

> 这一篇内容节选自[谷雨同学的 C++ 教程第四章](https://learn-cpp.tk/ch04/io/input_fail.html)。可以直接阅读原文以获得更多相关信息。

有些题目，它要求直接输入 n 行字符串，但不告诉你 n 是多少。比如样例输入是：

```
foo
bar
baz
```

你的程序需要从这种输入得出 n 为 3，且三个字符串分别是 `foo` `bar` `baz`。显然，用 for 循环的话需要提前知道 n，所以这里没法简单的用 for 循环。那么正确的做法是：**不断读取输入直至文件结尾**（EOF）。

## 什么是文件结尾（EOF）

在目前的学习阶段，我们经常接触的输入输出方式可能是在控制台中，通过键盘向程序输入信息，通过显示屏输出信息。然而在现实的应用中，更常使用的是**文件输入输出**。也就是说，C++ 程序将从一个文件读取输入，并将信息输出到另外一个文件中去。在线评测系统，包括我们的编程网格就是使用的文件输入输出。

从文件读取输入时，如果已经没有东西可以读取了（比如文件只有一个数，却要 `cin` 两个数），那么就可以说输入“遇到了 EOF”。这里，我们就要利用这条性质来帮助作答。

## 输入失败状态

当 `std::cin` 在读取输入时遇到了意外情况，则会进入**失败状态**。当然，这里就包括遇到 EOF 这种错误。失败状态下，所有的输入操作都会被跳过，且 `std::cin.fail()` 会得到 `true`。

```cpp
#include <iostream>

int main() {
    int n;

    // 此时输入非整数、或者遇到 EOF，就会导致 cin 失败
    std::cin >> n;

    if (std::cin.fail()) {
        std::cout << "Input failed!" << std::endl;
    }
}
```

那么，最初的例子就可以用这样的逻辑实现：“每次读取一行输入后，检查 `std::cin.fail()`；若为假则继续循环，否则结束读取”。

```cpp
#include <iostream>

int main() {
    char strs[100][256]{};
    int n{0};
    while (true) {
        std::cin.getline(strs[n], 256);
        if (std::cin.fail()) {
            break;
        } else {
            n++;
        }
    }
    // [...]
    for (int i = 0; i < n; i++) {
        std::cout << strs[i] << std::endl;
    }
}
```

## 利用 `operator bool`

刚刚的写法是 OK 的，但稍微复杂了一点。我们可以利用 `cin` 的一条特性来简化。这个特性就是：如果 `std::cin` 处于失败状态下，则它转换到布尔类型会得到 `false`。

```cpp
#include <iostream>

int main() {
    char strs[100][256]{};
    int n{0};
    while (std::cin.getline(strs[n], 256)) {
        n++;
    }
    // [...]
}
```

就像这样，将 `std::cin.getline(...)` 放在循环条件上。当循环开始时，输入执行；输入成功时循环条件为 `true`（从 `cin` 转换得到），于是继续下一轮读取。否则，输入失败，循环条件为 `false`，退出循环。

## 在终端上模拟 EOF

最后一个问题，就是在本地写代码的时候一般不是文件输入输出，而是基于终端模拟器的交互式运行。此时，我们需要手动模拟 EOF，或者说手动引发一个 EOF 错误。具体的方法是：

| Windows                                                               | macOS                                                 | GNU/Linux           |
| --------------------------------------------------------------------- | ----------------------------------------------------- | ------------------- |
| 依次按下：<br><kbd>Enter</kbd>，<kbd>Ctrl + Z</kbd>，<kbd>Enter</kbd> | 依次按下：<br><kbd>Return</kbd>，<kbd>Control+D</kbd> | <kbd>Ctrl + D</kbd> |

> 在少数环境如 CLion 内置终端下可能不起作用。

[原文](https://learn-cpp.tk/ch04/io/input_fail.html)还描述了更多会导致 `cin` 失败的情形，以及清除失败状态的方法，有兴趣的同学可以进一步阅读。
