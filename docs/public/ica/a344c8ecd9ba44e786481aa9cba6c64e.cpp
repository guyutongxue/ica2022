#include <iostream>
using namespace std;

int main() {
    int delta[1010]{};
    int number = 0;
    while (true) {
        int x;
        cin >> x;
        delta[x]++;
        number++;
        if (cin.get() == '\n') break;
    }
    cout << number << ' ';
    while (true) {
        int x;
        cin >> x;
        delta[x]--;
        if (cin.get() == '\n') break;
    }
    int total = 0, answer = 0;
    for (int i = 0; i < 1000; i++) {
        total += delta[i];
        if (total > answer) {
            answer = total;
        }
    }
    cout << answer << endl;
}