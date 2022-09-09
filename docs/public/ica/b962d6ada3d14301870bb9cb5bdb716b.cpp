#include <iostream>
using namespace std;

int main() {
    int c, r;
    cin >> r >> c;
    int a[102][102];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }
    int i_cur = 0, j_cur = -1;
    int i_reverse = 1, j_reverse = 1;
    int i_length = r - 1, j_length = c;
    int k = 0;
    while (k < r * c) {
        for (int j = 0; j < j_length; j++) {
            k++;
            j_cur += j_reverse;
            cout << a[i_cur][j_cur] << endl;
        }
        j_reverse *= -1;
        j_length--;
        for (int i = 0; i < i_length; i++) {
            k++;
            i_cur += i_reverse;
            cout << a[i_cur][j_cur] << endl;
        }
        i_reverse *= -1;
        i_length--;
    }
}