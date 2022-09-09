#include <cstring>
#include <iostream>
using namespace std;

int n;
char c[510];
bool comp(int a, int b) {
    for (int i = 0; i < n; i++) {
        if (c[i + a] != c[i + b]) {
            return false;
        }
    }
    return true;
}

int main() {
    int a[510] = {};
    cin >> n;
    cin >> c;
    int len = strlen(c);

    for (int i = 0; i <= len - n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (comp(i, j)) {
                a[j]++;
            }
        }
    }
    int maxi = 0;
    for (int i = 0; i <= len - n; i++) {
        if (maxi < a[i]) {
            maxi = a[i];
        }
    }
    if (maxi == 0) {
        cout << "NO" << endl;
    } else {
        cout << maxi + 1 << endl;
        for (int i = 0; i <= len - n; i++) {
            if (a[i] == maxi) {
                char tmp[6];
                for (int j = 0; j < n; j++) {
                    tmp[j] = c[i + j];
                }
                tmp[n] = '\0';
                cout << tmp << endl;
            }
        }
    }
}