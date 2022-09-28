#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        bool bad[180]{};
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int tick;
            cin >> tick;
            bad[3 * j + tick] = true;
            bad[3 * j + tick + 1] = true;
            bad[3 * j + tick + 2] = true;
        }
        int goodCnt = 0;
        for (int j = 0; j < 60; j++) {
            if (!bad[j]) goodCnt++;
        }
        cout << goodCnt << endl;
    }
}