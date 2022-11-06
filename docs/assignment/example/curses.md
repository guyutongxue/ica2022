# curses 库示例代码

::: info

这是一份使用 curses 库作为 TUI 的示例代码（不包含任何游戏逻辑、算法）。

- 请按照[这里](../tui#高级-tui)的说明，配置好 Xmake 及到第三方库的引用。
- 将下述代码粘贴到 `src/main.cpp` 即可。
- 此代码适用于 Windows/Mac/... 等多个平台，所以略有冗余。所有的 `#ifdef _WIN32` 都是在处理跨平台差异的问题，可以根据自己需要进行删减。

:::

```cpp
#include <curses.h>

#include <clocale>
#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#endif

// 棋盘底纹
constexpr char BOARD[] =
    R"( ┌─┬─┬─┬─┬─┬─┬─┬─┐ 
 ├─┼─┼─┼─┼─┼─┼─┼─┤ 
 ├─┼─┼─┼─┼─┼─┼─┼─┤ 
 ├─┼─┼─┼─┼─┼─┼─┼─┤ 
 ├─┼─┼─┼─┼─┼─┼─┼─┤ 
 ├─┼─┼─┼─┼─┼─┼─┼─┤ 
 ├─┼─┼─┼─┼─┼─┼─┼─┤ 
 ├─┼─┼─┼─┼─┼─┼─┼─┤ 
 └─┴─┴─┴─┴─┴─┴─┴─┘ 
)";

// 定义好目前所需要的颜色对（前景色-背景色对）
constexpr int CP_HIGHLIGHT = 1;
constexpr int CP_DIMMED = 2;
constexpr int CP_CHESSBOARD = 3;
constexpr int CP_BLACK = 4;
constexpr int CP_WHITE = 5;
constexpr int CP_CHOSEN = 6;
void initColors() {
    start_color();
    init_pair(CP_HIGHLIGHT, COLOR_BLUE, COLOR_BLACK);
    constexpr int COLOR_GRAY = 9;
    init_color(COLOR_GRAY, 500, 500, 500);
    init_pair(CP_DIMMED, COLOR_GRAY, COLOR_BLACK);
    init_pair(CP_CHESSBOARD, COLOR_BLACK, COLOR_YELLOW);
    init_pair(CP_BLACK, COLOR_BLACK, COLOR_YELLOW);
    init_pair(CP_WHITE, COLOR_WHITE, COLOR_YELLOW);
    constexpr int COLOR_CHOSEN = 10;
    init_color(COLOR_CHOSEN, 1000, 1000, 500);
    init_pair(CP_CHOSEN, COLOR_CHOSEN, COLOR_CHOSEN);
}
// 便利宏，以某种颜色对打印某些内容
#define WITH_COLOR_PAIR(cp, ...) \
    attron(COLOR_PAIR(cp));      \
    __VA_ARGS__;                 \
    attroff(COLOR_PAIR(cp));

// 存储当前棋盘的数据
int arr[9][9]{};

#ifdef _WIN32
constexpr char NEWLINE = '\r';
#else
constexpr char NEWLINE = '\n';
#endif

// 如果棋子的字体比棋盘制表符要宽，那么就取消下面这一行的注释：
// #define EXTRA_SPACE_AFTER_PIECE
#ifdef EXTRA_SPACE_AFTER_PIECE
#define EXTRA_SPACE " "
#else
#define EXTRA_SPACE
#endif

int main() {
    // 一些关于编码问题的处理代码
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#else
    std::setlocale(LC_ALL, "");
#endif

    // 各种初始化
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    initColors();

    printw("curses 库使用示例\nby 谷雨\n");
    WITH_COLOR_PAIR(CP_DIMMED, printw("（按上下键选择，按回车键确认）"));
    char menus[3][20]{"开始游戏", "读取存档", "退出"};
    int selected = 0;

    // 标题选择的循环
    while (true) {
        move(3, 0);
        for (int i = 0; i < 3; i++) {
            if (i == selected) attron(COLOR_PAIR(CP_HIGHLIGHT));
            printw("%c %s\n", (i == selected ? '>' : ' '), menus[i]);
            if (i == selected) attroff(COLOR_PAIR(CP_HIGHLIGHT));
        }
        refresh();
        int ch = getch();
        if (ch == KEY_UP && selected > 0) {
            selected--;
        } else if (ch == KEY_DOWN && selected < 2) {
            selected++;
        } else if (ch == NEWLINE) {
            break;
        }
    }

    if (selected != 2) {
        int x = 0, y = 0;
        bool black = true;

        // 落子选择的循环
        while (true) {
            clear();

            // 打印棋盘和帮助信息
            WITH_COLOR_PAIR(CP_CHESSBOARD, printw("%s", BOARD));
            WITH_COLOR_PAIR(CP_DIMMED, {
                printw("（按方向键选择位置，按回车键确认。");
                printw("按 : 暂停，按 q 退出）");
            });

            // 打印棋子
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (!arr[i][j]) continue;
                    const int cp = arr[i][j] > 0 ? CP_BLACK : CP_WHITE;
                    WITH_COLOR_PAIR(cp, mvaddstr(i, 2 * j + 1, "●" EXTRA_SPACE));
                }
            }

            // 打印当前“光标”
            WITH_COLOR_PAIR(CP_CHOSEN, mvaddch(x, 2 * y + 1, ' '));

            // 对输入的按键做判断
            int ch = getch();
            if (ch == ':') {
                mvaddstr(10, 0, "游戏暂停中。按任意键继续");
                getch();
            } else if (ch == 'q') {
                break;
            } else if (ch == KEY_UP && x > 0) {
                x--;
            } else if (ch == KEY_DOWN && x < 8) {
                x++;
            } else if (ch == KEY_LEFT && y > 0) {
                y--;
            } else if (ch == KEY_RIGHT && y < 8) {
                y++;
            } else if (ch == NEWLINE) {
                arr[x][y] = (black ? 1 : -1);
                black ^= true;
                x = y = 0;
            }
        }
    }

    endwin();
    std::cout << "再见！" << std::endl;
    std::exit(0);
}
```
