#include <graphics.h>
#include <conio.h>
#include "pieces.h"
#include "board.h"

int main() {

    //��ʼ������
    // ��ʼ��ͼ�δ��ڣ���� = �߾�*2 + ���Ӵ�С*19��
    initgraph(OFFSET * 2 + CELL_SIZE * (BOARD_SIZE - 1), OFFSET * 2 + CELL_SIZE * (BOARD_SIZE - 1));

    BeginBatchDraw(); // ����˫�����ֹ��˸

    // ��ʼ����
	DrawChessBoard(); // �Ȼ�����
	DrawAllPieces();  // �ٻ�����
    FlushBatchDraw();

    // ���
    MOUSEMSG msg;
    while (true) {
        // ��������
        if (MouseHit()) {
            msg = GetMouseMsg();
            if (msg.uMsg == WM_LBUTTONDOWN) {
                int x, y;
                if (ScreenToBoard(msg.x, msg.y, x, y)) {
                    if (PlacePieces(x, y)) {
                        // �ػ����
                        int screenX = OFFSET + x * CELL_SIZE;
                        int screenY = OFFSET + y * CELL_SIZE;

                        // 1.����������
                        setbkcolor(RGB(220, 179, 92));
                        clearrectangle(screenX - CELL_SIZE / 2,
                            screenY - CELL_SIZE / 2,
                            screenX + CELL_SIZE / 2,
                            screenY + CELL_SIZE / 2);

                        // 2.���»�������
                        DrawChessBoard();

                        // 3.���»�������
                        DrawPiece(x, y, g_board[x][y]);

                        // 4.ˢ��
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