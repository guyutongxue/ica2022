#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            for (int k = 0; k < 7; k++) {
                if (i * 49 + j * 7 + k == k * 81 + j * 9 + i) {
                    if (n == 1) {
                        cout << i * 49 + j * 7 + k << endl;
                    }
                    if (n == 2) {
                        cout << i * 100 + j * 10 + k << endl;
                    }
                    if (n == 3) {
                        cout << k * 100 + j * 10 + i << endl;
                    }
                }
            }
        }
    }
}