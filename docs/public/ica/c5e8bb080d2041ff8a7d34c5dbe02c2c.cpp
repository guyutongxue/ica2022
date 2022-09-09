#include <cstring>
#include <iostream>
using namespace std;

char a[1000][61] = {};

int main() {
    int count;
    for (int i = 0; true; i++) {
        cin >> a[i];
        if (cin.fail()) {
            count = i;
            break;
        }
    }
    // 每个单词的简化表述的长度
    int len[1000] = {};
    for (int i = 0; i < count; i++) {
        // flag[k] 代表 a[i] 与 a[k] 不会出现歧义
        bool flag[1000] = {};
        int num = count - 1;  // 计算会出现歧义的个数
        int full_len = strlen(a[i]);
        for (int j = 0; j < full_len; j++) {
            for (int k = 0; k < count; k++) {
                if (k == i)
                    continue;
                else if (flag[k])
                    continue;
                else {
                    // 如果该位不相等
                    if (a[k][j] != a[i][j]) {
                        flag[k] = true;
                        num--;
                    }
                }
            }

            if (num == 0) {
                len[i] = j + 1;
                break;
            }
        }
        if (num != 0) len[i] = full_len;
    }

    for (int i = 0; i < count; i++) {
        cout << a[i] << " ";
        for (int j = 0; j < len[i]; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
}