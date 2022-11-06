# BGI (EGE) 库示例代码

::: info

这是一份使用 EGE 库（BGI 接口）作为 GUI 的示例代码（不包含任何游戏逻辑、算法）。

- 请按照[这里](../gui#bgi)的说明，配置好 Xmake 及到第三方库的引用。
- 将下述代码粘贴到 `src/main.cpp` 即可。
- 助教也是第一次写 BGI，如果有写得啰嗦的地方烦请指教。

:::

```cpp
#include <Windows.h>
#include <ege.h>

#include <algorithm>
#include <iostream>
#include <string>

enum struct Page { Menu, Board, Pause };

struct String : public std::string {
    using std::string::string;
    operator LPCSTR() {
        return c_str();
    }
};

// 我们希望 UTF-8 遍地开花，但是 EGE 库使用了 ANSI 版本的 API
// 所以，这个函数将字符串字面量转换为 ANSI 编码
// 使用方法：L"字符串"_ansi
String operator""_ansi(const wchar_t* src, std::size_t len) {
    if (len == 0) return {};
    int bufferSize =
        WideCharToMultiByte(CP_ACP, 0, src, len, nullptr, 0, nullptr, nullptr);
    String result(bufferSize, 0);
    WideCharToMultiByte(CP_ACP, 0, src, len, result.data(), bufferSize, nullptr,
                        nullptr);
    return result;
}

// 是否为第一次鼠标事件
// 在刚启动程序、切换页面的时候，残留的鼠标事件会导致错误逻辑
// 故设置此变量以清除它们。直到第一次移动后，设置为 false
bool firstMouse = true;

// 鼠标是否位于按钮内部
#define IN_BUTTON(msg, bx, by, w, h)                                \
    ((msg).x >= (bx) && (msg).x <= (bx) + (w) && (msg).y >= (by) && \
     (msg).y <= (by) + (h))

// 绘制一个按钮
void drawButton(const wchar_t* title, int x, int y, int w, int h,
                ege::color_t fgcolor, ege::color_t bgcolor) {
    struct {
        int x, y;
    } mouse{};
    ege::mousepos(&mouse.x, &mouse.y);
    // 如果当前的鼠标位置位于按钮内，则把背景颜色调暗
    if (!firstMouse && IN_BUTTON(mouse, x, y, w, h)) {
        int r = EGEGET_R(bgcolor), g = EGEGET_G(bgcolor), b = EGEGET_B(bgcolor);
        bgcolor = EGERGB(std::clamp(r - 30, 0, 255), std::clamp(g - 30, 0, 255),
                         std::clamp(b - 30, 0, 255));
    }
    ege::setfillcolor(bgcolor);
    ege::setfontbkcolor(bgcolor);
    ege::setcolor(fgcolor);
    constexpr int FONT_SIZE = 30;
    ege::setfont(FONT_SIZE, 0, L"微软雅黑"_ansi);
    int tw = ege::textwidth(title);
    int th = ege::textheight(title);
    ege::bar(x, y, x + w, y + h);
    int yOffset = (h - th) / 2;
    int xOffset = (w - tw) / 2;
    ege::outtextxy(x + xOffset, y + yOffset, title);
}

void drawButton(const wchar_t* title, int x, int y, int w, int h) {
    drawButton(title, x, y, w, h, EGERGB(0, 0, 0), EGERGB(255, 255, 255));
}

// 存储棋局的数组
int arr[9][9]{};

int main() {
    ege::initgraph(500, 500);
    constexpr ege::color_t BGCOLOR = EGERGB(207, 235, 246);

    Page page = Page::Menu;
    bool black = true;

    // 渲染循环
    for (; ege::is_run(); ege::delay_fps(60)) {
        ege::cleardevice();
        ege::setbkcolor(BGCOLOR);

        constexpr int GRID_WIDTH = 44;
        constexpr int START_XY = 50 + GRID_WIDTH / 2;

        // 针对不同的页面，绘制不同的内容
        switch (page) {
            case Page::Menu: {
                ege::setcolor(EGERGB(0, 0, 255));
                ege::setfontbkcolor(BGCOLOR);
                ege::setfont(40, 0, L"微软雅黑"_ansi);
                ege::outtextxy(100, 100, L"不围棋 BCI 示例");
                ege::setfont(20, 0, L"微软雅黑"_ansi);
                ege::outtextxy(100, 140, L"by 谷雨");

                drawButton(L"新游戏", 100, 200, 300, 50);
                drawButton(L"读取存档", 100, 300, 300, 50);
                drawButton(L"退出", 100, 400, 300, 50);
                break;
            }
            case Page::Pause:
            case Page::Board: {
                ege::setfillcolor(EGERGB(200, 200, 64));
                ege::bar(50, 50, 450, 450);
                ege::setlinewidth(2);
                ege::setlinestyle(ege::SOLID_LINE);
                ege::setcolor(EGERGB(0, 0, 0));
                for (int i = 0; i < 9; i++) {
                    const int OFFSET = START_XY + i * GRID_WIDTH;
                    const int points[]{
                        START_XY,
                        OFFSET,
                        START_XY + 8 * GRID_WIDTH,
                        OFFSET,
                        OFFSET,
                        START_XY,
                        OFFSET,
                        START_XY + 8 * GRID_WIDTH,
                    };
                    ege::drawlines(2, points);
                }
                ege::setlinestyle(ege::NULL_LINE);
                for (int i = 0; i < 9; i++) {
                    for (int j = 0; j < 9; j++) {
                        if (!arr[i][j]) continue;
                        const int OFFSET_X = START_XY + i * GRID_WIDTH;
                        const int OFFSET_Y = START_XY + j * GRID_WIDTH;
                        ege::color_t color = arr[i][j] > 0
                                                 ? EGERGB(0, 0, 0)
                                                 : EGERGB(255, 255, 255);
                        ege::setfillcolor(color);
                        ege::fillellipse(OFFSET_X, OFFSET_Y, 20, 20);
                    }
                }
                drawButton(L"暂停", 0, 0, 50, 30);
                if (page == Page::Board) break;
                drawButton(L"暂停中", 200, 200, 100, 100);
            }
        }

        // 读取一个鼠标事件
        ege::mouse_msg msg;
        while (ege::mousemsg()) {
            msg = ege::getmouse();
        }
        if (firstMouse && msg.is_move()) {
            firstMouse = false;
        }

        // 针对不同的页面，处理不同的程序逻辑
        switch (page) {
            case Page::Menu: {
                if (!msg.is_up()) break;
                if (IN_BUTTON(msg, 100, 200, 300, 50) ||
                    IN_BUTTON(msg, 100, 300, 300, 50)) {
                    firstMouse = true;
                    page = Page::Board;
                } else if (IN_BUTTON(msg, 100, 400, 300, 50)) {
                    std::exit(0);
                }
                break;
            }
            case Page::Board: {
                if (firstMouse || !msg.is_up()) break;
                if (IN_BUTTON(msg, 0, 0, 50, 30)) {
                    page = Page::Pause;
                    break;
                }
                for (int i = 0; i < 9; i++) {
                    for (int j = 0; j < 9; j++) {
                        if (arr[i][j]) continue;
                        const int OFFSET_X =
                            START_XY + i * GRID_WIDTH - GRID_WIDTH / 2;
                        const int OFFSET_Y =
                            START_XY + j * GRID_WIDTH - GRID_WIDTH / 2;
                        if (IN_BUTTON(msg, OFFSET_X, OFFSET_Y, GRID_WIDTH,
                                      GRID_WIDTH)) {
                            arr[i][j] = black ? 1 : -1;
                            black ^= true;
                            goto end_of_pieces;
                        }
                    }
                }
                end_of_pieces:;
                break;
            }
            case Page::Pause: {
                if (!msg.is_up()) break;
                if (IN_BUTTON(msg, 200, 200, 100, 100)) {
                    page = Page::Board;
                }
                break;
            }
        }
    }
}
```
