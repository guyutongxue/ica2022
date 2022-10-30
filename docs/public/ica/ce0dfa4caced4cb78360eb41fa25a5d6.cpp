#include <iostream>
using namespace std;

struct Pin {
    int no;
    int prev;
    int next;
    double rate;
};

int main() {
    int n;
    cin >> n;
    Pin pins[102]{};
    for (int i{0}; i < n; i++) {
        cin >> pins[i].no >> pins[i].prev >> pins[i].next;
        pins[i].rate = 1.0 * pins[i].next / pins[i].prev;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (pins[j].rate > pins[j + 1].rate) {
                Pin temp = pins[j];
                pins[j] = pins[j + 1];
                pins[j + 1] = temp;
            }
        }
    }

    double maxDiff{};
    int bNum{};
    for (int i{1}; i < n; i++) {
        int diff = pins[i].rate - pins[i - 1].rate;
        if (diff > maxDiff) {
            maxDiff = diff;
            bNum = i;
        }
    }
    cout << n - bNum << endl;
    for (int i = bNum; i < n; i++) {
        cout << pins[i].no << endl;
    }
    cout << bNum << endl;
    for (int i = 0; i < bNum; i++) {
        cout << pins[i].no << endl;
    }
}