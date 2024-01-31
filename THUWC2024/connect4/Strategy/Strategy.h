/**
 * @file Strategy.h 
 * @brief: 策略接口文件
 * @version: 1.0 
 * @author: 张永锋(zhangyf07@gmail.com), ZnPdCo
 * @date: 2024-01-28 11:29:29
 **/

#ifndef STRATEGY_H_
#define STRATEGY_H_

#include "Point.h"

extern "C" Point *getPoint(const int M, const int N, const int *top, const int *_board,
						   const int lastX, const int lastY, const int noX, const int noY);

extern "C" void clearPoint(Point *p);

#endif // STRATEGY_H_
