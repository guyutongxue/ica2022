#include <cstring>
#include <iostream>
using namespace std;

int decode(char z) {
    if (z <= 'z' && z >= 'a') return z - 'a';
    return z - 'A' + 26;
}

int main() {
    int n, m, x[1010], y[1010];
    char s[1010][110];
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = m; i > 0; i--) {
        int key = x[i], src = y[i];
        int l1 = strlen(s[x[i]]), l2 = strlen(s[src]);
        for (int j = 0; j < l2; j++) {
            int x1 = decode(s[key][j % l1]);
            int x2 = decode(s[src][j]);
            x2 -= x1;
            if (x2 < 0) x2 += 52;
            if (x2 >= 26)
                s[src][j] = 'A' + x2 - 26;
            else
                s[src][j] = 'a' + x2;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << s[i] << endl;
    }
}