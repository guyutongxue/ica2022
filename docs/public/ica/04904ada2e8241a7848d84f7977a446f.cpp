#include <cstdlib>
#include <iostream>
using namespace std;

double calculate() {
    char str[10];
    std::cin >> str;
    switch (str[0]) {
        case '+': {
            double a = calculate();
            return a + calculate();
        }
        case '-': {
            double a = calculate();
            return a - calculate();
        }
        case '*': {
            double a = calculate();
            return a * calculate();
        }
        case '/': {
            double a = calculate();
            return a / calculate();
        }
        default: return atof(str);
    }
}
int main() {
    cout.setf(ios::fixed);
    cout << calculate() << endl;
}