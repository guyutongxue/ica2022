#include <iostream>
#include <cstring>
using namespace std;

bool isAbbr(const char* a, const char* b) {
    if (*a == '\0') {
        return true;
    }
    int i{0};
    for (; b[i] != '\0'; i++) {
        if (b[i] == a[0]) {
            break;
        }
    }
    if (b[i] != '\0') {
        return isAbbr(a + 1, b + i + 1);
    } else {
        return false;
    }
}
int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();
    while (n--) {
        char abbr[302], word[302];
        cin.getline(abbr, 302, ':');
        cin.getline(word, 302);
        if (strlen(abbr) >= strlen(word)) {
            cout << "NO" << endl;
        } else {
            cout << (isAbbr(abbr, word) ? "YES" : "NO") << endl;
        }
    }
}