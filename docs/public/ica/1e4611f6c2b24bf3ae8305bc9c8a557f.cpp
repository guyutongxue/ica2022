#include <cstring>
#include <iostream>
using namespace std;

void add(const char* a, const char* b, char* dest) {
    int sum = 0;
    int len_dest = 0;
    int len_a = strlen(a), len_b = strlen(b);
    for (int i = 0; i < len_a || i < len_b; i++) {
        if (i < len_a) {
            sum += a[i] - '0';
        }
        if (i < len_b) {
            sum += b[i] - '0';
        }
        dest[len_dest++] = sum % 10 + '0';
        sum /= 10;
    }
    if (sum) {
        dest[len_dest++] = sum + '0';
    }
}

int main() {
    char a[70];
    while (cin >> a) {
        cout << a;
        // reverse a
        int len_a = strlen(a);
        for (int i = 0; i < len_a / 2; i++) {
            char tmp = a[i];
            a[i] = a[len_a - 1 - i];
            a[len_a - 1 - i] = tmp;
        }
        char b[70] = "0", dest[70] = {};
        for (int i = 0; i <= len_a; i++) {
            add(a, b, dest);
            strcpy(b, dest);
        }
        bool isOk = true;
        for (int i = 0; i < len_a; i++) {
            if (b[i] != '9') {
                isOk = false;
                break;
            }
        }
        isOk &= b[len_a] == '\0';
        if (isOk) {
            cout << " is cyclic" << endl;
        } else {
            cout << " is not cyclic" << endl;
        }
    }
}