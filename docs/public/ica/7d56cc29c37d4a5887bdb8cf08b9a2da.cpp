#include <cstring>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char a[20]{};
        char b[20]{};
        cin >> a >> b;
        int max = 0;
        int aLen = strlen(a);
        int bLen = strlen(b);
        for (int j = 0; j < aLen; j++) {
            for (int k = 0; k < bLen; k++) {
                if (a[j] == b[k]) {
                    int num = 0;
                    while (a[j + num] == b[k + num] && a[j + num]) {
                        num++;
                    }
                    if (num > max) max = num;
                }
            }
        }
        cout << max << endl;
    }
}