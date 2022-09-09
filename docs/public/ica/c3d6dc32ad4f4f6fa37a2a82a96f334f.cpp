
#include <iostream>
using namespace std;

int n;
int m[9][9]{};
int trans[9]{};

int search(int k) {
    if (k == 0) {
        int max = -1;
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += m[i][(j + trans[i]) % n];
            }
            if (sum > max) {
                max = sum;
            }
        }
        return max;
    }
    int min = 9999999;
    for (int i = 0; i < n; i++) {
        trans[k - 1] = i;
        int result = search(k - 1);
        if (result < min) {
            min = result;
        }
    }
    return min;
}

int main() {
    while (cin >> n, n != -1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        cout << search(n) << endl;
    }
}