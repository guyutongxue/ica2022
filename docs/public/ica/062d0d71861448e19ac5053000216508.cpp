#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[102] = {};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for (int i = 0, j = 0; j < n - i; j++) {
        if (a[i] != a[i + j]) {
            cout << a[i] << ":" << j << endl;
            i += j;
            j = 0;
        }
        if (i + j == n - 1) {
            cout << a[i] << ":" << j + 1 << endl;
        }
    }
}