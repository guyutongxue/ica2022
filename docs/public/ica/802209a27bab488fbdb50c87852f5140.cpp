#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int n, cnt = 1;
    cin >> n;
    for (int c = 0; c <= n / 5; c++) {
        for (int b = 0; b <= n / 2; b++) {
            for (int a = 0; a <= n; a++) {
                if (a + 2 * b + 5 * c == n) {
                    cout << setfill('0') << setw(3) << cnt++;
                    cout << setfill(' ') << setw(12) << a;
                    cout << setfill(' ') << setw(12) << b;
                    cout << setfill(' ') << setw(12) << c << endl;
                }
            }
        }
    }
}