#include <iostream>
using namespace std;
int main() {
    char str[102][102]{};
    int i = 0;
    while (cin >> str[i]) {
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        cout << str[j] << " \n"[!j];
    }
}