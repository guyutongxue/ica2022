#include <iostream>

#define AT(m, x, y) *(*(m + x) + y)

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int A[102][102];
        int B[102][102];
        int n, m, k;
        std::cin >> n >> m >> k;
        for (int i{0}; i < n; i++) {
            for (int j{0}; j < m; j++) {
                std::cin >> AT(A, i, j);
            }
        }
        for (int j{0}; j < m; j++) {
            for (int l{0}; l < k; l++) {
                std::cin >> AT(B, j, l);
            }
        }
        for (int i{0}; i < n; i++) {
            for (int l{0}; l < k; l++) {
                int res = 0;
                for (int j{0}; j < m; j++) {
                    res += AT(A, i, j) * AT(B, j, l);
                }
                std::cout << res << " \n"[l == k - 1];
            }
        }
    }
}