#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int old[100] = {};
    for (int i = 0; i < n; i++) {
        cin >> old[i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j < n - i; j++) {
            if (old[j - 1] > old[j]) {
                int temp = old[j - 1];
                old[j - 1] = old[j];
                old[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            cout << old[n - 1 - i / 2] << endl;
        else
            cout << old[i / 2] << endl;
    }
}