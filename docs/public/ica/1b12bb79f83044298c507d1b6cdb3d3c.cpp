#include <iostream>
using namespace std;

bool prime(int a) {
    if (a == 1) return false;
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

void f(int n) {
    if (prime(n)){
        cout << n;
        return;
    }
    for (int i = 2; i <= n; i++) {
        if (!prime(i)) continue;
        if (n % i == 0) {
            cout << i << '*';
            return f(n / i);
        }
    }
}

int main() {
    int n;
    cin >> n;
    cout << n << '=';
    f(n);
}