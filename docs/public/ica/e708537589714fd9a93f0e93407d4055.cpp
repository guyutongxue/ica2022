#include <iostream>
using namespace std;

int main() {
    int n;
    int pos[10002] = {}, req[10002];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> req[i] >> pos[i + 1];
    }
    for (int i = 1; i <= n; i++) {
        pos[i] += pos[i - 1];
    }
    int totalLength = pos[n];
    int answer = 2000 * 100000;
    int answerPos = 0;
    for (int i = 0; i < n; i++) {
        int value = 0;
        for (int j = 0; j < n; j++) {
            int dis = abs(pos[i] - pos[j]);
            if (dis > totalLength / 2) {
                dis = totalLength - dis;
            }
            value += req[j] * dis;
        }
        if (value < answer) {
            answer = value;
            answerPos = i;
        }
    }
    cout << answerPos << "," << answer << endl;
}