#include <cstring>
#include <iostream>
using namespace std;

char s[50000000]{};
int len = 0;

int month[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

void get_digit(int num, char* ret) {
    memset(ret, '0', 10);
    int l = 0;
    while (num > 0) {
        ret[l++] = num % 10 + '0';
        num /= 10;
    }
}

int is_leap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int generate_day(int y, int m, int d, int curr) {
    char ymd[3][10]{};
    get_digit(y, ymd[0]);
    get_digit(m, ymd[1]);
    get_digit(d, ymd[2]);
    int l_ymd[3] = {4, 2, 2};
    for (int j = 0; j < 3; j++) {
        for (int i = l_ymd[j] - 1; i >= 0; i--) {
            s[curr++] = ymd[j][i];
        }
    }
    s[curr] = '\0';
    return curr;
}

int generate_month(int y, int m, int curr) {
    int leap = is_leap(y);
    for (int i = 1; i <= month[leap][m]; i++) {
        curr = generate_day(y, m, i, curr);
    }
    return curr;
}

int generate_year(int y, int curr) {
    for (int i = 1; i <= 12; i++) {
        curr = generate_month(y, i, curr);
    }
    return curr;
}

void generate_s() {
    for (int i = 3; i <= 31; i++) {
        len = generate_day(2021, 1, i, len);
    }
    for (int i = 2; i <= 12; i++) {
        len = generate_month(2021, i, len);
    }
    for (int i = 2022; i <= 2099; i++) {
        len = generate_year(i, len);
    }
}

int main() {
    int n = 0;
    char a[10]{};
    generate_s();
    cin >> n;
    while (n--) {
        cin >> a;
        cout << strstr(s, a) - s + 1 << endl;
    }
}