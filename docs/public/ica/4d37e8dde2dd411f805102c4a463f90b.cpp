#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n, n) {
        int a[1002], b[1002];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (a[j + 1] < a[j]) {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (b[j + 1] < b[j]) {
                    int temp = b[j];
                    b[j] = b[j + 1];
                    b[j + 1] = temp;
                }
            }
        }
        int sum = 0;
        int ag = n - 1, bg = n - 1;
        int al = 0, bl = 0;
        while (al <= ag) {
            if (a[ag] > b[bg]) {
                ag--;
                bg--;
                sum++;
            } else if (a[al] > b[bl]) {
                al++;
                bl++;
                sum++;
            } else {
                if (a[al] < b[bg])
                    sum--;
                else if (a[al] > b[bg])
                    sum++;
                al++;
                bg--;
            }
        }
        cout << sum * 200 << endl;
    }
}
