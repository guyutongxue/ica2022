#include <iostream>
using namespace std;

int w, h;
char ch[21][21];
int ans = 0;
int dx[4]{-1, 0, 1, 0};
int dy[4]{0, -1, 0, 1};

void dfs(int x, int y) {
    ans++;
    ch[y][x] = '#';
    for (int i = 0; i < 4; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx > 0 && tx <= w && ty > 0 && ty <= h && ch[ty][tx] != '#') {
            dfs(tx, ty);
        }
    }
}

int main() {
    while (cin >> w >> h, w) {
        ans = 0;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> ch[i][j];
            }
        }
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                if (ch[i][j] == '@') {
                    dfs(j, i);
                }
            }
        }
        cout << ans << endl;
    }
}
