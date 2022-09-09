#include <cmath>
#include <iostream>
using namespace std;

int m, n, k;
struct Position {
    int x;
    int y;
    int num;
};
Position a[930];

bool reachable(int to_get, int posx, int posy) {
    return k >= (abs(a[to_get].x - posx) + abs(a[to_get].y - posy) + a[to_get].x + 2);
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> m >> n >> k;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int num;
                cin >> num;
                a[i * n + j] = {i, j, num};
            }
        }

        for (int i = 0; i < m * n - 1; i++) {
            for (int j = 0; j < m * n - 1; j++) {
                if (a[j].num < a[j + 1].num) {
                    Position temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
        int get = 0;
        int to_get = 0;
        int pos_x = -1;
        int pos_y = a[0].y;
        while (reachable(to_get, pos_x, pos_y)) {
            k -= (abs(a[to_get].x - pos_x) + abs(a[to_get].y - pos_y) + 1);
            get += a[to_get].num;
            pos_x = a[to_get].x;
            pos_y = a[to_get].y;
            to_get++;
        }
        cout << get << endl;
    }
}