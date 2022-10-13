#include <iostream>

int main() {
    int n;
    std::cin >> n;
    std::cout << (n % 4 == 0 && n % 100 != 0 || n % 400 == 0 ? 'Y' : 'N') << std::endl;
}