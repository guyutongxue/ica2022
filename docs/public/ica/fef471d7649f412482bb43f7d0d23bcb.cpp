#include <iostream>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    bool a[1002];
    int now = 1;
    for (int i = 1; i <= n; i++) {
        a[i] = true;
    }
    while (k != 0) {
        int x = 0;
        int i = now - 1;
        while (x < m) {
            i++;
            if (i > n) i = 1;
            if (a[i]) {
                x++;
            }
        }
        a[i] = false;
        now = i;
        k--;
    }
    cout << now;
}