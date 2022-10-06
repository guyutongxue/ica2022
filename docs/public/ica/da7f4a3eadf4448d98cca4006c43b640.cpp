#include <cstring>
#include <iostream>
using namespace std;

struct Word {
    char word[30];
    int occurrence;
};

int main() {
    Word words[1000]{};
    int wordsCnt = 0;
    char c;
    char currentWord[30]{};
    int currentWordLen = -1;
    while (cin.get(c)) {
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c == '\'') {
            if (currentWordLen == -1) {
                currentWord[0] = c;
                currentWordLen = 1;
            } else {
                currentWord[currentWordLen++] = c;
            }
        } else {
            if (currentWordLen > 0) {
                currentWord[currentWordLen] = '\0';

                bool occur = false;
                for (int i = 0; i < wordsCnt; i++) {
                    if (strcmp(words[i].word, currentWord) == 0) {
                        occur = true;
                        words[i].occurrence++;
                        break;
                    }
                }
                if (!occur) {
                    strcpy(words[wordsCnt].word, currentWord);
                    words[wordsCnt].occurrence = 1;
                    wordsCnt++;
                }
                currentWordLen = -1;
            }
        }
    }
    for (int i = 0; i < wordsCnt; i++) {
        cout << words[i].word << ' ' << words[i].occurrence << endl;
    }
}