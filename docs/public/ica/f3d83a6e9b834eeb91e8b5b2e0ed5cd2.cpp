#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char c[10];
    cin >> c;
    int len = strlen(c);
    bool isPalindrome = true;
    for (int i = 0; i < len / 2; i++) {
        if (c[i] != c[len - i - 1]) {
            isPalindrome = false;
            break;
        }
    }
    if (isPalindrome) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}