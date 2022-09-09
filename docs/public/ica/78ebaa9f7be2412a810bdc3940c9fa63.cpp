#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char s[12];
    cin >> s;
    int max = -2000000000;
    int firstPos = s[0] == '-' ? 2 : 1;
    int len = strlen(s);
    for (int i = firstPos; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            char temp;
            temp = s[i], s[i] = '\0';
            int a = atoi(s);
            s[i] = temp, temp = s[j], s[j] = '\0';
            int b = atoi(s + i);
            s[j] = temp;
            int c = atoi(s + j);
            if (max < a * b * c) {
                max = a * b * c;
            }
        }
    }
     cout << max << endl;
}