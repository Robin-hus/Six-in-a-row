#pragma once
#include <graphics.h>

// ���̲���
const int BOARD_SIZE = 20; // 19*19������

const int CELL_SIZE = 30; // ÿ������30����

const int OFFSET = 50; // ���̵ı߾�

// ������������
void DrawGrid() {
    setlinecolor(BLACK); // ����������ɫ
    setlinestyle(PS_SOLID, 1); //�����������Ϊ 1px

    // ���ƺ�������
    for (int i = 0; i < BOARD_SIZE; ++i) {
        int y = OFFSET + i * CELL_SIZE;
        line(OFFSET, y, OFFSET + CELL_SIZE * (BOARD_SIZE - 1), y);
    }

    // ������������
    for (int i = 0; i < BOARD_SIZE; ++i) {
        int x = OFFSET + i * CELL_SIZE;
        line(x, OFFSET, x, OFFSET + CELL_SIZE * (BOARD_SIZE - 1));
    }
}

// ������λ
void DrawStarPoints() {
    // ��λ�����б������ϵĹؼ��㣩
    POINT stars[] = {
        {3, 3}, {3, 9}, {3, 15},
        {9, 3}, {9, 9}, {9, 15}, // ������Ԫ��(9,9)
        {15,3}, {15,9}, {15,15}
    };

    setfillcolor(BLACK); // �����ǵ���ɫ
    for (auto& p : stars) {
        // ת���߼����굽��Ļ����
        int x = OFFSET + p.x * CELL_SIZE;
        int y = OFFSET + p.y * CELL_SIZE;
        fillcircle(x, y, 3); // ���ư뾶3px��ʵ��Բ
    }
}