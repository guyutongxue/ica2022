#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int s[101] = {};
    for (int i = 1; i <= n; i++) {
        s[i] = i;
    }
    for (int i = 0; i < m; i++) {
        char op;
        int a, b;
        cin >> op >> a >> b;
        if (op == 'M') {
            int new_set = s[b];
            for (int j = 1; j <= n; j++) {
                if (s[j] == new_set) s[j] = s[a];
            }
        } else {
            if (s[a] == s[b])
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
}