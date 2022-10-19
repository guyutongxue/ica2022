#include <iostream>
using namespace std;

int main() {
    int h, u, d;
    cin >> h >> u >> d;
    int day = 0, height = 0;
    while (true) {
        day++;
        height += u;
        if (height >= h) break;
        height -= d;
    }
    cout << day << endl;
}