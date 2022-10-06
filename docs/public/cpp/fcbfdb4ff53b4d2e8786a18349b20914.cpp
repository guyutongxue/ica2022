#include <iostream>
#include <string>

int main() {
    std::string str;
    std::getline(std::cin, str);
    int wordStart = -1; // -1 表示不在单词内
    int i = 0;
    for (; str[i]; i++) {
        if (str[i] == ' ') {
            if (wordStart >= 0) {
                for (int j = i - 1; j >= wordStart; j--) {
                    std::cout << str[j];
                }
                wordStart = -1;
            }
            std::cout << ' ';
        } else {
            if (wordStart == -1) {
                wordStart = i;
            }
        }
    }
    if (wordStart > 0) {
        for (int j = i - 1; j >= wordStart; j--) {
            std::cout << str[j];
        }
    }
}