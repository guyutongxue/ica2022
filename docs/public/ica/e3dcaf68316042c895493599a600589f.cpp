#include <iostream>
using namespace std;

int k;

bool f(int n) {
    if (n < k) return false;
    if (n == k) return true;
    return (n % 2 == 1 && f((n - 1) / 2)) || (n % 3 == 1 && f((n - 1) / 3));
}

int main() {
    int x;
    char comma;
    cin >> k >> comma >> x;
    cout << (f(x) ? "YES" : "NO") << endl;
}