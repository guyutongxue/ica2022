#include <iostream>
using namespace std;

int main() {
    int digitSum[10001] = {};
    int m = 0, n = 0, k = 0;
    char c1, c2;
    cin >> m >> c1 >> n >> c2 >> k;

    for (int i = m + 1; i < n; i++) {
        int tmp = i;
        while (tmp > 0) {
            digitSum[i] += tmp % 10;
            tmp /= 10;
        }
    }

    int result[37][10001] = {};
    int resultLen[37] = {};
    for (int i = m + 1; i < n; i++) {
        int sum = digitSum[i];
        result[sum][resultLen[sum]++] = i;
    }

    for (int i = 1; i * k <= 36; i++) {
        if (resultLen[i * k] != 0) {
            cout << result[i * k][resultLen[0]];
            for (int j = 1; j < resultLen[i * k]; j++) {
                cout << "," << result[i * k][j];
            }
            cout << endl;
        }
    }
}