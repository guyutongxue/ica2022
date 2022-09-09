#include <cmath>
#include <iostream>
using namespace std;

int main() {
    const double PI = 3.14159;
    int h, r;
    double v;
    cin >> h >> r;
    v = PI * h * r * r / 1000;
    cout << int(ceil(20 / v)) << endl;
}