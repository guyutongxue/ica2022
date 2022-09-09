#include <iostream>
using namespace std;

int main() {
    int m, n, r, s;
    int a[101][101];
    int b[101][101];

    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    cin >> r >> s;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= s; j++) {
            cin >> b[i][j];
        }
    }

    int min = 2100000000;
    int tx = 1, ty = 1;
    int counter = 0;
    for (int i = 1; i <= m - r + 1; i++) {
        for (int j = 1; j <= n - s + 1; j++) {
            counter = 0;
            for (int p = 1; p <= r; p++) {
                for (int q = 1; q <= s; q++) {
                    counter += abs(b[p][q] - a[p + i - 1][q + j - 1]);
                }
            }
            if (counter < min) {
                min = counter;
                tx = i;
                ty = j;
            }
        }
    }

    for (int p = 1; p <= r; p++) {
        for (int q = 1; q <= s; q++) {
            cout << a[tx + p - 1][ty + q - 1] << ' ';
        }
        cout << endl;
    }
}