/**
 * @file Node.h 
 * @brief: UCT树节点类
 * @version: 1.0 
 * @author: ZnPdCo
 * @date: 2024-01-28 13:52:04
 * 
 **/

#include <vector>
#include "Board.h"

#ifndef NODE_H_
#define NODE_H_

class Node {
public:
	int opt;				// 记录落子位置（减少棋盘状态占用）
	int fa, color;			// fa: 父亲节点编号, color: 节点颜色（1/2）
	int Q, N;				// Q: 总价值, N: 总次数
	std::vector<int> son;	// 访问过的儿子
	std::vector<int> can;	// 未访问过的儿子

	Node(int _opt=0, int _fa=0, int _color=0, int _Q=0, int _N=0) {
		opt = _opt, fa = _fa, color = _color, Q = _Q, N = _N;
		son.clear(), can.clear();
	}
};

#endif
