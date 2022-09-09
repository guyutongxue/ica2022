#include <iostream>
using namespace std;

int m, n;
int h[205][205] = {};
bool drown[205][205] = {};

void dfs(int x, int y) {
    if (x - 1 >= 1 && h[x][y] >= h[x - 1][y] && !drown[x - 1][y]) {
        drown[x - 1][y] = true;
        h[x - 1][y] = h[x][y];
        dfs(x - 1, y);
    }
    if (x + 1 <= n && h[x][y] >= h[x + 1][y] && !drown[x + 1][y]) {
        drown[x + 1][y] = true;
        h[x + 1][y] = h[x][y];
        dfs(x + 1, y);
    }
    if (y - 1 >= 1 && h[x][y] >= h[x][y - 1] && !drown[x][y - 1]) {
        drown[x][y - 1] = true;
        h[x][y - 1] = h[x][y];
        dfs(x, y - 1);
    }
    if (y + 1 <= m && h[x][y] >= h[x][y + 1] && !drown[x][y + 1]) {
        drown[x][y + 1] = true;
        h[x][y + 1] = h[x][y];
        dfs(x, y + 1);
    }
}

int main() {
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> m >> n;
        for (int j = 1; j <= m; j++) {
            for (int l = 1; l <= n; l++) {
                cin >> h[j][l];
            }
        }
        int x, y, p;
        cin >> x >> y >> p;
        bool targetDrown = false;
        for (int j = 0; j < p; j++) {
            int xx, yy;
            cin >> xx >> yy;
            if (!targetDrown) {
                for (int k = 0; k < 205; k++) {
                    for (int l = 0; l < 205; l++) {
                        drown[k][l] = false;
                    }
                }
                drown[xx][yy] = true;
                dfs(xx, yy);
                targetDrown = drown[x][y];
            }
        }
        if (drown[x][y])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
