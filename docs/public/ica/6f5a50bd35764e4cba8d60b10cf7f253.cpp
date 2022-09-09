#include <iostream>
using namespace std;

char str[102] = {};

int firstClose(int pos) {
    if (str[pos] != str[0]) {
        return pos;
    } else {
        int n{firstClose(pos + 1)};
        cout << pos << ' ' << n << endl;
        return firstClose(n + 1);
    }
}

int main() {
    cin >> str;
    firstClose(0);
}