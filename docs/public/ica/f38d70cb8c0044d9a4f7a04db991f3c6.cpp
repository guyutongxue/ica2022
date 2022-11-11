#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    static long long stack[500]{};
    int len = 0;
    bool isNaN = false;

    char word[15]{};
    while (cin >> word) {
        long long* b = &stack[len - 1];
        long long* a = &stack[len - 2];

        switch (word[0]) {
            case '@': 
                if (isNaN) {
                    cout << "NaN" << endl;
                } else {
                    cout << stack[len - 1] << endl;
                }
                len = 0;
                isNaN = false;
                break;
            case '+':
                len--;
                stack[len - 1] = *a + *b;
                break;
            case '-':
                len--;
                stack[len - 1] = *a - *b;
                break;
            case '*':
                len--;
                stack[len - 1] = *a * *b;
                break;
            case '/':
                len--;
                if (*b == 0) {
                    isNaN = true;
                } else {
                    stack[len - 1] = *a / *b;
                }
                break;
            default:
                stack[len++] = atoll(word);
                break;
        }
    }
}