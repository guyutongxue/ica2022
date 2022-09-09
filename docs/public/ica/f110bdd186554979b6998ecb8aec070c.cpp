#include <cstring>
#include <iostream>
using namespace std;

int main() {
    char str[102];
    cin.getline(str, 102);
    bool is = true;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] != str[len - i - 1]) {
            is = false;
            break;
        }
    }
    if (is)
        cout << "1" << endl;
    else
        cout << "0" << endl;
}