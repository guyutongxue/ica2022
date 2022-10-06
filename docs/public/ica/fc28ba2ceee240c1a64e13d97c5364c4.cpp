#include <iostream>
using namespace std;

int main() {
    int arr[160]{};
    int arrLen = 0;
    int current = -1; // -1 表示当前没在读取整数
    char c;
    while (cin >> c) {
        if (c >= '0' && c <= '9') {
            if (current == -1) {
                current = 0;
            }
            (current *= 10) += c - '0';
        } else {
            if (current > 0) {
                arr[arrLen++] = current;
                current = -1;
            }
        }
    }
    if (current > 0) {
        arr[arrLen++] = current;
        current = -1;
    }

    for (int i = 0; i < arrLen; i++) {
        for (int j = 0; j < arrLen - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    if (arrLen) {
        for (int i = 0; i < arrLen; i++) {
            cout << "," + !i << arr[i];
        }
    } else {
        cout << 0;
    }
}