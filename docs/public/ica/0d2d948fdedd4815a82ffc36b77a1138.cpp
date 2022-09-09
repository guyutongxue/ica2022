#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int result = b;
    while (b >= a) {
        result += b / a;
        b = b / a + b % a;
    }
    cout << result << endl;
}