#include <iostream>
using namespace std;

int main() {
    int a[105][105] = {};
    int s = 0, c = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] <= 50) {
                s++;
                if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
                    c++;
                else if (a[i + 1][j] > 50 || a[i - 1][j] > 50 || a[i][j + 1] > 50 ||
                         a[i][j - 1] > 50)
                    c++;
            }
        }
    }
    cout << s << " " << c << endl;
}