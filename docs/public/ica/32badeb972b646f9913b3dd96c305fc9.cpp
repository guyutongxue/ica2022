#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char words[100][51]{};
    int n = 0;
    while (cin >> words[n]) {
        n++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(words[j], words[j + 1]) > 0) {
                char temp[51]{};
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }
    char last[51]{};
    for (int i = 0; i < n; i++) {
        if (strcmp(last, words[i]) != 0) {
            cout << words[i] << endl;
        }
        strcpy(last, words[i]);
    }
}
