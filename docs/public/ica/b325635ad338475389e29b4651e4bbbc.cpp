#include <iostream>
using namespace std;

// 这个程序在 Clang 编译器上貌似得不到正确结果
// 有机会再修吧

int main() {
    int n;
    cin >> n;
    cout << fixed;
    cout.precision(2);
    for (int i = 1; i <= n; i++) {
        cout << "Problem #" << i << endl;
        bool known[256]{};
        float knownValue[256]{};
        char trash[200]{};
        cin.getline(trash, 200, '=');
        float firstNumber;
        cin >> firstNumber;
        char x;
        cin.get(x);
        if (x == 'm') {
            firstNumber *= 1e-3;
            cin.get(x);
        } else if (x == 'k') {
            firstNumber *= 1e3;
            cin.get(x);
        } else if (x == 'M') {
            firstNumber *= 1e6;
            cin.get(x);
        }
        known[x] = true;
        knownValue[x] = firstNumber;

        cin.getline(trash, 200, '=');
        float secondNumber;
        cin >> secondNumber;
        cin.get(x);
        if (x == 'm') {
            secondNumber *= 1e-3;
            cin.get(x);
        } else if (x == 'k') {
            secondNumber *= 1e3;
            cin.get(x);
        } else if (x == 'M') {
            secondNumber *= 1e6;
            cin.get(x);
        }
        known[x] = true;
        knownValue[x] = secondNumber;

        if (known['V'] && known['A']) {
            cout << "P=" << firstNumber * secondNumber << "W" << endl;
        } else if (known['V'] && known['W']) {
            cout << "I=" << knownValue['W'] / knownValue['V'] << "A" << endl;
        } else {
            cout << "U=" << knownValue['W'] / knownValue['A'] << "V" << endl;
        }
        cout << endl;
    }
}