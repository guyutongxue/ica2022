#include <iostream>
using namespace std;

int max(int a, int b, int c) {
    int m = a;
    if (b > a || c > a) {
        if (b > c) m = b;
        else m = c;
    }
    return m;
}

int min(int a, int b, int c) {
    int m = a;
    if (b < a || c < a) {
        if (b < c) m = b;
        else m = c;
    }
    return m;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << max(a, b, c) - min(a, b, c) << endl;
}
