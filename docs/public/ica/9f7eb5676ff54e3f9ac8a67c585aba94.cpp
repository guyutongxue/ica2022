#include <iostream>
using namespace std;

bool isComposite[12346]{};

void initPrime() {
    isComposite[1] = true;
    for (int i = 2; i < 12345; i++) {
        if (!isComposite[i]) {
            for (int j = 2 * i; j < 12345; j += i) {
                isComposite[j] = true;
            }
        }
    }
}

bool binaryPrime(int x) {
    int cnt = 0;
    for (int i = 0; i < 31; i++) {
        if (x & (1 << i)) {
            cnt++;
        }
    }
    return !isComposite[cnt];
}

int main() {
    initPrime();

    int n;
    while (cin >> n) {
        int cnt = 0;
        for (int i = 2; i <= n; i++) {
            if (!isComposite[i] && binaryPrime(i)) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}