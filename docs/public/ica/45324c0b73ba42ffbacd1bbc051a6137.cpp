#include <iostream>
using namespace std;

int n;
char from[11][11], to[11][11];

bool T1() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (from[i][j] != to[j][n - 1 - i]) return false;
        }
    }
    return true;
}
bool T2() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (from[i][j] != to[n - 1 - j][i]) return false;
        }
    }
    return true;
}
bool T3() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (from[i][j] != to[n - 1 - i][n - 1 - j]) return false;
        }
    }
    return true;
}
bool T4() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (from[i][j] != to[i][j]) return false;
        }
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> from[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> to[i][j];
        }
    }
    if (T1())
        cout << 1 << endl;
    else if (T2())
        cout << 2 << endl;
    else if (T3())
        cout << 3 << endl;
    else if (T4())
        cout << 4 << endl;
    else
        cout << 5 << endl;
}