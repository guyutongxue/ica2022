#include <iostream>
using namespace std;

void moveDisk(int n, char src, char dest, char trans) {
    if (n == 1) {
        cout << src << "->" << dest << endl;
        return;
    }
    moveDisk(n - 1, src, trans, dest);
    cout << src << "->" << dest << endl;
    moveDisk(n - 1, trans, dest, src);
}
int main() {
    int n;
    cin >> n;
    moveDisk(n, 'A', 'C', 'B');
}