#include <cstring>
#include <iostream>
using namespace std;

char str[8]{};
bool used[8]{};
char now[8]{};
int len{};

void dfs(int cnt) {
    for (int i = 0; i < len; i++) {
        if (!used[i]) {
            now[cnt] = str[i];
            used[i] = true;
            dfs(cnt + 1);
            used[i] = false;
        }
    }
    if (cnt == len - 1) {
        cout << now << endl;
        cnt = 0;
    }
}

int main() {
    cin >> str;
    len = strlen(str);
    dfs(0);
}