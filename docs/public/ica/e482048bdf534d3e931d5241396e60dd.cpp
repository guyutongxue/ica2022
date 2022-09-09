#include <iostream>
using namespace std;

bool validate(int a) {
    char s[1000] = {};
    int len = 0;
    while (a) {
        s[++len] = a % 10;
        a /= 10;
    }
    bool result = true;
    for (int i = 1; i <= len / 2; i++) {
        if (s[i] != s[len + 1 - i]) {
            result = false;
            break;
        }
    }
    return result;
}
int reverse(int a) {
    int result = 0;
    while (a) {
        result = result * 10 + a % 10;
        a /= 10;
    }
    return result;
}
int main() {
    int a;
    cin >> a;
    int i = 0;
    for (; i < 7; i++) {
        int b = reverse(a);
        int c = a + b;
        cout << a << '+' << b << '=' << c << endl;
        if (validate(c)) {
            break;
        }
        a = c;
    }
    if (i == 7)
        cout << "N" << endl;
    else
        cout << "Y" << endl;
}