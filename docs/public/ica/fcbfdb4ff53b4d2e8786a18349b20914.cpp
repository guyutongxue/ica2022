#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[501]{};
    cin.getline(str, 501);
    int wordStart = -1; // -1 表示不在单词内
    int i = 0;
    for (; str[i]; i++) {
        if (str[i] == ' ') {
            if (wordStart >= 0) {
                for (int j = i - 1; j >= wordStart; j--) {
                    cout << str[j];
                }
                wordStart = -1;
            }
            cout << ' ';
        } else {
            if (wordStart == -1) {
                wordStart = i;
            }
        }
    }
    if (wordStart > 0) {
        for (int j = i - 1; j >= wordStart; j--) {
            cout << str[j];
        }
    }
}