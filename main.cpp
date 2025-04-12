#include <graphics.h>
#include <conio.h>
#include "pieces.h"
#include "board.h"

int main() {

    //初始化棋盘
    // 初始化图形窗口（宽度 = 边距*2 + 格子大小*19）
    initgraph(OFFSET * 2 + CELL_SIZE * (BOARD_SIZE - 1), OFFSET * 2 + CELL_SIZE * (BOARD_SIZE - 1));

    BeginBatchDraw(); // 开启双缓冲防止闪烁

    // 初始绘制
	DrawChessBoard(); // 先画棋盘
	DrawAllPieces();  // 再画棋子
    FlushBatchDraw();

    // 鼠标
    MOUSEMSG msg;
    while (true) {
        // 处理输入
        if (MouseHit()) {
            msg = GetMouseMsg();
            if (msg.uMsg == WM_LBUTTONDOWN) {
                int x, y;
                if (ScreenToBoard(msg.x, msg.y, x, y)) {
                    if (PlacePieces(x, y)) {
                        // 重绘界面
                        int screenX = OFFSET + x * CELL_SIZE;
                        int screenY = OFFSET + y * CELL_SIZE;

                        // 1.擦除旧区域
                        setbkcolor(RGB(220, 179, 92));
                        clearrectangle(screenX - CELL_SIZE / 2,
                            screenY - CELL_SIZE / 2,
                            screenX + CELL_SIZE / 2,
                            screenY + CELL_SIZE / 2);

                        // 2.重新绘制棋盘
                        DrawChessBoard();

                        // 3.重新绘制棋子
                        DrawPiece(x, y, g_board[x][y]);

                        // 4.刷新
                        FlushBatchDraw();
                    }
                }
            }
        }
        Sleep(10);
    }
    //_getch();
    closegraph();
    return 0;
}