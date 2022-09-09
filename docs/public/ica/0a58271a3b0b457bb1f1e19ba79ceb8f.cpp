#include <cstring>
#include <iostream>
using namespace std;

struct Order {
    char name[22];
    int num;
};
int main() {
    Order order[110];
    int no[2000] = {};
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> order[i].name >> order[i].num;
    }
    int n;
    cin >> n;
    for (int i = 1; i <= t; i++) {
        if (order[i].num == n) {
            char* temp = order[i].name;
            for (int j = 1; j <= t; j++) {
                if (strcmp(order[i].name, temp) == 0 && order[j].num != n) {
                    no[order[j].num]++;
                }
            }
        }
    }
    int result = 0;
    int max = 0;
    for (int i = 1; i <= 1000; i++) {
        if (no[i] > max) {
            max = no[i];
            result = i;
        }
    }
    cout << result << endl;
}