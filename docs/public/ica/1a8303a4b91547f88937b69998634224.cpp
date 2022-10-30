#include <cstring>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char pwd[51]{};
        cin >> pwd;
        int len = strlen(pwd);
        if (len < 6) {
            cout << "Not safe" << endl;
            continue;
        }
        bool hasDigit{}, hasUpper{}, hasLower{}, hasOther{};
        for (int i = 0; i < len; i++) {
            if (pwd[i] >= '0' && pwd[i] <= '9') {
                hasDigit = true;
            } else if (pwd[i] >= 'a' && pwd[i] <= 'z') {
                hasLower = true;
            } else if (pwd[i] >= 'A' && pwd[i] >= 'Z') {
                hasUpper = true;
            } else {
                hasOther = true;
            }
        }
        // 利用 bool -> int 的隐式转换
        int categories = hasDigit + hasUpper + hasLower + hasOther;
        switch (categories) {
            case 1: cout << "Not safe" << endl; break;
            case 2: cout << "Medium safe" << endl; break;
            default: cout << "Safe" << endl; break;
        }
    }
}