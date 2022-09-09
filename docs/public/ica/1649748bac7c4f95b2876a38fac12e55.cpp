#include <iostream>
using namespace std;

bool covered[100005]{};

int main() {
    int n;
    cin >> n;
    int inf = 100005;
    int sup = 1;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (inf > a) inf = a;
        if (sup < b) sup = b;
        for (int j = a; j < b; j++) covered[j] = true;
    }
    bool need = false;
    for (int i = inf; i < sup; i++) {
        if (!covered[i]) {
            need = true;
            for (int j = i; j <= sup; j++) {
                if (covered[j]) {
                    cout << i << ' ' << j << endl;
                    break;
                }
                covered[j] = true;
            }
        }
    }
    if (!need) {
        cout << "Not Needed" << endl;
    }
}