#include <iostream>
using namespace std;

int main() {
    int cnt;
    cin >> cnt;
    for (int i = 1; i <= cnt; i++) {
        double b, c;
        cin >> b;
        c = 5 * (b - 32) / 9;
        cout << fixed;
        cout.precision(5);
        cout << c << endl;
    }
}