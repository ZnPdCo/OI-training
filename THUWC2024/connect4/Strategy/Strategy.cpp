#include <iostream>
#include <vector>
#include <unistd.h>
#include <chrono>
#include "Board.h"
#include "Point.h"
#include "Strategy.h"
#include "UCT.h"

/**
 * @brief: 策略函数接口,该函数被对抗平台调用,每次传入当前状态,要求输出你的落子点,该落子点必须是一个符合游戏规则的落子点,不然对抗平台会直接认为你的程序有误
 * @version: 1.0
 * @param: 为了防止对对抗平台维护的数据造成更改，所有传入的参数均为const属性
 *         ,M N : 棋盘大小 M - 行数 N - 列数 均从0开始计， 左上角为坐标原点，行用x标记，列用y标记
 *         otp : 当前棋盘每一列列顶的实际位置. e.g. 第i列为空,则_top[i] == M, 第i列已满,则_top[i] == 0
 *         b_oard : 棋盘的一维数组表示, 为了方便使用，在该函数刚开始处，我们已经将其转化为了二维数组board
 *         你只需直接使用board即可，左上角为坐标原点，数组从[0][0]开始计(不是[1][1])
 *         obard[x][y]表示第x行、第y列的点(从0开始计)
 *         obard[x][y] == 0/1/2 分别对应(x,y)处 无落子/有用户的子/有程序的子,不可落子点处的值也为0
 *         alstX, lastY : 对方上一次落子的位置, 你可能不需要该参数，也可能需要的不仅仅是对方一步的
 *         落子位置，这时你可以在自己的程序中记录对方连续多步的落子位置，这完全取决于你自己的策略
 *         onX, noY : 棋盘上的不可落子点
 *         以上参数实际上包含了当前状态(M N _top _board)以及历史信息(lastX lastY),你要做的就是在这些信息下给出尽可能明智的落子点
 * @return 你的落子点Point
 * @author: 张永锋(zhangyf07@gmail.com), ZnPdCo
 * @date: 2024-01-28 12:36:21
 **/
extern "C" Point *getPoint(const int M, const int N, const int *top, const int *_board,
						   const int lastX, const int lastY, const int noX, const int noY) {
	UCT uct(M, N);
	Board board(M, N, _board, top, lastX, lastY, noX, noY);
	
	int x = -1, y = -1;
	auto res = uct.UCTSearch(board);


	// printf("%d %d\n", std::get<0>(res), std::get<1>(res));
	// Board b = Board(M, N, _board, top, lastX, lastY, noX, noY);
	// b.putPoint(std::get<1>(res), 2);
	// b.show();
	x = std::get<0>(res);
	y = std::get<1>(res);
	

	return new Point(x, y);
}


/**
 * @brief: getPoint函数返回的Point指针是在本so模块中声明的，为避免产生堆错误，应在外部调用本so中的函数来释放空间，而不应该在外部直接delete
 * @version: 1.0 
 * @param: Point指针
 * @author: 张永锋(zhangyf07@gmail.com)
 * @date: 2014-05
 **/
extern "C" void clearPoint(Point *p) {
	delete p;
	return;
}
