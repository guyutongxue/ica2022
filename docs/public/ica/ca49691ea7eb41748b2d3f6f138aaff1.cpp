#include <iostream>
using namespace std;

int main() {
    constexpr double PRICES[] = {28.9, 32.7, 45.6, 78.0, 35.0, 86.2, 27.8, 43.0, 56.0, 65.0};
    int k;
    cin >> k;
    cout << fixed;
    cout.precision(2);
    for (int i = 0; i < k; i++) {
        double sum{0.0};
        for (int j{0}; j < 10; j++) {
            int num;
            cin >> num;
            sum += num * PRICES[j];
        }
        cout << sum << endl;
    }
}
