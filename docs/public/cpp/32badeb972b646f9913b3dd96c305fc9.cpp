#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <string>

int main() {
    std::set<std::string> words;
    std::copy(std::istream_iterator<std::string>(std::cin),
              std::istream_iterator<std::string>{},
              std::inserter(words, words.end()));
    for (auto& i : words) {
        std::cout << i << std::endl;
    }
}
