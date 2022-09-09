#include <cstring>
#include <iostream>
using namespace std;

int main() {
    char c[1010];
    cin.getline(c, 1010);
    int len = strlen(c);
    int numOfSpace;  // 空格的数量
    bool head = true;
    char cha[1010][1010];
    int cnt = 0;  // 单词的数量
    int p = 0;
    for (int i = 0; i < len; i++) {
        if (c[i] == ' ') {
            numOfSpace++;
            head = true;
            if (p != 0) {
                cha[cnt][p] = '\0';
                p = 0;
            }
        } else {  // 字母
            if (head) {
                head = false;
                p = 0;
                cnt++;
                cha[cnt][0] = c[i];
                p++;
            } else {
                cha[cnt][p] = c[i];
                p++;
            }
        }
    }
    if (cnt == 1) {
        char res[1010];
        char space1[1010];
        if (numOfSpace == 0) {
            cout << cha[1] << endl;
            exit(0);
        }
        for (int i = 0; i < numOfSpace; i++) {
            space1[i] = ' ';
        }
        space1[numOfSpace] = '\0';
        strcpy(res, cha[0]);
        strcat(res, space1);
        cout << res << endl;
    } else {
        int spaceInEnd = numOfSpace % (cnt - 1);
        int spacePreCha = numOfSpace / (cnt - 1);
        char space1[1010], space2[1010];
        for (int i = 0; i < spacePreCha; i++) {
            space1[i] = ' ';
        }
        space1[spacePreCha] = '\0';
        for (int i = 0; i < spaceInEnd; i++) {
            space2[i] = ' ';
        }
        space2[spaceInEnd] = '\0';
        char res[1010];
        for (int i = 1; i <= cnt; i++) {
            strcat(res, cha[i]);
            if (i != cnt) strcat(res, space1);
        }
        strcat(res, space2);
        cout << res << endl;
    }
}