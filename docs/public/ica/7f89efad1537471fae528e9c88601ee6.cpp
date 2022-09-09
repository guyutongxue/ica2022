#include <iostream>
using namespace std;

int main() {
    int h, w;
    char fill;
    bool isFilled;
    while (cin >> h >> w >> fill >> isFilled, h != 0) {
        if (isFilled) {
            for (int i{0}; i < h; i++) {
                for (int j{0}; j < w; j++) {
                    cout << fill;
                }
                cout << endl;
            }
        } else {
            for (int i{0}; i < w; i++) {
                cout << fill;
            }
            cout << endl;
            for (int i{0}; i < h - 2; i++) {
                cout << fill;
                for (int j{0}; j < w - 2; j++) {
                    cout << ' ';
                }
                cout << fill << endl;
            }
            for (int i{0}; i < w; i++) {
                cout << fill;
            }
            cout << endl;
        }
    }
}