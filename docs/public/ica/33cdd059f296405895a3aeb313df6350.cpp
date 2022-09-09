#include<iostream>
#include<cstring>
using namespace std;

struct Bracket {
    int l;
    int r = 0;
    int dis;
};

int main() {
    int sum_left = 0, sum_right = 0;
    Bracket bracket[500];
    char str[600];
    cin.getline(str, 600);
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(') {
            sum_left++;
            bracket[sum_left].l = i + 1;
        }
        if (str[i] == ')') {
            sum_right++;
            for (int j = sum_left; j >= 1; j--) {
                if (bracket[j].r == 0) {
                    bracket[j].r = i + 1;
                    break;
                }
            }
        }
        if (sum_right > sum_left) {
            cout << "mismatch" << endl;
            exit(0);
        }
    }
    if (sum_left != sum_right) {
        cout << "mismatch" << endl;
        exit(0);
    }
    int sum = sum_left;
    for (int i = 1; i <= sum; i++)
        bracket[i].dis = bracket[i].r - bracket[i].l;
    for (int i = 1; i < sum; i++) {
        for (int j = 1; j <= sum - i; j++) {
            if (bracket[j].dis > bracket[j + 1].dis) {
                Bracket temp = bracket[j];
                bracket[j] = bracket[j + 1];
                bracket[j + 1] = temp;
            }
            else if (bracket[j].dis == bracket[j + 1].dis) {
                if (bracket[j].l > bracket[j + 1].l) {
                    Bracket temp = bracket[j];
                    bracket[j] = bracket[j + 1];
                    bracket[j + 1] = temp;
                }
            }
        }
    }
    for (int i = 1; i <= sum; i++)
        cout << bracket[i].l << "," << bracket[i].r << endl;
    if (sum == 0)
        cout << "0,0" << endl;
}