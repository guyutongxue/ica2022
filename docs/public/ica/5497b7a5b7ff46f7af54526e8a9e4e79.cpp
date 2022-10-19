#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n, a[10]{};
    char s[20]{};
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t = 0;
        cin >> s;
        int len = strlen(s);
        for (int j = 0; j < len; j++) {
            if (s[j] != '-') {
                if (s[j] == 'A' || s[j] == 'B' || s[j] == 'C') a[++t] = 2;
                if (s[j] == 'D' || s[j] == 'E' || s[j] == 'F') a[++t] = 3;
                if (s[j] == 'G' || s[j] == 'H' || s[j] == 'I') a[++t] = 4;
                if (s[j] == 'J' || s[j] == 'K' || s[j] == 'L') a[++t] = 5;
                if (s[j] == 'M' || s[j] == 'N' || s[j] == 'O') a[++t] = 6;
                if (s[j] == 'P' || s[j] == 'R' || s[j] == 'S') a[++t] = 7;
                if (s[j] == 'T' || s[j] == 'U' || s[j] == 'V') a[++t] = 8;
                if (s[j] == 'W' || s[j] == 'X' || s[j] == 'Y') a[++t] = 9;
                if ('0' <= s[j] && s[j] <= '9') a[++t] = s[j] - '0';
            }
        }
        for (int j = 1; j <= 7; j++) {
            if (j == 3)
                cout << a[j] << '-';
            else
                cout << a[j];
        }
        cout << endl;
    }
}