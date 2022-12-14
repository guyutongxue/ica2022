char* int2str(int val) {
    int size = 0;
    int val2 = val;
    do {
        size++;
    } while (val2 /= 10);
    if (val < 0) {
        size++;
    }
    char* buffer = new char[size + 1]{};
    if (val < 0) {
        buffer[0] = '-';
    }
    do {
        int digit = val % 10;
        if (digit < 0) digit = -digit;
        buffer[--size] = digit + '0';
    } while (val /= 10);
    return buffer;
}
 
#include <iostream>
using namespace std;
int main() {
    int n;
    while (cin >> n) {
        char* str = int2str(n);
        cout << str << endl;
        delete[] str;
    }
}
