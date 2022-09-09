#include <iostream>
using namespace std;

int main() {
    int a[210], b[210], c[210];
    int a_len = 0, b_len = 0, c_len = 0;
    while (true) {
        cin >> a[a_len++];
        if (cin.get() == '\n') break;
    }
    while (true) {
        cin >> b[b_len++];
        if (cin.get() == '\n') break;
    }
    
    for (int i = 0; i < a_len; i++) {
        for (int j = i + 1; j < a_len; j++) 
            if (a[j] == a[i]) a[j] = 0;
    }
    for (int i = 0; i < b_len; i++) {
        for (int j = i + 1; j < b_len; j++)
            if (b[j] == b[i]) b[j] = 0;
    }
    for (int i = 0; i < a_len; i++) {
        for (int j = 0; j < b_len; j++)
            if (a[i] == b[j] && a[i] != 0)
                c[c_len++] = a[i];
    }
    if (c_len == 0) {
        cout << "NULL";
        exit(0);
    }
    for (int i = 0; i < c_len - 1; i++) {
        for (int j = 0; j < c_len - 1; j++) {
            if (c[j] > c[j + 1]) {
                int temp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp;
            }
        }
    }
    cout << c[0];
    for (int i = 1; i < c_len; i++) {
        cout << "," << c[i];
    }
}