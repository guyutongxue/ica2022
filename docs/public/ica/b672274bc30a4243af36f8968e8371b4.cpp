#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char s[50]{};
    char w[50]{};
    cin >> s >> w;
    /* 此为“投机取巧”之法，std::strstr 即为本题答案
    char* pos = strstr(w, s);
    cout << pos - w << endl;
    */
   int sLen = strlen(s);
   int wLen = strlen(w);
    for (int i = 0; i <= wLen - sLen; i++) {
        bool isSame = true;
        for (int j = 0; j < sLen; j++) {
            isSame &= w[i + j] == s[j];
        }
        if (isSame) {
            cout << i << endl;
            break;
        }
    }
}