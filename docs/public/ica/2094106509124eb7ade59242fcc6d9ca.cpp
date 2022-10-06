#include<iostream>
using namespace std;

int main() {
    for (int a = 1; a <= 5; a++) {
        for (int b = 1; b <= 5; b++) {
            for (int c = 1; c <= 5; c++) {
                for (int d = 1; d <= 5; d++) {
                    for (int e = 1; e <= 5; e++) {
                        if (((b == 2) ^ (a == 3))
                            && ((b == 2) ^ (e == 4))
                            && ((c == 1) ^ (d == 2)) 
                            && ((c == 5) ^ (d == 3)) 
                            && ((e == 4) ^ (a == 1)) 
                            && (a * b * c * d * e == 120)) {
                            cout << a << endl << b << endl << c << endl << d << endl << e << endl;
                        }
                    }
                }
            }
        }
    }
}