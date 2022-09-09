#include <iostream>
using namespace std;

int main() {
    int n, m = -100000;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > m) {
            m = arr[i];
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != m) sum += arr[i];
    }
    cout << sum << endl;
}