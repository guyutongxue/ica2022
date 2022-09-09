#include <iostream>
using namespace std;

int main() {
    const int size = 1000;
    int stu[size] = {};
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> stu[i];
    }
    int j;
    int temp = 0;
    for (temp = 0; temp < n - 1; temp++) {
        for (int i = 0; i < n - 1; i++) {
            if (stu[i] > stu[i + 1]) {
                j = stu[i + 1];
                stu[i + 1] = stu[i];
                stu[i] = j;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << stu[i] << endl;
    }
}