#include <iostream>
using namespace std;

int sum[100001] = {};
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        sum[i] = 1;
        for (int x = 2; x * x <= i; x++) {
            if (i % x == 0) {
                sum[i] += x;
                if (x * x != i) {
                    sum[i] += i / x;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (sum[i] <= n && sum[i] > i && sum[sum[i]] == i) {
            cout << i << " " << sum[i] << endl;
        }
    }
}