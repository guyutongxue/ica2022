#include <iostream>
using namespace std;
int main() {
    int a[10], b[10], c[20];
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 10; i++) {
        cin >> b[i];
    }
    int p = 0, q = 0;
    while (p < 10 && q < 10) {
        if (a[p] < b[q]) {
            c[p + q] = a[p];
            p++;
        } else {
            c[p + q] = b[q];
            q++;
        }
    }
    while (p < 10) {
        c[p + q] = a[p];
        p++;
    }
    while (q < 10) {
        c[p + q] = b[q];
        q++;
    }
    cout << c[0];
    for (int i = 1; i < 20; i++) {
        cout << " " << c[i];
    }
}