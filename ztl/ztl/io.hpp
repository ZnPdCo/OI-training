#ifndef ZTL_IO_HPP
#define ZTL_IO_HPP 1

#include <iostream>
#include "definition.hpp"

namespace ztl {
	void print() {}

	template<typename T, typename... Ts>
	void print(const T& x, const Ts&... y) {
		std::cout << x << ' ';
		print(y...);
	}

	void input() {}

	template<typename T, typename... Ts>
	void input(T& x, Ts&... y) {
		std::cin >> x;
		input(y...);
	}
}

#endif
