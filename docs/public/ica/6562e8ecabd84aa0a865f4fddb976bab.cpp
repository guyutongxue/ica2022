#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

struct Point {
    int x, y, z;
};

struct PointPair {
    Point p;
    Point q;
    double d;
};

PointPair pairs[50]{};

int cnt = 1;

double distance(Point p, Point q) {
    return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y) + (p.z - q.z) * (p.z - q.z));
}

void sort() {
    for (int i = 1; i <= cnt - 1; i++) {
        for (int j = 1; j <= cnt - 1 - i; j++) {
            if (pairs[j].d < pairs[j + 1].d) {
                PointPair temp = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    Point a[11]{};
    for (int i = 1; i <= n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        a[i] = {x, y, z};
    }

    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            pairs[cnt] = {a[i], a[j], distance(a[i], a[j])};
            cnt++;
        }
    }
    sort();
    for (int i = 1; i <= cnt - 1; i++) {
        cout << '(' << pairs[i].p.x << ',' << pairs[i].p.y << ',' << pairs[i].p.z << ")-("
             << pairs[i].q.x << ',' << pairs[i].q.y << ',' << pairs[i].q.z << ")=" << fixed
             << setprecision(2) << pairs[i].d << endl;
    }
}
