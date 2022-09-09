#include <iostream>
using namespace std;

int main() {
    int n, x;
    int cnt[10] = {};
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        int k = i;
        while (k != 0) {
            cnt[k % 10]++;
            k /= 10;
        }
    }
    cout << cnt[x] << endl;
}