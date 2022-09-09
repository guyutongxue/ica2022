#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (a < b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    int r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        a /= gcd(a, b);
        b /= gcd(a, b);
        int d = 0, res = 0;
        while (a != 1 || b != 1) {
            if (a > b) {
                a -= b;
                res += (1 << d);
            } else {
                b -= a;
            }
            d++;
        }
        cout << (1 << d) + res << endl;
    }
}