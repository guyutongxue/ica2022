# Visual Studio Code 配置说明

1. 到[这里](https://code.visualstudio.com)下载 Visual Studio Code；
2. 到[这里](https://v4.vscch.tk)下载 C++ 配置工具；
3. 运行配置工具，按照提示操作。[配置工具的文档](https://v4.vscch.tk/docs)提供了更多的说明。

> 配置工具为个人开发，难免会遇到各种各样的 bug。如遇到问题，请私戳谷雨助教。

## VS Code 和 VS 的关系

答案：雷峰塔和雷锋的关系。（程序员喜欢用“JavaScript 和 Java 的关系”。）

VS Code 官方上被称为一个文本编辑器（粗略地说，70% 像 IDE，30% 像文本编辑器）。这是因为，它本身不包含编译器。当我们配置 VS Code 时，其实包括了这些步骤：
- 获取编译器；VS Code 并不包含它们所以必须自行获取；
- 让 VS Code 知道编译器在哪儿；
- 告诉 VS Code 如何运用编译器编译代码。

所以，这个配置的步骤是省略不了的。但也正因如此，我们可以通过调整配置，实现了适合初学者的“单文件”开发配置。这也是我推荐 VS Code 的最重要原因。

而 VS 作为 IDE，则囊括了大量编译器（但你可以不下载它们），比如：
- Microsoft Visual C++，简称 MSVC 的三大家 C++ 编译器之一；
- .NET Framework 与 .NET，编程语言 C#、F# 和 Visual Basic 的核心；
- Python、Node.js 等各种编译器或解释器。

一旦你在安装 VS 时勾选了它们，那么 VS 就会自动处理好剩下的所有事情。之后的事情你也知道了，新建项目后就可以直接编译运行了。
