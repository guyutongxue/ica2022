#include <iostream>
using namespace std;

struct Pillar {
    int h;
    int no;
};
Pillar p[20002];

int solve(int l, int r) {
    if (l == r) return p[l].h;
    if (l > r) return 0;
    Pillar minimal = p[l];

    for (int i = l + 1; i <= r; i++) {
        if (p[i].h < minimal.h) {
            minimal = p[i];
        }
    }
    int useMiddle = minimal.h * (r - l + 1);
    int useLeft = solve(l, minimal.no - 1);
    int useRight = solve(minimal.no + 1, r);

    if (useMiddle > useLeft && useMiddle > useRight) {
        return useMiddle;
    } else if (useLeft > useRight) {
        return useLeft;
    } else {
        return useRight;
    }
}
int main() {
    int n;
    cin >> n;
    for (int i{1}; i <= n; i++) {
        cin >> p[i].h;
        p[i].no = i;
    }
    cout << solve(1, n) << endl;
}