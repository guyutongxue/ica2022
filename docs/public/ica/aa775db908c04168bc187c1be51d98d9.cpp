#include <cctype>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        char line[82]{};
        cin.getline(line, 82);
        int lineLen = strlen(line);
        bool f1 = isalpha(line[0]) || line[0] == '_';
        bool f2 = true;
        for (int i = 1; i < lineLen; i++) {
            if (!isalpha(line[i]) && !isdigit(line[i]) && line[i] != '_') {
                f2 = false;
                break;
            }
        }
        cout << (f1 && f2) << endl;
    }
}