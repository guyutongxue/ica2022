#include <iostream>
using namespace std;

enum Direction { UP, DOWN, LEFT, RIGHT };

int main() {
    int m[12][12] = {};

    int r, c;
    char s[102];
    cin >> r >> c;
    cin.ignore();
    cin.getline(s, 102);

    int data[102];
    int data_len = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {
            data[data_len++] = 0;
            data[data_len++] = 0;
        } else {
            int r = s[i] - 'A' + 1;
            data[data_len++] = r / 10;
            data[data_len++] = r % 10;
        }
    }

    int current_row{0}, current_col{0};
    int up_limit = 1, down_limit = r - 1, left_limit = 0, right_limit = c - 1;
    Direction direction{RIGHT};
    for (int i = 0; i < data_len; i++) {
        m[current_row][current_col] = data[i];
        switch (direction) {
            case UP:
                if (--current_row == up_limit) {
                    direction = RIGHT;
                    up_limit++;
                }
                break;
            case DOWN:
                if (++current_row == down_limit) {
                    direction = LEFT;
                    down_limit--;
                }
                break;
            case LEFT:
                if (--current_col == left_limit) {
                    direction = UP;
                    left_limit++;
                }
                break;
            case RIGHT:
                if (++current_col == right_limit) {
                    direction = DOWN;
                    right_limit--;
                }
                break;
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << m[i][j];
        }
    }
    cout << endl;
}