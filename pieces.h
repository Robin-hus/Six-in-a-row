#pragma once

#include <graphics.h>

const int BOARD_SIZE = 20; // 19*19的棋盘

const int CELL_SIZE = 30; // 每个格子30像素

const int OFFSET = 50; // 棋盘的边距

// 棋子半径（略小于格子的一半）
const int PIECE_RADIUS = CELL_SIZE * 0.4;

int g_board[BOARD_SIZE][BOARD_SIZE] = { 0 }; // 0为空，1为黑，2为白

int g_currentPlayer = BLACK; // 当前玩家

// 绘制单个棋子
void DrawPiece(int logicalX, int logicalY, int color) {
	// 将逻辑坐标转化为屏幕坐标
	int screenX = OFFSET + logicalX * CELL_SIZE;
	int screenY = OFFSET + logicalY * CELL_SIZE;

	// 设置颜色（尽量有立体感）
	if (color == 1) {
		setfillcolor(RGB(35, 35, 35)); //深黑
		setlinecolor(RGB(80, 80, 80)); // 边缘高光
	}
	else if(color == 2){
		setfillcolor(RGB(245, 245, 245)); // 米白
		setlinecolor(RGB(210, 210, 210)); // 边缘阴影
	}

	// 绘制带有边框的棋子
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

// 落子逻辑实现
bool PlacePieces(int logicalX, int logicalY) {
	// 检查X，Y是否合法。1.是否超出边界
	if (logicalX < 0 || logicalX >= BOARD_SIZE || logicalY < 0 || logicalY >= BOARD_SIZE)
		return false;

	// 检查X，Y是否合法。2.所选位置是否为空
	if (g_board[logicalX][logicalY] != 0)
		return false;

	// 检查完毕，更新棋盘状态
	g_board[logicalX][logicalY] = g_currentPlayer;

	// 切换玩家
	g_currentPlayer = (g_currentPlayer == 1) ? 2 : 1;

	return true;
}