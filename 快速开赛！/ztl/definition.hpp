#ifndef ZTL_DEFINITION_HPP
#define ZTL_DEFINITION_HPP 1

namespace ztl {
	using ll = long long;

	template<typename T>
	inline T ls(T x) {
		return x << 1;
	}

	template<typename T>
	inline T rs(T x) {
		return x << 1 | 1;
	}
}

#endif
