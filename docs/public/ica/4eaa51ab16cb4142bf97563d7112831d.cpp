#include <cstring>
#include <iostream>
using namespace std;

int main() {
    int k, m;
    char a[50];
    char comma;
    cin >> k >> comma >> m >> comma >> a;
    int n = strlen(a);
    for (int i = 1; i <= m; i++) {
        int p = n - 1;
        a[p]++;
        while (a[p] - '0' == k) {
            a[p] = '0';
            if (p == 0) {
                char newA[50] = "1";
                strcat(newA, a);
                strcpy(a, newA);
                n++;
                break;
            }
            p--;
            a[p]++;
        }
        cout << a;
        if (i % 5 == 0) {
            cout << endl;
        } else if (i != m) {
            cout << ",";
        }
    }
}
