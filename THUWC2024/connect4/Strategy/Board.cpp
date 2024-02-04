#include "Board.h"
#include <cstdio>

/**
 * @brief: 棋盘构造函数
 * @version: 1.0 
 * @param: M: 棋盘高
 *         N: 棋盘宽
 *         _board: 棋盘数组指针（main函数读入）
 *         _top: 棋盘剩余空间，根据文档说明，当棋盘一子未下，top=M，反之为top=0
 *         lastX, lastY: 上一次落子位置
 *         noX, noY: 不可落子位置
 * @author: 张永锋(zhangyf07@gmail.com)
 * @date: 2014-05
 **/
Board::Board() {}

Board::Board(const int M, const int N, const int *_board, const int *_top,
	const int lastX, const int lastY, const int noX, const int noY) {
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			board[i][j] = _board[i * N + j];
		}
	}
	for(int i = 0; i < N; i++) {
		top[i] = _top[i];
	}
	nox = noX, noy = noY;
	m = M, n = N;
	lstx = lastX, lsty = lastY;
}

/**
 * @brief: 判断用户（对方）是否胜利
 * @version: 1.0 
 * @param: x, y: 用户（对方）最后一次落子位置
 * @return: 用户（对方）是否胜利
 * @author: ZnPdCo
 * @date: 2024-01-28 11:37:49
 **/
bool Board::userWin(const int x, const int y) {
	if(x == -1 && y == -1) return false;
	//横向检测
	int i, j;
	int count = 0;
	for (i = y; i >= 0; i--)
		if (!(board[x][i] == 1))
			break;
	count += (y - i);
	for (i = y; i < n; i++)
		if (!(board[x][i] == 1))
			break;
	count += (i - y - 1);
	if (count >= 4)
		return true;
	
	//纵向检测
	count = 0;
	for (i = x; i < m; i++)
		if (!(board[i][y] == 1))
			break;
	count += (i - x);
	if (count >= 4)
		return true;
	
	//左下-右上
	count = 0;
	for (i = x, j = y; i < m && j >= 0; i++, j--)
		if (!(board[i][j] == 1))
			break;
	count += (y - j);
	for (i = x, j = y; i >= 0 && j < n; i--, j++)
		if (!(board[i][j] == 1))
			break;
	count += (j - y - 1);
	if (count >= 4)
		return true;
	
	//左上-右下
	count = 0;
	for (i = x, j = y; i >= 0 && j >= 0; i--, j--)
		if (!(board[i][j] == 1))
			break;
	count += (y - j);
	for (i = x, j = y; i < m && j < n; i++, j++)
		if (!(board[i][j] == 1))
			break;
	count += (j - y - 1);
	if (count >= 4)
		return true;
	
	return false;
}

bool Board::userWin()
{
	return userWin(lstx, lsty);
}


/**
 * @brief: 判断机器（自己）是否胜利
 * @version: 1.0 
 * @param: x, y: 机器（自己）最后一次落子位置
 * @return: 机器（自己）是否胜利
 * @author: 张永锋(zhangyf07@gmail.com)
 * @date: 2014-05
 **/
bool Board::machineWin(const int x, const int y)
{
	if(x == -1 && y == -1) return false;
	//横向检测
	int i, j;
	int count = 0;
	for (i = y; i >= 0; i--)
		if (!(board[x][i] == 2))
			break;
	count += (y - i);
	for (i = y; i < n; i++)
		if (!(board[x][i] == 2))
			break;
	count += (i - y - 1);
	if (count >= 4)
		return true;
	
	//纵向检测
	count = 0;
	for (i = x; i < m; i++)
		if (!(board[i][y] == 2))
			break;
	count += (i - x);
	if (count >= 4)
		return true;
	
	//左下-右上
	count = 0;
	for (i = x, j = y; i < m && j >= 0; i++, j--)
		if (!(board[i][j] == 2))
			break;
	count += (y - j);
	for (i = x, j = y; i >= 0 && j < n; i--, j++)
		if (!(board[i][j] == 2))
			break;
	count += (j - y - 1);
	if (count >= 4)
		return true;
	
	//左上-右下
	count = 0;
	for (i = x, j = y; i >= 0 && j >= 0; i--, j--)
		if (!(board[i][j] == 2))
			break;
	count += (y - j);
	for (i = x, j = y; i < m && j < n; i++, j++)
		if (!(board[i][j] == 2))
			break;
	count += (j - y - 1);
	if (count >= 4)
		return true;
	
	return false;
}


bool Board::machineWin()
{
	return machineWin(lstx, lsty);
}


/**
 * @brief: 判断局面是否平局
 * @version: 1.0 
 * @return: 局面是否平局
 * @author: ZnPdCo
 * @date: 2024-01-28 11:37:49
 **/
bool Board::isTie()
{
	bool tie = true;
	for (int i = 0; i < n; i++)
	{
		if (isCanPut(i))
		{
			tie = false;
			break;
		}
	}
	return tie;
}

/**
 * @brief: 在某一列放置棋子
 * @version: 1.0 
 * @param: y: 列数
 *         color: 颜色
 * @return: 放置是否成功
 * @author: ZnPdCo
 * @date: 2024-01-28 11:37:49
 **/
bool Board::putPoint(const int y, const int color) {
	if(!isCanPut(y)) return false;
	top[y]--;
	if(nox == top[y] && noy == y) {
		top[y]--;
	}
	board[top[y]][y] = color;
	lstx = top[y], lsty = y;
	return true;
}


/**
 * @brief: 判断某一列是否为空
 * @version: 1.0 
 * @param: y: 列数
 * @return: 该列是否为空
 * @author: ZnPdCo
 * @date: 2024-01-28 11:37:49
 **/
bool Board::isCanPut(const int y) {
	if(top[y] > 0 && !(top[y] == 1 && nox == 0 && noy == y)) return true;
	return false;
}

/**
 * @brief: debug 输出棋盘
 * @version: 1.0 
 * @author: ZnPdCo
 * @date: 2024-01-29 07:17:26
 **/
void Board::show() {
	char _[4] = ".BA";
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(nox == i && noy == j) printf("X ");
			else printf("%c ", _[board[i][j]]);
		}
		printf("\n");
	}

	printf("======\n");
}
