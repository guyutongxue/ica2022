#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n, n) {
        int last = -1, current = 1, answer = 1;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == last) {
                current++;
            } else {
                last = x;
                current = 1;
            }
            if (current > answer) {
                answer = current;
            }
        }
        cout << answer << endl;
    }
}