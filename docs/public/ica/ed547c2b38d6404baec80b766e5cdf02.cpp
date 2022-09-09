#include <cstring>
#include <iostream>
using namespace std;

bool illness[102][102] = {};
bool illness_next[102][102] = {};
bool empty[102][102] = {};
void spread(int i, int j) {
    if (!empty[i][j] && !illness[i][j]) {
        illness_next[i][j] = true;
    }
}
void gen(int x, int y) {
    if (illness[x][y]) {
        spread(x + 1, y);
        spread(x - 1, y);
        spread(x, y + 1);
        spread(x, y - 1);
    }
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char str[102];
        cin >> str;
        for (int j = 1; j <= n; j++) {
            if (str[j - 1] == '#')
                empty[i][j] = true;
            else
                empty[i][j] = false;
            if (str[j - 1] == '.') illness[i][j] = false;
            if (str[j - 1] == '@') illness[i][j] = true;
        }
    }
    for (int i = 0; i <= n + 1; i++) {
        empty[0][i] = true;
        empty[i][0] = true;
        empty[n + 1][i] = true;
        empty[i][n + 1] = true;
    }
    int d;
    cin >> d;
    while (--d) {
        memcpy(illness_next, illness, sizeof(illness));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                gen(i, j);
            }
        }
        memcpy(illness, illness_next, sizeof(illness_next));
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (illness[i][j]) cnt++;
        }
    }
    cout << cnt << endl;
}