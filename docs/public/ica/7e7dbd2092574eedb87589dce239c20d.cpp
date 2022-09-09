#include <iostream>
using namespace std;

int main() {
    int l, m;
    cin >> l >> m;
    bool trees[10002] = {};
    for (int i = 0; i < m; i++) {
        int left, right;
        cin >> left >> right;
        for (int j = left; j <= right; j++) {
            trees[j] = true;
        }
    }
    int count = 0;
    for (int i = 0; i <= l; i++) {
        if (!trees[i]) {
            count++;
        }
    }
    cout << count << endl;
}