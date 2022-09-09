#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n <= 9) {
            cout << n << endl;
            continue;
        } else if (n <= 189) {
            int t{10 + (n - 10) / 2};
            if (n % 2 == 0) {
                cout << t / 10 << endl;
            } else {
                cout << t % 10 << endl;
            }
        } else if (n <= 2889) {
            int t{100 + (n - 190) / 3};
            int i{(n - 190) % 3};
            char buf[5];
            sprintf(buf, "%d", t);
            cout << buf[i] << endl;
        } else {
            int t{1000 + (n - 2890) / 4};
            int i{(n - 2890) % 4};
            char buf[5];
            sprintf(buf, "%d", t);
            cout << buf[i] << endl;
        }
    }
}