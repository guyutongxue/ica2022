#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double sum = 0;
    double a[10015] = {};
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    double ave = sum / n;
    double mean = 0;
    for (int i = 0; i < n; i++) {
        mean += (a[i] - ave) * (a[i] - ave);
    }
    mean /= n;
    cout << fixed << setprecision(5) << ave << " " << mean << endl;
}