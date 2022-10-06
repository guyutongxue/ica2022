#include <iostream>
using namespace std;
struct Coord {
    int x, y;
};
int main() {
    static Coord in[1000], dom[1000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> in[i].x >> in[i].y;
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        bool flag = false;
        for (int j = 0; j < n; j++)
            if (i != j)
                if (in[j].x >= in[i].x && in[j].y >= in[i].y) {
                    flag = true;
                    break;
                }
        if (!flag) {
            dom[k++] = in[i];
        }
    }
    for (int i = 0; i < k; i++)
        for (int j = i + 1; j < k; j++)
            if (dom[i].x > dom[j].x) {
                Coord temp = dom[i];
                dom[i] = dom[j];
                dom[j] = temp;
            }
    bool isFirst = true;
    for (int i = 0; i < k; i++) {
        if (isFirst) {
            isFirst = false;
        } else {
            cout << ",";
        }
        cout << "(" << dom[i].x << "," << dom[i].y << ")";
    }
}