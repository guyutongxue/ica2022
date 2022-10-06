#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char str[102] = {};
    cin >> str;
    int len = strlen(str);
    bool isPalindrome = true;
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            isPalindrome = false;
            break;
        }
    }
    cout << (isPalindrome ? "yes" : "no") << endl;
}
