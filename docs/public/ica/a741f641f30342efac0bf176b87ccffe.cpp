#include <iostream>
using namespace std;

int main() {
    int upper{0}, lower{0}, number{0};
    while (true) {
        char c;
        cin >> c;
        if (cin.fail()) {
            cout << upper << ' ' << lower << ' ' << number << endl;
            break;
        }
        if (c >= 'a' && c <= 'z') {
            lower++;
        } else if (c >= 'A' && c <= 'Z') {
            upper++;
        } else if (c >= '0' && c <= '9') {
            number++;
        }
    }
}