#include <iostream>
#include <array>
#include <algorithm>

int main() {
    std::array<int, 10> a, b;
    std::array<int, 20> c;
    for (auto& i : a) {
        std::cin >> i;
    }
    for (auto& i : b) {
        std::cin >> i;
    }
    std::merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
    bool isFirst = true;
    for (auto i : c) {
        if (isFirst) {
            isFirst = false;
        } else {
            std::cout << ' ';
        }
        std::cout << i;
    }
}