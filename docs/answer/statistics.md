# 关于题目“统计字符”

[这道题目](https://programming.pku.edu.cn/probset/570939369cef4ad18de4261b375ba508/8f7db698f280414f84460c387876bfd6/?problemsId=570939369cef4ad18de4261b375ba508)有两个问题。

## 提示中的 `gets` 函数不可用

C++14 标准移除了 `std::gets` 函数，所以这里不能用它。你应该改用 `cin.getline` 或者  `std::getline`。

## 中文出现乱码

2021 年更新编程网格时，编程网格的网站出现了编码错误：它期望我们上交的代码是 UTF-8 编码，但标准答案却是 GBK 编码的。随后在比较标准答案时，GBK 编码的汉字被解析为 Unicode 替换字符（即解析出错）。

我们只好将错就错。如果这道题你得到了乱码的结果，请使用两个 [Unicode 替换字符](https://unicode-table.com/en/FFFD/) `��` 来替换单个汉字：

```cpp
    std::cout << "*������" << starNum << "��;" << std::endl;
    std::cout << "@������" << atNum << "��." << std::endl;
```

## 完整解答（待调整）

```cpp
#include <iostream>
#include <string>
#include <algorithm>
int main() {
    std::string a;
    std::getline(std::cin, a);

    auto starNum = std::count(a.begin(), a.end(), '*');
    auto atNum = std::count(a.begin(), a.end(), '@');

    std::cout << "*������" << starNum << "��;" << std::endl;
    std::cout << "@������" << atNum << "��." << std::endl;
}
```
