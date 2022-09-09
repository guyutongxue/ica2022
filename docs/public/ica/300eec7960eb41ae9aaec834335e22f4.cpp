#include <iostream>
using namespace std;

int main() {
    // 交换的时候，只有交换0,1是有意义的，交换(1,1),(0,0)都是徒劳。
    // 仅考虑1的位置，交换一次，可以让一个1的位置加1或者-1
    // 最后只需要1的位置对齐即可完成
    int n, src[210], target[210], numberOfOne;
    cin >> n;

    int posOfOne[2][210], p = 0;
    for (int i = 0; i < n; i++) {
        cin >> src[i];
        if (src[i] == 1) {
            posOfOne[0][p] = i;
            p++;
        }
    }
    numberOfOne = p;
    p = 0;
    for (int i = 0; i < n; i++) {
        cin >> target[i];
        if (target[i] == 1) {
            posOfOne[1][p] = i;
            p++;
        }
    }
    if (p != numberOfOne) {
        cout << -1 << endl;
    } else {
        int res = 0;
        for (int i = 0; i < numberOfOne; i++) {
            res += abs(posOfOne[0][i] - posOfOne[1][i]);
        }
        cout << res << endl;
    }
}