#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[100002] = {};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int b[102] = {};
    for (int i = 0; i < n; i++) {
        b[a[i]]++;
    }
    for (int i = 1; i <= 100; i++) {
        if (b[i] % 2 != 0) cout << i << endl;
    }
}
