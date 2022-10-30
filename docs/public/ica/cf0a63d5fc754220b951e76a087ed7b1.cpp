#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    static int a[20002]{};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int max{};
    for (int i = 0; i < n; i++) {
        int height = a[i];
        int width = 1;
        for (int j = i - 1; j >= 0 && a[j] >= height; j--) {
            width++;
        }
        for (int j = i + 1; j <= n && a[j] >= height; j++) {
            width++;
        }
        int area = height * width;
        if (area > max) {
            max = area;
        }
    }
    cout << max << endl;
}