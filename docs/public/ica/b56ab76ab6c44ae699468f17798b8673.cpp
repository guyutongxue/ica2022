#include <iostream>
using namespace std;

bool judge(int a, int b) {
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }
    if (a / b >= 2 || a == b) return true;
    return !judge(b, a - b);
}

int main() {
    int a, b;
    while (cin >> a >> b, a) {
        cout << (judge(a, b) ? "win" : "lose") << endl;
    }
}