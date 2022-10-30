#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double x{}, y{};
    double dx, dy;
    while (cin >> dx >> dy) {
        x += dx;
        y += dy;
    }
    cout << fixed << setprecision(4) << sqrt(x * x + y * y) << endl;
}