#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        int a[102]{};
        int b[102]{};
        int aLen{0}, bLen{0};

        // step 1 读入
        char ch;
        while (cin.get(ch) && ch != '\n') {
            a[aLen++] = ch - '0';
        }
        while (cin.get(ch) && ch != '\n') {
            b[bLen++] = ch - '0';
        }

        // step 2 反转（低位在前）
        for (int i = 0; i < aLen / 2; i++) {
            int temp = a[i];
            a[i] = a[aLen - i - 1];
            a[aLen - i - 1] = temp;
        }
        for (int i = 0; i < bLen / 2; i++) {
            int temp = b[i];
            b[i] = b[bLen - i - 1];
            b[bLen - i - 1] = temp;
        }

        // step 3 做加法
        int c[103]{};
        int cLen = aLen > bLen ? aLen : bLen;
        int carry{0};
        for (int i = 0; i < cLen; i++) {
            c[i] = a[i] ^ b[i] ^ carry;
            carry = (a[i] + b[i] + carry) > 1;
        }
        if (carry) {
            c[cLen++] = 1;
        }

        // step 4 输出
        for (int i = cLen - 1; i >= 0; i--) {
            cout << c[i];
        }
        cout << endl;
    }
}