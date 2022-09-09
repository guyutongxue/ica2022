#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int n, k,  total = 0;
    static int a[1010000], sum[1010000] = {};
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }
    for (int i = 0; i < n - k; i++) {
        sum[0] += a[i];
    }
    for (int i = 1; i < k + 1; i++) {
        sum[i] = sum[i - 1] - a[i - 1] + a[i + n - k - 1];
    }
    int mini = 1000000000;
    for (int i = 0; i < k + 1; i++) {
        if (mini > sum[i]) {
            mini = sum[i];
        }
    }
    cout << total - mini;
}