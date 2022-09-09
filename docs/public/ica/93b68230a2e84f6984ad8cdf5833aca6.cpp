#include <cstring>
#include <iostream>
using namespace std;

char a[21] = {};
char b[21] = {};
int la, lb;
bool check(int aPos, int bPos) {
    if (aPos > la && bPos > lb) return true;
    if (aPos > la || bPos > lb) return false;
    if (a[aPos] == '*') {
        for (int i = bPos; i <= lb; i++) {
            if (check(aPos + 1, i)) {
                return true;
            }
        }
        return false;
    } else if (a[aPos] == '?' || a[aPos] == b[bPos]) {
        return check(aPos + 1, bPos + 1);
    } else {
        return false;
    }
}
int main() {
    cin >> a >> b;
    la = strlen(a);
    lb = strlen(b);
    if (check(0, 0))
        cout << "matched";
    else
        cout << "not matched";
}