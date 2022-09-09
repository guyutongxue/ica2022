#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int a = x / 1000;
        int b = (x / 100) % 10;
        int c = (x / 10) % 10;
        int d = x % 10;
        if ((d - a - b - c) > 0) cnt++;
    }
    cout << cnt << endl;
}