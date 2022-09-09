#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    n++;
    bool output{false};
    for (int i{18}; i >= 0; i--) {
        if (output) {
            cout << ((n & (1 << i)) ? 'G' : 'N');
        }
        if (n & (1 << i)) {
            output = true;
        }
    }
    cout << endl;
}