#include <iostream>
using namespace std;

int main() {
    bool mark[200] = {};
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        mark[a] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (!mark[i]) {
            cout << i << endl;
        }
    }
}