#include <cstring>
#include <iostream>
using namespace std;

int main() {
    char str[105];
    while (cin.getline(str, 105)) {
        bool is = true;
        int l = 0, r = strlen(str) - 1;
        while (l < r) {
            while (!isupper(str[l]) && !islower(str[l])) {
                l++;
            }
            while (!isupper(str[r]) && !islower(str[r])) {
                r--;
            }
            if (l > r) break;
            if (str[l] != str[r]) {
                is = false;
                break;
            }
            l++;
            r--;
        }
        if (is)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}