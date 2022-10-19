#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (a < b) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int a, b;
    char comma;
    cin >> a >> comma >> b;
    cout << a * b / gcd(a, b) << endl;
}