#include <iostream>
using namespace std;

int main() {
    int n;
    int a_wins = 0, b_wins = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a - b == 1 || a - b == -2) {
            b_wins++;
        } else if (a - b == -1 || a - b == 2) {
            a_wins++;
        }
    }
    if (a_wins > b_wins) {
        cout << "A" << endl;
    } else if (a_wins < b_wins) {
        cout << "B" << endl;
    } else {
        cout << "Tie" << endl;
    }
}