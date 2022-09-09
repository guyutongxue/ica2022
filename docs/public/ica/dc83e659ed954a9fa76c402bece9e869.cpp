#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int history, distance;
    cin >> history >> distance;
    int cost;
    if (distance <= 6) {
        cost = 3;
    } else if (distance <= 12) {
        cost = 4;
    } else if (distance <= 32) {
        cost = 4 + ceil((distance - 12) / 10.0);
    } else {
        cost = 6 + ceil((distance - 32) / 20.0);
    }

    cout << fixed;
    cout.precision(2);
    if (history < 100 || history >= 400) {
        cout << 1.0 * cost << endl;
    } else if (history < 150) {
        cout << 0.8 * cost << endl;
    } else {
        cout << 0.5 * cost << endl;
    }
}