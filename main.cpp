#include <graphics.h>
#include <conio.h>
#include "pieces.h"
#include "board.h"

int main() {
    // 初始化图形窗口（宽度 = 边距*2 + 格子大小*19）
    initgraph(OFFSET * 2 + CELL_SIZE * (BOARD_SIZE - 1), OFFSET * 2 + CELL_SIZE * (BOARD_SIZE - 1));

    //设置棋盘背景颜色
    setbkcolor(RGB(220, 179, 92));
    cleardevice();

    // 绘制棋盘网格
    DrawGrid();

    // 绘制星位
    DrawStarPoints();

    _getch();
    closegraph();
    return 0;
}