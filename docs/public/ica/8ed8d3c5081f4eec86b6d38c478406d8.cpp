#include <iostream>
using namespace std;

int main() {
    int n, a[102]{};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int min = a[0];
    int minIdx = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
            minIdx = i;
        }
    }
    cout << minIdx + 1 << endl;
}