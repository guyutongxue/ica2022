#include <iostream>
using namespace std;

char words[110][100] = {};
char t[1010] = {};
int n, m;
bool check(int start) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        int pos = 0;
        while (words[i][pos] == t[start + pos] && t[start + pos] != '\0') {
            pos++;
        }
        if (t[start + pos] == '\0' && words[i][pos] == '\0') return true;
        if (words[i][pos] == '\0') return check(start + pos);
    }
    return false;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> t;
        if (check(0))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
}