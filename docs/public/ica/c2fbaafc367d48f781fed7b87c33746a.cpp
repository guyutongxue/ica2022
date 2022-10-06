#include <iostream>
using namespace std;

constexpr int MAX_INT{200200};

int bucket[MAX_INT]{};
int _min = MAX_INT, _size = 0;

void load(int num) {
    bucket[num]++;
    if (num < _min) _min = num;
    _size++;
}

int unload_min() {
    int ret = 0;
    if (!bucket[_min])
        while (!bucket[_min]) _min++;
    ret = _min;
    bucket[_min]--;
    _size--;
    return ret;
}

int main() {
    int n = 0, num = 0;
    char opt[20]{};
    std::ios::sync_with_stdio(false);

    std::cin >> n;
    while (n--) {
        std::cin >> num;
        load(num);
    }

    std::cin >> n;
    while (n--) {
        std::cin >> opt;
        switch (opt[0]) {
            case 'E':
                if (_size)
                    std::cout << unload_min() << '\n';
                else
                    std::cout << "NULL\n";
                break;
            case 'A':
                std::cin >> num;
                load(num);
                break;
            default: break;
        }
    }
}