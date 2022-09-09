#include <iostream>
using namespace std;

int main() {
    int a[5][5] = {};
    int b[5][5] = {};
    bool flag = false;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> a[i][j];
        }
    }
    // 求最大最小值并记录
    for (int i = 0; i < 5; i++) {
        int max = 0, min = 1000000;
        int maxPos = 0, minPos = 0;
        b[i][maxPos]++;
        b[minPos][i]++;
        for (int j = 0; j < 5; j++) {
            if (a[i][j] > max) {
                b[i][maxPos]--;
                max = a[i][j];
                maxPos = j;
                b[i][j]++;
            }
            if (a[j][i] < min) {
                b[minPos][i]--;
                min = a[j][i];
                minPos = j;
                b[j][i]++;
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (b[i][j] > 1) {
                cout << i + 1 << ' ' << j + 1 << ' ' << a[i][j] << endl;
                flag = true;
            }
        }
    }
    if (!flag) cout << "not found";
}