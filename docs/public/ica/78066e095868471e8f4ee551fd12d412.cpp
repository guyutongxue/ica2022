#include <iostream>
using namespace std;

int n, k;
bool hasLeft(int num, int times) {
    if (times == 0) {
        return num != 0;
    }
    if ((num - k) % n) return false;
    return hasLeft((n - 1) * (num / n), times - 1);
}

int main() {
    cin >> n >> k;
    int i = 0;
    while (!hasLeft(++i, n)) {
    }
    cout << i << endl;
}