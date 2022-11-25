#include <iostream>
#include <cctype>
using namespace std;
 
bool tryParse(const char* str, int* n) {
    int multiplier = 1;
    if (*str == '-') multiplier = -1, str++;
    else if (*str == '+') str++;
    if (*str == '\0') return false;
    int x = 0;
    while (*str) {
        if (isdigit(*str)) {
            x = x * 10 + (*str - '0');
        } else {
            return false;
        }
        str++;
    }
    *n = multiplier * x;
    return true;
}
int main() {
    int n;
    tryParse("42", &n);
    cout << "Hello, " << n << endl;
 
    char str[10]{};
    while (cin >> str) {
        if (tryParse(str, &n)) {
            cout << n + 1 << endl;
        } else {
            cout << "Not an integer" << endl;
        }
    }
}
