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

## 完整解答

### C++ 风格

```cpp
#include <iostream>
#include <string>
#include <algorithm>
int main() {
    std::string a;
    std::getline(std::cin, a);

    auto starNum = std::count(a.begin(), a.end(), '*');
    auto atNum = std::count(a.begin(), a.end(), '@');

    std::cout << "*出现了" << starNum << "次;" << std::endl;
    std::cout << "@出现了" << atNum << "次." << std::endl;
}
```

### 计概 A 风格

```cpp
#include <iostream>
using namespace std;

int main() {
    char a[1001] = {};
    cin.getline(a, 1000);
    int num1 = 0, num2 = 0;
    for (int i = 0; a[i] != '\0'; i++) {
        if (a[i] == '*')
            num1++;
        if (a[i] == '@')
            num2++;
    }
    cout << "*出现了" << num1 << "次;" << endl;
    cout << "@出现了" << num2 << "次." << endl;
}
```
