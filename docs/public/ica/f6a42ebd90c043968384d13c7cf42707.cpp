#include <iostream>
using namespace std;

int main() {
    char comma;
    double x, y;
    cin >> x >> comma >> y;
    if (abs(x) < 1 && abs(y) < 1) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}