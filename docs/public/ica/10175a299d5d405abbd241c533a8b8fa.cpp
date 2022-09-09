#include <cmath>
#include <iostream>
using namespace std;

double p(int n, double x) {
    if (n == 0)
        return 1;
    else if (n == 1)
        return x;
    else
        return ((2 * n - 1) * p(n - 1, x) - (n - 1) * p(n - 2, x)) / n;
}

int main() {
    int n;
    double x;
    cin >> n >> x;
    cout << round(p(n, x)) << endl;
}