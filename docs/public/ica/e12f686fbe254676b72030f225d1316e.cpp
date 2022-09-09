#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        double f;
        cin >> f;
        cout << setprecision(4) << fixed << 5.0 * (f - 32) / 9 << endl;
    }
}