#include <iostream>
using namespace std;

struct Problem {
    int score;
    int time;
    int bestResult;
    int timeSpent;
};

int main() {
    int n, t;
    cin >> n >> t;
    Problem p[1000] = {};
    for (int i = 1; i <= n; i++) {
        cin >> p[i].score;
        cin.ignore();
        cin >> p[i].time;
        p[i].bestResult = p[i].timeSpent = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (p[i].timeSpent + p[j].time <= t) {
                p[i].bestResult += p[j].score;
                p[i].timeSpent += p[j].time;
            }
            else break;
        }
    }
    int bestId = 0;
    for (int i = 1; i <= n; i++) {
        if (p[i].bestResult > p[bestId].bestResult) {
            bestId = i;
        }
        else if (p[i].bestResult == p[bestId].bestResult) {
            if (p[i].timeSpent < p[bestId].timeSpent) {
                bestId = i;
            }
        }
    }
    cout << bestId << ':' << p[bestId].bestResult << ';' << p[bestId].timeSpent << endl;
}