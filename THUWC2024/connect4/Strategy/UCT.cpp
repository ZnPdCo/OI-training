#include <cmath>
#include <random>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include "UCT.h"
#include "Board.h"
#include "Node.h"
#include "Point.h"
#define C 1

std::mt19937 rnd(time(0));
Node node[1500000];

/**
 * @brief: UCT构造函数
 * @version: 1.0 
 * @param: M: 棋盘高度
 *         N: 棋盘宽度
 *         _start: 时间辍
 * @author: ZnPdCo
 * @date: 2024-01-28 13:18:06
 **/
UCT::UCT(const int M, const int N) {
	m = M, n = N;
}

/**
 * @brief: UCT函数
 * @version: 1.0 
 * @param: _board: 棋盘Board
 * @return: 最优的位置与价值
 * @author: ZnPdCo
 * @date: 2024-01-28 13:18:06
 **/
std::tuple<int, int, int> UCT::UCTSearch(const Board _board) {
	auto start = std::chrono::high_resolution_clock::now();

	for(int i = 0; i < n; i++) {
		Board board = _board;
		if(board.isCanPut(i)) {
			board.putPoint(i, 2);
			if(board.machineWin()) return std::make_tuple(board.lstx, board.lsty, 1e9); 
		}
	}


	for(int i = 1; i < 600000; i++) {
		node[i].can.clear(), node[i].son.clear();
		node[i].color = node[i].fa = node[i].N = node[i].Q = 0;
	}
	cnt = 0;

	Board board = _board;

	node[++cnt].opt = -1;
	node[cnt].color = 1;

	for(int i = 0; i < n; i++) {
		if(board.isCanPut(i))
			node[cnt].can.push_back(i);
	}

	std::shuffle(node[cnt].can.begin(), node[cnt].can.end(), rnd);

	while(cnt < 1400000) {
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> tm = end - start;
		if(tm.count() > 2500) break;
		auto res = treePolicy(1, board);
		int delta = defaultPolicy(res.first, res.second);
		backup(res.first, delta);
	}

	auto res = bestChild(1, C, board, 1);


	int v = res.first;

	board.putPoint(node[v].opt, node[v].color);
	

	return std::make_tuple(board.lstx, board.lsty, res.second); 
}

/**
 * @brief: UCT搜索函数
 * @version: 1.0 
 * @param: u: 节点编号
 *         _board: 初始棋盘
 * @return: 最后选择的节点编号，棋盘
 * @author: ZnPdCo
 * @date: 2024-01-28 13:18:06
 **/
std::pair<int, Board> UCT::treePolicy(int u, Board _board) {
	Board board = _board;
	while(true) {
		if(board.userWin()) {
			return std::make_pair(u, board);
		} else if(board.machineWin()) {
			return std::make_pair(u, board);
		} else if(board.isTie()) {
			return std::make_pair(u, board);
		}
		
		if(!node[u].can.empty()) {
			return expand(u, board);
		} else {
			u = bestChild(u, C, board, 0).first;
			board.putPoint(node[u].opt, node[u].color);
		}
	}
}

/**
 * @brief: UCT拓展函数
 * @version: 1.0 
 * @param: u: 节点编号
 *         _board: 
 * @return: 拓展后的节点编号，棋盘
 * @author: ZnPdCo
 * @date: 2024-01-28 13:18:06
 **/
std::pair<int, Board> UCT::expand(int u, Board _board) {
	int y = node[u].can.back();
	node[u].can.pop_back();
	int color = node[u].color ^ 3;	// 1^3=2,2^3=1
	
	Board board = _board;
	board.putPoint(y, color);

	int v = ++cnt;
	node[v].opt = y;
	node[v].fa = u;
	node[v].color = color;
	for(int i = 0; i < n; i++) {
		if(board.isCanPut(i)) {
			node[v].can.push_back(i);
		}
	}
	std::shuffle(node[v].can.begin(), node[v].can.end(), rnd);
	node[u].son.push_back(v);
	return std::make_pair(v, board);
}

/**
 * @brief: UCT选择最好的子节点函数
 * @version: 1.0 
 * @param: u: 节点编号
 *         check: 是否暴力检查未来两步
 *         _board:
 * @return: 最好的子节点编号与价值
 * @author: ZnPdCo
 * @date: 2024-01-28 13:18:06
 **/
std::pair<int, int> UCT::bestChild(int u, double c, Board _board, bool check) {
	long double mx = -1e9;
	int pos = 0;
	for(int v : node[u].son) {
		double num = (long long)(node[v].Q) * 1.0 / (long long)(node[v].N) + c * sqrt((long long)(2*log(node[u].N))/(long long)(node[v].N));
		if(check) {
			for(int i = 0; i < n; i++) {
				Board board = _board;
				board.putPoint(node[v].opt, node[v].color);
				board.putPoint(i, node[v].color ^ 3);
				if(board.userWin()) num = -1e9;
			}
		}
		if(num > mx) {
			mx = num;
			pos = v;
		}
	}
	return std::make_pair(pos, mx);
}

/**
 * @brief: UCT回传函数
 * @version: 1.0 
 * @param: u: 节点编号
 * @author: ZnPdCo
 * @date: 2024-01-28 13:18:06
 **/
void UCT::backup(int u, int delta) {
	while(u) {
		node[u].N ++;
		node[u].Q += delta;
		delta *= -1;
		u = node[u].fa;
	}
}

/**
 * @brief: UCT随机拓展
 * @version: 1.0 
 * @param: u: 节点编号
 * @return: 代价
 * @author: ZnPdCo
 * @date: 2024-01-28 13:18:06
 **/
int UCT::defaultPolicy(int u, Board _board) {
	Board board = _board;
	int color = node[u].color;
	std::vector<int> can;
	while(true) {
		if(board.userWin()) {
			if(node[u].color == 1) return 3;
			if(node[u].color == 2) return -3;
		} else if(board.machineWin()) {
			if(node[u].color == 1) return -1;
			if(node[u].color == 2) return 1;
		} else if(board.isTie()) {
			return 0;
		}
		
		can.clear();
		for(int i = 0; i < n; i++) {
			if(board.isCanPut(i)) {
				can.push_back(i);
			}
		}
		int y = can[rnd() % can.size()];
		
		color ^= 3;
		board.putPoint(y, color);
	}
}