#include <iostream>
#include <string>

int main() {
    int col = 0;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string word;
        std::cin >> word;
        if (col + 1 + word.size() > 80) {
            std::cout << std::endl;
            col = 0;
        } 
        if (col != 0) {
            std::cout << ' ';
            col += 1;
        }
        col += word.size();
        std::cout << word;
    }
}