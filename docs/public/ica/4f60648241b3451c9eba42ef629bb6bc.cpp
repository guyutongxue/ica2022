#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;

int t[10000010] = {};
int transform(char x) {
    if (x <= '9') return x - '0';
    if (x <= 'C') return 2;
    if (x <= 'F') return 3;
    if (x <= 'I') return 4;
    if (x <= 'L') return 5;
    if (x <= 'O') return 6;
    if (x <= 'S') return 7;
    if (x <= 'V') return 8;
    if (x <= 'Y') return 9;
    return 0;
}
int main() {
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 1; i <= n; i++) {
        char str[20];
        cin.getline(str, 20);
        int len = strlen(str);
        int num = 0;
        for (int j = 0; j < len; j++) {
            if (str[j] == '-') continue;
            num = num * 10 + transform(str[j]);
        }
        if (num >= 0) t[num]++;
    }
    bool isEmpty = true;
    for (int i = 0; i <= 9999999; i++) {
        if (t[i] >= 2) {
            isEmpty = false;
            cout.fill('0');
            cout << setw(3) << i / 10000 << "-";
            cout << setw(4) << i % 10000 << " " << t[i] << endl;
        }
    }
    if (isEmpty) {
        cout << "No duplicates." << endl;
    }
}