#include <iostream>
#include <cstring>
using namespace std;

constexpr char MONTH_NAMES[12][4]{"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                              "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
constexpr char WEEK_NAMES[7][4]{"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

// Zeller Formula
int calcWeek(int year, int month, int day) {
    if (month <= 2) year--, month += 12;
    int c{year / 100};
    int y{year % 100};
    int week{y + y / 4 + c / 4 - 2 * c + 26 * (month + 1) / 10 + day - 1};
    week %= 7;
    return week < 0 ? week + 7 : week;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char s[20]{};
        cin >> s;
        int sLen = strlen(s);
        int d{0}, m{0}, y{0};
        int curLen = 0;
        for (int j{0}; j <= sLen; j++) {
            if (s[j] == '-' || s[j] == '/' || s[j] == '\0') {
                if (curLen == 2) {
                    d = (s[j - 2] - '0') * 10 + (s[j - 1] - '0');
                }
                if (curLen == 3) {
                    char curMonth[4]{};
                    curMonth[0] = s[j - 3];
                    curMonth[1] = s[j - 2];
                    curMonth[2] = s[j - 1];
                    for (int i = 0; i < 12; i++) {
                        if (strcmp(MONTH_NAMES[i], curMonth) == 0) {
                            m = i + 1;
                            break;
                        }
                    }
                }
                if (curLen == 4) {
                    y = (s[j - 4] - '0') * 1000 + (s[j - 3] - '0') * 100 + (s[j - 2] - '0') * 10 + (s[j - 1] - '0');
                }
                curLen = 0;
            } else {
                curLen++;
            }
        }
        cout << WEEK_NAMES[calcWeek(y, m, d)] << '.' << endl;
    }
}