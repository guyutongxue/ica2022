#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int m;
    cin >> m;
    int a[26][1000]{};
    int aLen[26]{};
    for (int i = 0; i < m; i++) {
        int id;
        char s[30];
        cin >> id >> s;
        for (int j = 0; s[j]; j++) {
            int no = s[j] - 'A';
            a[no][aLen[no]++] = id;
        }
    }
    int maxLen = 0;
    int maxIdx = 0;
    for (int i = 0; i < 26; i++) {
        if (aLen[i] > maxLen) {
            maxLen = aLen[i];
            maxIdx = i;
        }
    }
    cout << char('A' + maxIdx) << endl << maxLen << endl;
    for (int i = 0; i < maxLen; i++) {
        cout << a[maxIdx][i] << endl;
    }
}