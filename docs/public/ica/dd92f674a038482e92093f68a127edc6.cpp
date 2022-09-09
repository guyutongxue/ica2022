#include <iomanip>
#include <iostream>
using namespace std;

struct Patient {
    int number;
    double time;
};

int main() {
    int n;
    cin >> n;
    Patient patients[1000] = {};
    for (int i = 0; i < n; i++) {
        patients[i].number = i + 1;
        cin >> patients[i].time;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (patients[j].time > patients[j + 1].time) {
                Patient temp = patients[j];
                patients[j] = patients[j + 1];
                patients[j + 1] = temp;
            }
        }
    }
    cout << patients[0].number;
    for (int i = 1; i < n; i++) {
        cout << " " << patients[i].number;
    }
    cout << endl;
    double time = 0;
    for (int i = n - 1; i > 0; i--) {
        time += i * patients[n - i - 1].time;
    }
    double average = 1.0 * time / n;
    cout << fixed << setprecision(2) << average << endl;
}