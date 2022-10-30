#include <iostream>
#include <cstring>
using namespace std;

constexpr int WIDTH = 250;
int op1[WIDTH + 1]{};
int op2[WIDTH + 1]{};
int result[WIDTH + 1]{};

void shiftResult() {
    for (int i = 0; i < WIDTH; i++) {
        if (result[i] >= 10) {
            result[i] -= 10;
            result[i + 1]++;
        }
    }
}

void add() {
    for (int i = 0; i < WIDTH; i++) {
        result[i] = op1[i] + op2[i];
    }
    shiftResult();
    if (result[WIDTH - 1] == 9) {
        cout << "-";
        for (int i = 0; i < WIDTH; i++) {
            result[i] = 9 - result[i];
        }
        result[0]++;
        shiftResult();
    }
    bool output = false;
    for (int i = WIDTH - 1; i >= 0; i--) {
        if (!output && result[i]) {
            output = true;
        }
        if (output) {
            cout << result[i];
        }
    }
    if (!output) {
        cout << 0;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char str1[201]{};
        char str2[201]{};
        cin >> str1 >> str2;
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        if (str1[0] == '-') {
            int j = 0; // op1 index
            for (int i = len1 - 1; i >= 1; i--) {
                op1[j++] = '9' - str1[i];
            }
            while (j < WIDTH) {
                op1[j++] = 9;
            }
            op1[0]++;
        } else {
            int j = 0;
            int min = str1[0] == '+';
            for (int i = len1 - 1; i >= min; i--) {
                op1[j++] = str1[i] - '0';
            }
            while (j < WIDTH) {
                op1[j++] = 0;
            }
        }
        if (str2[0] != '-') {
            int j = 0; // op2 index
            int min = str2[0] == '+';
            for (int i = len2 - 1; i >= min; i--) {
                op2[j++] = '9' - str2[i];
            }
            while (j < WIDTH) {
                op2[j++] = 9;
            }
            op2[0]++;
        } else {
            int j = 0;
            for (int i = len2 - 1; i >= 1; i--) {
                op2[j++] = str2[i] - '0';
            }
            while (j < WIDTH) {
                op2[j++] = 0;
            }
        }
        add();
    }
}