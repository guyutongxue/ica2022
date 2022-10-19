#include <cstring>
#include <iostream>

using namespace std;

constexpr char H[][10] = {"pop",  "no",   "zip",   "zotz",  "tzec", "xul", "yoxkin",
                          "mol",  "chen", "yax",   "zac",   "ceh",  "mac", "kankin",
                          "muan", "pax",  "koyab", "cumhu", "uayet"};
constexpr char T[][10] = {"imix",  "ik",    "akbal", "kan",   "chicchan", "cimi", "manik",
                          "lamat", "muluk", "ok",    "chuen", "eb",       "ben",  "ix",
                          "mem",   "cib",   "caban", "eznab", "canac",    "ahau"};
int main() {
    char ignore;
    int n;
    cin >> n;
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        int hday, hyear;
        char hmonth[10];
        cin >> hday >> ignore >> hmonth >> hyear;

        int day = 0;
        day += hyear * 365;
        int m = 0;
        for (int i = 0; i < 19; i++) {
            if (strcmp(H[i], hmonth) == 0) {
                m = i;
                break;
            }
        }
        day += m * 20 + hday;

        int tyear = day / 260;
        int tday1 = (day % 260) % 13 + 1;
        int tday2 = (day % 260) % 20;

        cout << tday1 << ' ' << T[tday2] << ' ' << tyear << endl;
    }
}