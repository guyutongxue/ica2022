#include <algorithm>
#include <iostream>
using namespace std;
int n, t;
int a[1010];
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        int end = n - 1;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int res = 0;

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (a[j] > a[j + 1]) {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
        while (end > 2) {
            res += min((a[0] * 2 + a[end - 1] + a[end]), (a[0] + a[1] * 2 + a[end]));
            end -= 2;
        }
        if (end == 2) {
            res += (a[0] + a[1] + a[2]);
        }
        if (end == 1) {
            res += a[1];
        }
        if (end == 0) {
            res += a[0];
        }
        cout << res << endl;
    }
}