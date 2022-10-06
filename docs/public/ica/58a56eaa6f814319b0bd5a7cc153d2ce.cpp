#include <iostream>
using namespace std;

int x[50002]{};
int R = 0, n = 0;

int range(int l) {
    int ret = l;
    while (ret < n && x[ret] - x[l] <= R) ret++;
    return ret;
}

int main() {
    int cnt = 0, l = 0;
    while (cin >> R >> n) {
        if (R < 0 && n < 0) return 0;
        for (int i = 0; i < n; i++) cin >> x[i];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (x[j] > x[j + 1]) {
                    int temp = x[j];
                    x[j] = x[j + 1];
                    x[j + 1] = temp;
                }
            }
        }

        cnt = 0;
        l = 0;
        while (l < n) {
            l = range(range(l) - 1);
            cnt++;
        }
        cout << cnt << endl;
    }
}