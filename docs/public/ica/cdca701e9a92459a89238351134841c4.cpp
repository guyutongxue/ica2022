#include <iostream>
using std::cin, std::cout, std::endl;

// 由于存在 std::end，所以不能 using namespace std

int start[100'000]{};
int end[100'000]{};

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> start[i] >> end[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (end[j] > end[j + 1]) {
                int temp = start[j];
                start[j] = start[j + 1];
                start[j + 1] = temp;
                temp = end[j];
                end[j] = end[j + 1];
                end[j + 1] = temp;
            }
        }
    }
    int currentTime = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (start[i] >= currentTime) {
            count++;
            currentTime = end[i];
        }
    }
    cout << count << endl;
}