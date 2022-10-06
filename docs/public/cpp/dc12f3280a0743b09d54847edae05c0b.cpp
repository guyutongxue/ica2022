#include <deque>
#include <iostream>
#include <string>

int read() {
    int n;
    std::string str;
    std::cin >> n >> str;
    int result = 0;
    for (int i = 0; str[i]; i++) {
        (result *= n) += (str[i] > '9' ? str[i] + 10 - 'a' : str[i] - '0');
    }
    return result;
}

int main() {
    int a = read();
    int b = read();

    int c{a + b};
    int n;
    std::cin >> n;
    std::deque<int> bits;
    do {
        bits.push_front(c % n);
    } while (c /= n);
    for (int i : bits) {
        std::cout << char(i > 9 ? 'a' + i - 10 : i + '0');
    }
}