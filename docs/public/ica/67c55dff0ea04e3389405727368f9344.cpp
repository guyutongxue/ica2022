#include <iostream>
using namespace std;
bool flag[10] = {};

void get_flag(int x) {
    while (x) {
        flag[x % 10] = true;
        x /= 10;
    }
}
int main() {
    for (int i = 123; i <= 329; i++) {
        for (int j{1}; j <= 9; j++) {
            flag[j] = false;
        }
        int x1 = i, x2 = 2 * i, x3 = 3 * i;
        get_flag(x1);
        get_flag(x2);
        get_flag(x3);
        bool result = true;
        for (int j = 1; j <= 9; j++) {
            result &= flag[j];
        }
        if (result) {
            cout << x1 << ' ' << x2 << ' ' << x3 << endl;
        }
    }
}