#include <iostream>
using namespace std;

int main() {
    double sum = 0.0;
    for (int i = 0; i < 12; ++i) {
        double w;
        cin >> w;
        sum += w;
    }
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << '$' << sum / 12.0 << endl;
}