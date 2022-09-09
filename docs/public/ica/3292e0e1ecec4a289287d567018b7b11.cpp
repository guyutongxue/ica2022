#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << "None";
        exit(0);
    }
    int num[1002];
    int count[1002] = {};
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (num[j] < num[i]) count[i]++;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << count[i] << endl;
    }
}