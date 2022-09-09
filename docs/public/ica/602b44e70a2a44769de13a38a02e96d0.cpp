#include <iostream>
#include <vector>

int ans;
int a[20];
int n = 0;

void dfs(int i, int m) {
    if (m == 0) {
        ans++;
        return;
    }
    if (i == n) return;
    
    dfs(i + 1, m - a[i]);
    dfs(i + 1, m);
}

int main() {
    while (true) {
        int x;
        std::cin >> x;
        a[n++] = x;
        if (std::cin.get() == '\n') break;
    }
    int m;
    while (std::cin >> m, m != 0) {
        ans = 0;
        dfs(0, m);
        std::cout << ans << std::endl;
    }
}