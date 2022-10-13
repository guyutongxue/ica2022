#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::tuple<int, int>> t(n);
    for (auto& i : t) {
        std::cin >> std::get<0>(i) >> std::get<1>(i);
    }
    std::sort(t.begin(), t.end(), [](auto&& a, auto&& b) {
        return std::get<1>(a) < std::get<1>(b);
    });
    int currentTime = 0;
    int count = 0;
    for (auto& i : t) {
        if (std::get<0>(i) >= currentTime) {
            count++;
            currentTime = std::get<1>(i);
        }
    }
    std::cout << count << std::endl;
}