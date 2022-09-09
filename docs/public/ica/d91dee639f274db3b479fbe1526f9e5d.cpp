#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int time;
    if (k >= n) {
        time = 2;
    } else {
        if ((2 * n) % k == 0)
            time = 2 * n / k;
        else
            time = 2 * n / k + 1;
    }
    cout << time << endl;
}