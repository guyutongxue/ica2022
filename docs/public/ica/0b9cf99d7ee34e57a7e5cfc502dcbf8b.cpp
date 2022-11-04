#include <iostream>
#include <cstring>
#include <algorithm>
using std::cin, std::cout, std::endl;

int memory[502][502]{};
bool hasMemory[502][502]{};

char* aBegin{};
char* bBegin{};

int diff(char* a, char* b) {
    if (hasMemory[a - aBegin][b - bBegin]) {
        return memory[a - aBegin][b - bBegin];
    }
    int r;
    if (*a == '\0') {
        r = std::strlen(b);
    } else if (*b == '\0') {
        r = std::strlen(a);
    } else if (*a == *b) {
        r = diff(a + 1, b + 1);
    } else {
        r = 1 + std::min(diff(a, b + 1), diff(a + 1, b));
    }
    hasMemory[a - aBegin][b - bBegin] = true;
    memory[a - aBegin][b - bBegin] = r;
    return r;
}

int main() {
    char pattern[502]{};
    cin >> pattern;
    int n;
    cin >> n;
    static char targets[202][502]{};
    static int diffs[202]{};
    int minDiff = 1000;
    for (int i = 0; i < n; i++) {
        std::memset(hasMemory, 0, sizeof(hasMemory));
        aBegin = pattern, bBegin = targets[i];
        cin >> targets[i];
        diffs[i] = diff(pattern, targets[i]);
        if (diffs[i] < minDiff) {
            minDiff = diffs[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (diffs[i] == minDiff) {
            cout << targets[i] << endl;
        }
    }
}
