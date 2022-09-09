#include <iostream>
using namespace std;

bool is_coprime(int a, int b) {
    int temp;
    if (a == 0) return false;
    while (a != 0) {
        temp = a;
        a = b % a;
        b = temp;
    }
    if (temp == 1) return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    int num[202];
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < n; i++) {
        int k = i;
        for (int j = n - 1; j > i; j--) {
            if (num[j] < num[k]) k = j;
        }
        int temp = num[i];
        num[i] = num[k];
        num[k] = temp;
    }
    bool flag = false;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (is_coprime(num[i], num[j])) {
                if (!flag) {
                    cout << num[i] << '/' << num[j];
                    flag = true;
                } else
                    cout << ',' << num[i] << '/' << num[j];
            }
        }
    }
    if (!flag) cout << "NO" << endl;
}