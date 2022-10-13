#include <iostream>
#include <cmath>
using namespace std;

bool prime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int a, b;
    char c;
    cin >> a >> c >> b;
    int max = a > b ? a : b;
    for (int i = 2; i <= max; i++) {
        if (!prime(i)) continue;
        if ((a % i == 0) ^ (b % i == 0)) {
            cout << "NO" << endl;
            exit(0);
        }
    }
    cout << "YES" << endl;
}