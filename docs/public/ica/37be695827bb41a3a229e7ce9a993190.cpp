#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    double sum = 1.10 * a + 1.20 * b + 22.50 * c + 8.80 * d;
    if (sum < 600) {
        cout << "UNDER" << endl;
    } else if (sum > 1000) {
        cout << "OVER" << endl;
    } else {
        cout << "FINE" << endl;
    }
}