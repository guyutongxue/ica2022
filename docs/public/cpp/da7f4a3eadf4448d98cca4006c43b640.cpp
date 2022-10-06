#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

struct Word {
    std::string word;
    int occurrence;
};

int main() {
    std::vector<Word> words;
    char c;
    std::string currentWord;
    bool inWord = false;
    while (std::cin.get(c)) {
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c == '\'') {
            if (!inWord) {
                currentWord = std::string(1, c);
                inWord = true;
            } else {
                currentWord += c;
            }
        } else {
            if (inWord) {
                if (auto it = std::find_if(words.begin(), words.end(),
                                           [&](auto&& w) { return w.word == currentWord; });
                    it != words.end()) {
                    it->occurrence++;
                } else {
                    words.push_back({currentWord, 1});
                }
                inWord = false;
            }
        }
    }
    for (auto& i : words) {
        std::cout << i.word << ' ' << i.occurrence << std::endl;
    }
}