#include <iostream>
using namespace std;

enum Status { HEALTHY, ILL, IMMUNE, WILL_ILL, WILL_HEALTHY };

int main() {
    long long n, m;
    cin >> n >> m;
    static Status situation[100001] = {};
    static int friends[100001][1001] = {};
    static int friends_len[100001] = {};
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        friends[x - 1][friends_len[x - 1]++] = y;
        friends[y - 1][friends_len[y - 1]++] = x;
    }
    int max = 0;
    for (int i = 0; i < m; i++) {
        if (max < friends_len[i]) max = friends_len[i];
    }
    int a;
    cin >> a;
    situation[a - 1] = ILL;
    long long date = 0;
    long long illnumber = 1;
    while (true) {
        for (int i = 0; i < n; i++) {
            if (situation[i] == ILL) {
                for (int j = 0; j < max; j++) {
                    if (friends[i][j] != 0 && situation[friends[i][j] - 1] == HEALTHY) {
                        situation[friends[i][j] - 1] = WILL_ILL;
                        illnumber++;
                    }
                }
                situation[i] = IMMUNE;
                illnumber--;
            } else if (situation[i] == IMMUNE) {
                situation[i] = WILL_HEALTHY;
            }
        }
        date++;
        for (int k = 0; k < n; k++) {
            if (situation[k] == WILL_ILL) {
                situation[k] = ILL;
            }
            if (situation[k] == WILL_HEALTHY) {
                situation[k] = HEALTHY;
            }
        }
        if (illnumber == 0) {
            cout << date << endl;
            break;
        }
        if (date >= 2000000000) {
            cout << -1 << endl;
            break;
        }
    }
}