/**
 * @file Board.h 
 * @brief: 棋盘类，判断双方胜负，平局，落子、判断列是否能落子
 * @version: 1.0 
 * @author: 张永锋(zhangyf07@gmail.com), ZnPdCo
 * @date: 2024-01-28 11:09:34
 **/

#ifndef BOARD_H_
#define BOARD_H_

class Board {
public:
	Board();
	Board(const int M, const int N, const int *_board, const int *_top,
	const int lastX, const int lastY, const int noX, const int noY);
	
	bool userWin(const int x, const int y);
	bool machineWin(const int x, const int y);
	bool userWin();
	bool machineWin();
	bool isTie();
	
	bool putPoint(const int y, const int color);
	bool isCanPut(const int y);

	void show();
	
	int lstx, lsty;
private:
	int m, n;
	short top[20];
	short board[20][20];
	int nox, noy;
};

#endif // BOARD_H_
