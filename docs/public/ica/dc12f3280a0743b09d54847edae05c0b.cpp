#include <iostream>
using namespace std;

int read() {
    int n;
    char str[20]{};
    cin >> n >> str;
    int result = 0;
    for (int i = 0; str[i]; i++) {
        (result *= n) += 
            (str[i] > '9' ? str[i] + 10 - 'a' : str[i] - '0');
    }
    return result;
}

int main() {
    int a = read();
    int b = read();

    int c = a + b;
    int n;
    cin >> n;
    int bits[20]{};
    int bitLen = 0;
    do {
        bits[bitLen++] = c % n;
    } while (c /= n);
    for (int i = bitLen - 1; i >= 0; i--) {
        cout << char(bits[i] > 9
            ? 'a' + bits[i] - 10
            : bits[i] + '0');
    }
}
