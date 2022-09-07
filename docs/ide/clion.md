# CLion 使用说明

首先，CLion 是付费软件。我不推荐你安装破解版，请支持正版。在[这里](https://www.jetbrains.com/zh-cn/clion/download/)获取。你可以试试[申请学生认证](https://www.jetbrains.com/zh-cn/community/education/#students)，这样就能免费使用 CLion。

下载完成首次启动 CLion 时，它会自动检测编译器等必要工具的配置。如果它提示缺了什么，就按照说明安装必要的软件。

在 CLion 的欢迎界面中点击 “New Project”，然后选择项目类型为 C++ Executable （C++ 可执行文件）。选择你的项目存放路径，同时选择语言标准（我建议你用最新的标准 C++20)。

新建完成后，CLion 会为你打开两个文件 `CMakeList.txt` 和 `main.cpp` 。其中 `main.cpp` 是你要编写 C++ 程序的位置，另外一个可以不用管它。在 `main.cpp` 中写好代码后，点击右上角绿色三角图标，就可以成功地编译并运行。如果没有问题的话，下方会弹出一个子窗口并显示输入和输出；默认的输入会用绿色字体以示区别。

## 注意事项

CLion 和 VS 一样是基于项目的开发流程，因此如果你想要写一份新代码，请新建项目（New Project），而不是添加源文件。

不要管也不要动 `CMakeList.txt`。如果你很好奇的话，可以看看 [CMake 官网](https://cmake.org)。