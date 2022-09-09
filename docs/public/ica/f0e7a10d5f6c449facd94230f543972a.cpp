#include <iostream>
using namespace std;

int main() {
    int a[16]{};
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    int max_index = 0;
    for (int i = 1; i < 16; i++) {
        if (a[i] > a[max_index]) {
            max_index = i;
        }
    }

    cout << max_index << endl;
}