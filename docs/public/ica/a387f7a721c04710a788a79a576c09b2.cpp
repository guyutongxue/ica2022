#include <cstring>
#include <iostream>
using namespace std;

int main() {
    int k;
    cin >> k;
    cin.ignore();
    while (k--) {
        char str[1001];
        cin.getline(str, 1001);
        char c = str[0];
        int sum = 0;
        int len = strlen(str);
        for (int i = 0; i < len; i++) {
            if (str[i] == c) {
                sum++;
            } else {
                cout << sum << c;
                sum = 1;
                c = str[i];
            }
        }
        cout << sum << c << endl;
    }
}