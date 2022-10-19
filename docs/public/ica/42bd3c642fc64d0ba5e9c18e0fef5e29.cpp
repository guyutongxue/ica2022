#include <iostream>
using namespace std;

int main() {
    int x;
    while (cin >> x) {
        for (int i = 31; i >= 0; i--) {
            cout << ((x >> i) & 1);
        }
        cout << endl;
    }
}