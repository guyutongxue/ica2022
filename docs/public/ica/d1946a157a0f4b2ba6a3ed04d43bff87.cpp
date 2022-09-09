#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        int k;
        cin >> k;
        int a[82] = {};
        for (int j = 0; j < k; j++) {
            cin >> a[j];
        }

        bool isFirst{true};
        if (a[0] != a[1]) {
            if (isFirst) {
                isFirst = false;
            } else {
                cout << " ";
            }
            cout << 0;
        }
        for (int j = 1; j < k - 1; j++) {
            if ((a[j] - a[j - 1]) * (a[j + 1] - a[j]) < 0) {
                if (isFirst) {
                    isFirst = false;
                } else {
                    cout << " ";
                }
                cout << j;
            }
        }
        if (a[k - 1] != a[k - 2]) {
            if (isFirst) {
                isFirst = false;
            } else {
                cout << " ";
            }
            cout << k - 1;
        }
        cout << endl;
    }
}