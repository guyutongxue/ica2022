#include <iostream>
using namespace std;
int main() {
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            for (int k = 0; k <= 2; k++) {
                if (i != j && i != k && j != k) {
                    int a = (j > i) + (k == i);
                    int b = (i > j) + (i > k);
                    int c = (k > j) + (j > i) ;
                    if (a + i == 2 && b + j == 2 && c + k == 2) {
                        for (int m = 2; m >= 0; m--) {
                            if (m == a) {
                                cout << 'A';
                            } else if (m == b) {
                                cout << 'B';
                            } else if (m == c) {
                                cout << 'C';
                            }
                        }
                    }
                }
            }
        }
    }
}