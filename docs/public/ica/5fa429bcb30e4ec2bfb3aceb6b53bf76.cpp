#include <iostream>
#include <cstring>
using namespace std;

bool a[110][110]{};
int hb, lb;
bool walk(int x, int y) {
    if (x == hb && y == lb) {
        return true;
    } else {
        a[x][y] = 0;
        return a[x - 1][y] && walk(x - 1, y) || a[x + 1][y] && walk(x + 1, y) ||
               a[x][y - 1] && walk(x, y - 1) || a[x][y + 1] && walk(x, y + 1);
    }
}

int main() {
    int k, n;
    cin >> k;
    for (int i = 1; i <= k; i++) {
        memset(a, 0, sizeof(a));

        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                char x;
                cin >> x;
                if (x == '.') a[i][j] = true;
            }
        }
        int ha, la;
        cin >> ha >> la >> hb >> lb;
        ha++, la++, hb++, lb++;
        if (!a[ha][la] || !a[hb][lb]) {
            cout << "NO" << endl;
        } else {
            cout << (walk(ha, la) ? "YES" : "NO") << endl;
        }
    }
}