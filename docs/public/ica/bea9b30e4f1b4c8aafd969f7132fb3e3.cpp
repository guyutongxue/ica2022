#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    double n;
    while (cin >> n) {
        int cnt = 0;
        double error = 1.0, x = 1.0;
        while (error > 1e-6) {
            double old_x = x;
            x = (x + n / x) / 2;
            cnt++;
            error = abs(x - old_x);
        }
        cout << cnt;
        cout << fixed << setprecision(2) << ' ' << x << endl;
    }
}