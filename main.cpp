#include <graphics.h>
#include <conio.h>
#include "pieces.h"
#include "board.h"

int main() {
    // ��ʼ��ͼ�δ��ڣ���� = �߾�*2 + ���Ӵ�С*19��
    initgraph(OFFSET * 2 + CELL_SIZE * (BOARD_SIZE - 1), OFFSET * 2 + CELL_SIZE * (BOARD_SIZE - 1));

    //�������̱�����ɫ
    setbkcolor(RGB(220, 179, 92));
    cleardevice();

    // ������������
    DrawGrid();

    // ������λ
    DrawStarPoints();

    _getch();
    closegraph();
    return 0;
}