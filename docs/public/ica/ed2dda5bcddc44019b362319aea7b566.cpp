#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[3100]{};
    int b[3100]{};
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    b[1] = a[1];
    for (int i = 2; i <= n; i++) {
        int m = a[i];
        for (int j = 1; j <= i / 2; j++) {
            if (m < b[j] + b[i - j]) {
                m = b[j] + b[i - j];
            }
        }
        b[i] = m;
    }
    cout << b[n];
}
