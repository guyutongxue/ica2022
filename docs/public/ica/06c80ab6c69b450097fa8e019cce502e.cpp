#include <cstring>
#include <iostream>
using namespace std;
int n;
int ans = 1999;
bool used[105];
char dict[105][25];
char ansStr[2000];

bool check(const char* x, const char* y) {
    int a = strlen(x), b = strlen(y);
    int n = a < b ? a : b;
    for (int i = 0; i < n; i++) {
        if (x[i] != y[i]) return false;
    }
    return true;
}

void dfs(char* des, int length, char* have) {
    for (int i = 1; i <= n; i++) {
        if (!used[i] && check(des, dict[i])) {
            int a = strlen(des), b = strlen(dict[i]);
            if (a == b) {
                if (length + a < ans) {
                    ans = length + a;
                    strcpy(ansStr, have);
                    strcat(ansStr, des);
                }
                return;
            } else if (a < b) {
                used[i] = true;
                char tmp[2000];
                strcpy(tmp, have);
                dfs(dict[i] + a, length + a, strcat(tmp, des));
                used[i] = false;
            } else if (a > b) {
                used[i] = true;
                char tmp[2000];
                strcpy(tmp, have);
                dfs(des + b, length + b, strcat(tmp, dict[i]));
                used[i] = false;
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> dict[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            int iLen = strlen(dict[i]);
            int jLen = strlen(dict[j]);
            if (check(dict[i], dict[j]) && iLen != jLen) {
                if (iLen < jLen) dfs(dict[j] + iLen, iLen, dict[i]);
                if (iLen > jLen) dfs(dict[i] + jLen, jLen, dict[j]);
            }
        }
    }
    cout << ansStr;
}