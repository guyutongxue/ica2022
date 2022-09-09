#include <iostream>
using namespace std;

int cross_product(int x0, int y0, int x1, int y1, int x2, int y2) {
    int n = (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
    if (n > 0)
        return 1;
    else if (n == 0)
        return 0;
    else
        return -1;
}

int main() {
    int a[8] = {};
    while (cin >> a[0]) {
        for (int i = 1; i <= 7; i++) {
            cin >> a[i];
        }
        if (cross_product(a[4], a[5], a[0], a[1], a[2], a[3]) *
                    cross_product(a[6], a[7], a[0], a[1], a[2], a[3]) >
                0 &&
            cross_product(a[0], a[1], a[2], a[3], a[4], a[5]) *
                    cross_product(a[6], a[7], a[2], a[3], a[4], a[5]) >
                0 &&
            cross_product(a[0], a[1], a[4], a[5], a[6], a[7]) *
                    cross_product(a[2], a[3], a[4], a[5], a[6], a[7]) >
                0) {
            cout << "yes";
        } else {
            cout << "no";
        }
        cout << endl;
    }
}