#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        double bikeTime = 27 + 23 + d / 3.0;
        double walkTime = d / 1.2;
        if (walkTime < bikeTime) {
            cout << "Walk" << endl;
        } else if (walkTime > bikeTime) {
            cout << "Bike" << endl;
        } else {
            cout << "All" << endl;
        }
    }
}