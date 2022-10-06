#include <iostream>
using namespace std;

int t[1002] = {};

int main() {
    int n, k, h;
    int prev_a = 0;
    cin >> n >> k >> h;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if ((a - prev_a) * k < h) {
            t[i] = (a - prev_a) * k;
            h -= t[i];
        } else {
            t[i] = h;
            h = 0;
        }
        prev_a = a;
    }
    t[n] = h;
    int exp = 0;
    for (int i = 0; i <= n; i++) {
        int b;
        cin >> b;
        exp += b * t[i];
    }
    cout << exp << endl;
}
