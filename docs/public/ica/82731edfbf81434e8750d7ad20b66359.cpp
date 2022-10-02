#include <iostream>
using namespace std;
int main() {
    int m, n, k;
    char c1, c2;
    cin >> m >> c1 >> n >> c2 >> k;
    for (int target = k; target <= 36; target += k) {
        bool isFirst = true;
        for (int i = m + 1; i < n; i++) {
            int temp = i;
            int sum = 0;
            while (temp != 0) {
                sum += temp % 10;
                temp /= 10;
            }
            if (sum == target) {
                if (isFirst) {
                    cout << i;
                    isFirst = false;
                } else {
                    cout << ',' << i;
                }
            }
        }
        if (!isFirst) {
            cout << endl;
        }
    }
}
