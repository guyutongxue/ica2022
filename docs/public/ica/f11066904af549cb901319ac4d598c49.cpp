#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int bad, good;
        cin >> bad >> good;
        int hours = 0;
        while (bad > 0) {
            bad -= good;
            bad *= 2;
            good *= 1.05;
            if (bad > 1'000'000) {
                bad = 1'000'000;
            }
            hours++;
        }
        cout << hours << endl;
    }
}