#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int p[10000];
    int m;
    cin >> m;
    int prime_num = 0;
    for (int i = 2; i <= m; i++) {
        bool isPrime = true;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            p[prime_num++] = i;
        }
    }
    for (int i = 1; i < prime_num; i++) {
        for (int j = i; j < prime_num; j++) {
            if (m == (p[i] + p[j])) cout << p[i] << " " << p[j] << endl;
        }
    }
}