#include <iostream>
using namespace std;

int stirling2(int p, int q) {
    if (p == 1 || q == 1 || p == q) return 1;
    return stirling2(p - 1, q - 1) + q * stirling2(p - 1, q);
}
int main() {
    int n;
    while (cin >> n, n != -1) {
        if (n == 0) {
            cout << 1 << endl;
            continue;
        }
        int num = 0;
        for (int i = 1; i <= n; i++) {
            num += stirling2(n, i);
        }
        cout << num << endl;
    }
}