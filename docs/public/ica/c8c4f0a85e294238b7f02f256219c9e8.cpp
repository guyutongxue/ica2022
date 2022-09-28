#include <iostream>
using namespace std;

int main() {
    bool a[1002]{};
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (j % i == 0) {
                a[j] ^= true;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}