#include <iostream>

// https://www.wolframalpha.com/input?i=inverse+of+%5B%5Ba%2C1%2C0%2C0%2C0%5D%2C%5B0%2Cb%2C1%2C0%2C0%5D%2C%5B0%2C0%2Cc%2C1%2C0%5D%2C%5B0%2C0%2C0%2Cd%2C1%5D%2C%5B1%2C0%2C0%2C0%2Ce%5D%5D

int main() {
    int k;
    std::cin >> k;
    k *= 100;
    int a, b, c, d, e;
    std::cin >> a >> b >> c >> d >> e;
    int deep{a * b * c * d * e + 1};
    if (deep > k) {
        std::cout << "not found" << std::endl;
        std::exit(0);
    }
    // clang-format off
    int results[5]{
        b * c * d * e - c * d * e + d * e - e + 1,
        1 + a * c * d * e - a * d * e + a * e - a,
        -b + 1 + a * b * d * e - a * b * e + a * b,
        b * c - c + 1 + a * b * c * e - a * b * c,
        -b * c * d + c * d - d + 1 + a * b * c * d};
    // clang-format on
    for (int i{0}; i < 5; i++) {
        for (int j{0}; j < i; j++) {
            if (results[i] == results[j]) {
                std::cout << "not found" << std::endl;
                std::exit(0);
            }
        }
    }
    std::cout << deep;
    for (auto i : results) {
        std::cout << " " << i;
    }
    std::cout << std::endl;
}
