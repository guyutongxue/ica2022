#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int total;
        cin >> total;
        int a = total / 25;
        total %= 25;
        int b = total / 10;
        total %= 10;
        int c = total / 5;
        total %= 5;
        cout << i << " " << a << " QUARTER(S)," << b << " DIME(S)," << c << " NICKEL(S)," << total
             << " PENNY(S)" << endl;
    }
}