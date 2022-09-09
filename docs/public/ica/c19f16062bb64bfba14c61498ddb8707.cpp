#include <iostream>
using namespace std;

int main() {
    double a, b;
    double sum = 0.0;
    cin >> a;
    for (int i = 1; i <= a; i++) {
        cin >> b;
        sum += b;
    };
    cout << fixed;
    cout.precision(2);
    cout << sum / a << endl;
}