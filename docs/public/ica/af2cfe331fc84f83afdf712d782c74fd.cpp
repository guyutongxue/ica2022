#include <iostream>
using namespace std;

int num[17] = {};

bool judge(int i, int prod) {
    if (i == 1)
        return prod == num[1];
    else if (prod == 0)
        return true;
    else if (prod % num[i] == 0)
        return judge(i - 1, prod / num[i]) || judge(i - 1, prod);
    else
        return judge(i - 1, prod);
}
int main() {
    int t, n;
    cin >> t >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    if (judge(n, t))
        cout << "YES";
    else
        cout << "NO";
}
