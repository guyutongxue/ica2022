#include <iostream>
using namespace std;

int gcd(int a, int b) {
    int temp = 0;
    while (b) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    for (int i = n / 2; i >= 1; i--) {
        if (gcd(n, i) == 1) {
                cout << i << endl;
            break;
        }
    }
}