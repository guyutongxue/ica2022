#include <iostream>
using namespace std;

int main() {
    double x, m;
    cin >> x >> m;
    double saved = x;
    int y = 1;
    while (y <= 100) {
        if (saved >= m) {
            cout << y << endl;
            exit(0);
        }
        saved += x *= 1.08;
        m *= 1.10;
        y++;
    }
    cout << "Forget it." << endl;
}