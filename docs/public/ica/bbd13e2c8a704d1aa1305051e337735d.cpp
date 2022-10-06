#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int col = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char word[40]{};
        cin >> word;
        int wordLen = strlen(word);
        if (col + 1 + wordLen > 80) {
            cout << endl;
            col = 0;
        } 
        if (col != 0) {
            cout << ' ';
            col += 1;
        }
        col += wordLen;
        cout << word;
    }
}