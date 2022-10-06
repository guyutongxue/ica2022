#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    bool isFirst = true;
    int x1, y1, x2 = 0, y2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            if (a == 0 && isFirst) {
                x1 = i;
                y1 = j;
                isFirst = false;
            }
            if (a == 0) {
                if (i >= x2 && j >= y2) {
                    x2 = i;
                    y2 = j;
                }
            }
        }
    }
    cout << (x2 - x1 - 1) * (y2 - y1 - 1) << endl;
}