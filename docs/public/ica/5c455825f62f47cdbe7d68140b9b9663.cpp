#include <cstring>
#include <iostream>
using namespace std;

const char* FRUITS[7]{"apples", "bananas", "peaches",     "cherries",
                      "pears",  "oranges", "strawberries"};

int main() {
    char line[500]{};
    while (cin.getline(line, 500)) {
        bool replaced = false;
        for (int i = 0; i < 7; i++) {
            char* occur = strstr(line, FRUITS[i]);
            if (occur) {
                *occur = '\0';
                cout << line << "Brussels sprouts" << (occur + strlen(FRUITS[i])) << endl;
                replaced = true;
                break;
            }
        }
        if (!replaced) {
            cout << "You must not enjoy fruit." << endl;
        }
    }
}