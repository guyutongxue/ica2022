#include <iostream>
using namespace std;

int main() {
    int fib[20] = {1, 1};
    for (int i = 2; i < 20; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        int n;
        cin >> n;
        cout << fib[n - 1] << endl;
    }
}