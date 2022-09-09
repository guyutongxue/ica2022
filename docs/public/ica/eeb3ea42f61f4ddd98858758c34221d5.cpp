#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int counted = 0;
    for (int i = 0; i < n; i++) {
        char name[10];
        double temp;
        bool cough;
        cin >> name >> temp >> cough;
        if (temp >= 37.5 && cough) {
            cout << name << endl;
            counted++;
        }
    }
    cout << counted << endl;
}