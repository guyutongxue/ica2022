#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a = n / 100;
    int b = (n / 10) % 10;
    int c = n % 10;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    return 0;
}