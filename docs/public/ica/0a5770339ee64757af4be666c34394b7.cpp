#include <iostream>
using namespace std;
int a[2] = {}, b[2] = {}, c[2] = {}, d = 0;
bool check1() {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 1; l < 5; l++) {
                    // 有一种语言三人都会
                    if ((a[i] == l) + (b[j] == l) + (c[k] == l) + (d == l) == 3) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
bool check2() {
    return d != 4 && b[1] != 2 && b[0] != 2;
}
bool check3() {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (c[j] == d || a[i] == c[j]) {
                return false;
            }
        }
    }
    return !(b[1] != c[0] && b[0] != c[0] && b[1] != c[1] && b[0] != c[1]);
}
bool check4() {
    return a[1] * a[0] != 12 && b[1] * b[0] != 12 && c[1] * c[0] != 12;
}
int main() {
    a[1] = 4;
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 5; j++) {
            for (int k = j + 1; k < 5; k++) {
                for (int l = 1; l < 5; l++) {
                    for (int m = l + 1; m < 5; m++) {
                        for (int n = 1; n < 5; n++) {
                            a[0] = i;
                            b[0] = j;
                            b[1] = k;
                            c[0] = l;
                            c[1] = m;
                            d = n;
                            if (l != m && check1() && check2() && check3() && check4()) {
                                cout << a[0] << ' ' << a[1] << endl
                                     << b[0] << ' ' << b[1] << endl
                                     << c[0] << ' ' << c[1] << endl
                                     << d << endl;
                            }
                        }
                    }
                }
            }
        }
    }
}