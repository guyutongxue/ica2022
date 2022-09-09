#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[200000] = {};

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    bool read[200000] = {};
    int day = 0;
    int last = 0;

    while (true) {
        int p;
        for (p = last + 1; p <= n; p++) {
            if (!read[p]) {
                break;
            }
        }
        if (p > n) break;

        last = p;
        day++;
        while (!read[p]) {
            read[p] = true;
            p = a[p];
        }
    }
    cout << day << endl;
}