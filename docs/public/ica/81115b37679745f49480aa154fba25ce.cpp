#include <iostream>
using namespace std;

int main() {
    int n;
    int times[22]{};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (times[j] > times[j + 1]) {
                int temp = times[j];
                times[j] = times[j + 1];
                times[j + 1] = temp;
            }
        }
    }
    int currentPatient = 0; // 排在队首的病人号
    int t = 60;   // 当前时间
    int cnt = 0; // 完成就诊人数
    while (currentPatient < n && t <= 170) {
        if (times[currentPatient] <= t) {
            // 就诊
            currentPatient++;
            t += 10;
            cnt++;
        } else {
            // 等一分钟
            t++;
        }
    }
    cout << cnt << endl;
}