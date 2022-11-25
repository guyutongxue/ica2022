#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int m, n;
        int a[100], b[100];
        cin >> m >> n;
        for (int i = 1; i <= m; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        for (int i = 2; i <= m + n; i++) {
            long long ans = 0;
            for (int j = max(1, i - n); j <= min(m, i - 1); j++) {
                ans += a[j] * b[i - j];
            }
            cout << ans << "\n "[i < m + n];
        }
    }
}