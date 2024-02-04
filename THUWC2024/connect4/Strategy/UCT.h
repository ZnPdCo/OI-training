/**
 * @file UCT.h 
 * @brief: 信心上限树算法
 * @version: 1.0 
 * @author: ZnPdCo
 * @date: 2024-01-28 12:42:45
 **/

#ifndef UCT_H_
#define UCT_H_
#include <vector>
#include <map>
#include <chrono>
#include "Board.h"
#include "Node.h"
#include "Point.h"

class UCT {
public:
	UCT(const int M, const int N);
	std::tuple<int, int, int> UCTSearch(const Board _board);
private:
	int m, n;
	int cnt;
	std::pair<int, Board> treePolicy(int u, Board _board);
	std::pair<int, Board> expand(int u,  Board _board);
	std::pair<int, int> bestChild(int u, double c, Board _board, bool check);
	void backup(int u, int delta);
	int defaultPolicy(int u, Board _board);
};

#endif // UCT_H_

