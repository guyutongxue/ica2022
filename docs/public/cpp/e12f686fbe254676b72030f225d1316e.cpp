#include <iostream>

int main() {
    int n;
    std::cin >> n;
    std::cout.precision(4);
    std::cout << std::fixed;
    while (n--) {
        double f;
        std::cin >> f;
        std::cout << 5.0 * (f - 32) / 9 << std::endl;
    }
}