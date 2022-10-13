#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (auto& i : v) {
        std::cin >> i;
    }
    std::cout << std::min_element(v.begin(), v.end()) - v.begin() + 1
              << std::endl;
}