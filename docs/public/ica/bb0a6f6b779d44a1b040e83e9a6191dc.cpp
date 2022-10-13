#include <iostream>
using namespace std;
int main() {
    int h, n[6]{};
    cin >> h;
    for (int i = 1; i <= 5; i++) {
        cin >> n[i];
    }
    h *= 100;
    for (int s = 1; s <= h; s++) {
        for (int a = 1; a <= s / n[1]; a++) {
            int b = s - a * n[1];
            int c = s - b * n[2];
            int d = s - c * n[3];
            int e = s - d * n[4];
            if (e * n[5] + a == s && a != b && a != c && a != d && a != e && b != c && b != d &&
                b != e && c != d && c != e && d != e) {
                cout << s << ' ' << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << endl;
                exit(0);
            }
        }
    }
    cout << "not found";
}