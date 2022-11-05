# 关于 GUI 开发

![](https://s1.ax1x.com/2022/11/05/xOowIH.png)
> 2021 级沈大为同学的计概 A 大作业《同化棋》

GUI，即 Graphics User Interface，图形用户界面。我们日常能接触到的大部分计算机程序，都是图形界面的，比如浏览器、Office、VS Code 等等。但编写图形界面应用程序的复杂度，相比普通的基于输入输出的应用程序要困难得多。

现代的图形界面程序，其复杂程度不是我们大一学生能够妥善处理的（当然你可以<ruby>试试<rt>逝世</rt></ruby>）。但是，我们可以回顾一下历史——上个世纪，有一家公司叫 Borland，它推出了一个简洁的 C 开发环境叫 Borland C，现在已经没人用了。这个 Borland C 提供了一个小型的图形接口 Borland Graphics Interface，简称 BGI。BGI 使用数十个非常简短的函数定义，就可以绘制出简单但是有用的图形界面。在今天，虽然 BGI 已经随着 Borland C 消失在历史长河之中，但是有一些小众的库在 Windows 上模拟了 BGI 的所有接口。

## BGI

::: warning

这一节的内容仅适用于 Windows。目前所有模拟 BGI 的库，都是仅 Windows 的；如果你使用其它操作系统，请跳转到[下一节](#qt)。

:::

中国人大多很懒，许多人抱着上个世纪的 Borland C 的教材学习；而懒惰也催生出了开发模拟 BGI 库的动力。于是，[EGE 图形库](https://xege.org)就这样诞生了。

> 类似的库还有 EasyX，也是模拟 BGI 的绘图库。但它闭源，而且仅支持 VS，我是很不喜欢。别的班助教可能会让同学用这个。

总之，我们要使用一个叫做 EGE 的第三方库，帮助我们完成图形界面的绘制。但引入第三方库对于新手来说是一个不小的挑战；如果你做好准备了，那我们就继续吧。

### 下载 Xmake 构建管理器

前往 [xmake.io](https://xmake.io/#/zh-cn/guide/installation?id=%e4%bd%bf%e7%94%a8powershell) 下载并安装 Xmake。这个操作对于电脑小白来说或许有一定难度，但你可以自己先鼓捣鼓捣，不会弄的话问问其它同学。

哦对了，请保证网络通畅。（言外之意是……）

### 创建一个新的工作文件夹

你如果很听话的话，你应该电脑上安装了 VS Code。呃——如果没有的话，我建议你取下一个，因为它真的蛮好用的。我在这里就假设你们都安装了吧。然后，你应该已经熟练掌握了使用 VS Code 运行“单文件”C++ 程序的方法了（如果不会的话，就看看[这个](../ide/vscode)）。

但是呢，和往常编程不太一样，我们现在要在原来的工作文件夹之外，**新建一个独立的文件夹**用来写大作业。这是因为，原来的工作文件夹被配置为“单文件编译”，而如果带上第三方库的话，就不能叫“单文件”了。所以，我们需要一个新的地方，使用新的配置。

如果网络条件好的话，你可以直接下载 [vscode-xege-template](https://github.com/Guyutongxue/vscode-xege-template) 这个仓库。里面已经准备好所有你需要的文件（然后你可以跳过接下来所有创建文件的操作）。

### 配置 Xmake

用 VS Code 打开这个新建的文件夹（当然，路径上不要带中文）。新建一个名为 `xmake.lua` 的文件，内容如下：

```lua
add_requires("xege")

target("my-ege-project") -- 注：my-ege-project 可以修改为任意名字。
    add_packages("xege")
    add_files("src/*.cpp")
```

Xmake 提供了第三方库包管理的功能，所以这里直接通过 `add_requires` 和 `add_packages` 就完成了对第三方库的引用。这里的 `add_files("src/*.cpp")` 意思是，所有的源文件都放在 `src` 文件夹里。所以，我们建立一个 `src` 文件夹，在其中新建 `main.cpp` 内容如下：

```cpp
#include <graphics.h>
int main() {
    initgraph(640, 480);
    setfillcolor(RGB(0, 255, 255));
    fillellipse(200, 200, 50, 50);
    setfillcolor(RGB(0, 0, 0));
    setcolor(RGB(0, 0, 0));
    fillellipse(220, 220, 50, 50);
    getch();
}
```

`<graphics.h>` 就是 BGI 的接口文件。你也可以用 `<ege.h>` 外加 `using namespace ege;`。这里的代码，运用 BGI 中定义的一些函数，绘制一个月亮的形状。

接下来，菜单栏“终端”中“新建终端”，键入

```sh
xmake f -pmingw
```

> 如果你电脑上有安装 VS，那么就可以省略掉 `-pmingw`。

Xmake 可能会询问你是否安装依赖库，直接回车确认即可。如果一切顺利，你会看到最终有一个 `ok` 的字样。接下来，执行

```sh
xmake b
xmake r
```

就可以编译并运行你的程序了。你应该能看到绘制了图形的窗口弹了出来。在该窗口上，按任意键盘上的按键退出程序。

### 启用 VS Code 的智能提示

VS Code 第一次肯定会告诉你 `<graphics.h>` 找不到之类的错误。这是因为我们没有配置关于智能提示的设置。你可以做这样的操作：新建文件 `.vscode/c_cpp_properties.json`，写入：

```json
{
  "version": 4,
  "configurations": [
    {
      "name": "Win32",
      "compileCommands": "${workspaceFolder}\\.vscode\\compile_commands.json"
    }
  ]
}
```

然后，运行命令

```sh
xmake projects -kcompile_commands .vscode
```

即可。你如果直接从 GitHub 上下载了我提供的模板，则可以 Ctrl+Shift+P ，“Run Tasks” 中运行 “update intellisense”。如果你还安装了[Xmake VS Code 扩展](https://marketplace.visualstudio.com/items?itemName=tboox.xmake-vscode)，则还可以运行 “Xmake: Update IntelliSense” 命令。一般这个操作只用做一次，智能提示失效的时候再重新执行就可以。

### 运行快捷键

F6 运行的话，则稍微复杂一点。最简单的，你直接上 GitHub 把[这个文件](https://github.com/Guyutongxue/vscode-xege-template/blob/main/.vscode/tasks.json)的内容存放在 `.vscode/tasks.json` 里就 OK 了。手动写的话，就在 `.vscode/tasks.json` 中存放如下内容：

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "xmake build",
      "group": {
        "kind": "build",
        "isDefault": true
      },
      "command": "xmake",
      "problemMatcher": "$gcc" // 如果你使用 MSVC，请更改为 $msCompile
    },
    {
      "label": "run and pause",
      "dependsOn": "xmake build",
      "type": "pause-console",
      "command": "xmake",
      "args": [
        "r"
      ],
      "problemMatcher": []
    }
  ]
}
```

关于 BGI/EGE 的使用，你可以在百度上搜索“graphics.h”。你还可以参考 EGE 的[官方文档](https://xege.org/manual/)。具体的我不太懂，就不多说了；请同学们自己探索。

## Qt

::: info

未完待续

:::
