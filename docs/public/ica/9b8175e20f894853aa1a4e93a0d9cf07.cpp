#include <cstring>
#include <iostream>
using namespace std;

int main() {
    char s[310] = {}, s1[15] = {}, s2[15] = {};
    cin.getline(s, 310, ',');
    cin.getline(s1, 15, ',');
    cin.getline(s2, 15);
    int lens1 = strlen(s1) - 1, lens2 = strlen(s2) - 1, lens = strlen(s) - 1;

    // 从左到右，找到第一个和 s1 完全相同的位置，记录终点
    bool flag1 = false;
    int place1 = 0;
    for (int i = lens1; i <= lens; i++) {
        int check = true;
        for (int j = i - lens1; j <= i; j++) {
            if (s[j] != s1[j - i + lens1]) {
                check = false;
                break;
            }
        }
        if (check) {
            flag1 = true;
            place1 = i;
            break;
        }
    }

    // 从右到左，判别 s2
    bool flag2 = false;
    int place2 = 0;
    for (int i = lens - lens2; i >= 0; i--) {
        int check = true;
        for (int j = i; j <= i + lens2; j++) {
            if (s[j] != s2[j - i]) {
                check = false;
                break;
            }
        }
        if (check) {
            flag2 = true;
            place2 = i;
            break;
        }
    }

    if (!flag1 || !flag2 || place1 > place2)
        cout << "-1" << endl;
    else
        cout << place2 - place1 - 1 << endl;
}