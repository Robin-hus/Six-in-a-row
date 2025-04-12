#pragma once

#include <graphics.h>

const int BOARD_SIZE = 20; // 19*19������

const int CELL_SIZE = 30; // ÿ������30����

const int OFFSET = 50; // ���̵ı߾�

// ���Ӱ뾶����С�ڸ��ӵ�һ�룩
const int PIECE_RADIUS = CELL_SIZE * 0.4;

int g_board[BOARD_SIZE][BOARD_SIZE] = { 0 }; // 0Ϊ�գ�1Ϊ�ڣ�2Ϊ��

int g_currentPlayer = BLACK; // ��ǰ���

// ���Ƶ�������
void DrawPiece(int logicalX, int logicalY, int color) {
	// ���߼�����ת��Ϊ��Ļ����
	int screenX = OFFSET + logicalX * CELL_SIZE;
	int screenY = OFFSET + logicalY * CELL_SIZE;

	// ������ɫ������������У�
	if (color == 1) {
		setfillcolor(RGB(35, 35, 35)); //���
		setlinecolor(RGB(80, 80, 80)); // ��Ե�߹�
	}
	else if(color == 2){
		setfillcolor(RGB(245, 245, 245)); // �װ�
		setlinecolor(RGB(210, 210, 210)); // ��Ե��Ӱ
	}

	// ���ƴ��б߿������
	setlinestyle(PS_SOLID, 2);
	fillcircle(screenX, screenY, PIECE_RADIUS);
	circle(screenX, screenY, PIECE_RADIUS);
}

void DrawAllPieces() {
	for (int y = 0; y < BOARD_SIZE; ++y) {
		for(int x = 0; x < BOARD_SIZE; ++x) {
			if (g_board[x][y] != 0) {
				DrawPiece(x, y, g_board[x][y]);
			}
		}
	}
}

// �����߼�ʵ��
bool PlacePieces(int logicalX, int logicalY) {
	// ���X��Y�Ƿ�Ϸ���1.�Ƿ񳬳��߽�
	if (logicalX < 0 || logicalX >= BOARD_SIZE || logicalY < 0 || logicalY >= BOARD_SIZE)
		return false;

	// ���X��Y�Ƿ�Ϸ���2.��ѡλ���Ƿ�Ϊ��
	if (g_board[logicalX][logicalY] != 0)
		return false;

	// �����ϣ���������״̬
	g_board[logicalX][logicalY] = g_currentPlayer;

	// �л����
	g_currentPlayer = (g_currentPlayer == 1) ? 2 : 1;

	return true;
}