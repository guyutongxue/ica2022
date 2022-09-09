#include <iostream>
using namespace std;

bool chessboard[9][9] = {};
int result[100][9] = {};
int cnt = 1;
bool isOk(int x, int y) {
    for (int i = 1; i < x; i++) {
        for (int j = 1; j <= 8; j++) {
            if (chessboard[i][j]) {
                if (j == y) return false;
                if (abs(i - x) == abs(j - y)) return false;
            }
        }
    }
    return true;
}
void queen(int k) {
    for (int i = 1; i <= 8; i++) {
        if (isOk(k, i)) {
            result[cnt][k] = i;
            if (k == 8) {
                cnt++;
                for (int j = 1; j <= 8; j++) {
                    result[cnt][j] = result[cnt - 1][j];
                }
                return;
            }
            chessboard[k][i] = true;
            queen(k + 1);
            chessboard[k][i] = false;
        }
    }
}
int main() {
    queen(1);
    int n;
    cin >> n;
    while (n--) {
        int r;
        cin >> r;
        for (int i = 1; i <= 8; i++) {
            cout << result[r][i];
        }
        cout << endl;
    }
}