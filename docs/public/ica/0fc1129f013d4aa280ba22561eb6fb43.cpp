#include <cstring>
#include <iostream>
using namespace std;

int main() {
    int cnt[26] = {};
    char line[90];
    while (cin.getline(line, 90)) {
        int len = strlen(line);
        for (int i = 0; i < len; i++) {
            if (isupper(line[i])) {
                cnt[line[i] - 'A']++;
            }
        }
    }

    int max = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > max) {
            max = cnt[i];
        }
    }

    for (int i = max; i >= 1; i--) {
        char l[60] = "#";
        int l_len = 1;
        for (int j = 0; j < 26; j++) {
            l[l_len++] = ' ';
            if (cnt[j] >= i) {
                l[l_len++] = '*';
            } else {
                l[l_len++] = ' ';
            }
        }
        l[l_len] = ' ';
        int k;
        for (k = l_len; l[k] == ' '; k--);
        l[k + 1] = '\0';
        cout << l << endl;
    }
    cout << "# A B C D E F G H I J K L M N O P Q R S T U V W X Y Z" << endl;
}