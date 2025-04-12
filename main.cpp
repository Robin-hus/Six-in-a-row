#include <graphics.h>
#include <conio.h>
#include "pieces.h"

// 棋盘参数
//const int BOARD_SIZE = 20; // 19*19的棋盘
//const int CELL_SIZE = 30; // 每个格子30像素
//const int OFFSET = 50; // 棋盘的边距

//int g_board[BOARD_SIZE][BOARD_SIZE] = { 0 }; // 0为空，1为黑，2为白
//int g_currentPlayer = BLACK; // 当前玩家

// 绘制棋盘网格
void DrawGrid() {
    setlinecolor(BLACK); // 设置线条颜色
    setlinestyle(PS_SOLID, 1); //设置线条宽度为 1px

    // 绘制横向线条
    for (int i = 0; i < BOARD_SIZE; ++i) {
        int y = OFFSET + i * CELL_SIZE;
        line(OFFSET, y, OFFSET + CELL_SIZE * (BOARD_SIZE - 1), y);
    }

    // 绘制纵向线条
    for (int i = 0; i < BOARD_SIZE; ++i) {
        int x = OFFSET + i * CELL_SIZE;
        line(x, OFFSET, x, OFFSET + CELL_SIZE * (BOARD_SIZE - 1));
    }
}

// 绘制星位
void DrawStarPoints() {
    // 星位坐标列表（棋盘上的关键点）
    POINT stars[] = {
        {3, 3}, {3, 9}, {3, 15},
        {9, 3}, {9, 9}, {9, 15}, // 中央天元在(9,9)
        {15,3}, {15,9}, {15,15}
    };

    setfillcolor(BLACK); // 设置星点颜色
    for (auto& p : stars) {
        // 转换逻辑坐标到屏幕坐标
        int x = OFFSET + p.x * CELL_SIZE;
        int y = OFFSET + p.y * CELL_SIZE;
        fillcircle(x, y, 3); // 绘制半径3px的实心圆
    }
}

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

    //// 测试棋子
    //g_board[1][1] = 1;
    //g_board[10][10] = 2;
    //DrawAllPieces();
    _getch();
    closegraph();
    return 0;
}