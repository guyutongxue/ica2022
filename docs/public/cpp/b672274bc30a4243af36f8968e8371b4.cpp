#include <iostream>
#include <string>

int main() {
    std::string s, w;
    std::cin >> s >> w;
    std::cout << w.find(s) << std::endl;
}