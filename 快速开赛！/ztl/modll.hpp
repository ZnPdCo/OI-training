#ifndef ZTL_MODLL_HPP
#define ZTL_MODLL_HPP 1

#include <cstdio>
#include <iostream>
#include "definition.hpp"

namespace ztl {
	template<const unsigned _Mod = LLONG_MAX>
	class modll {
		protected:
			ll _val;
			typedef modll<_Mod> _mll;
			friend inline _mll
			__construct(_mll&& _res, ll _x) {
				_res._val = _x;
				return _res;
			}
			template<class _Tp>friend _mll
			__quickly_power(_mll _a, _Tp _b) {
				if (_b <= 0)return 1;
				_mll _res = 1;
				for (; (bool)_b; _b >>= 1, _a *= _a)if (_b & 1)_res *= _a;
				return _res;
			}
		public:
			modll(): _val(0) {}
			template<class _Tp>modll(_Tp _x) {
				_val = ((ll)_x % _Mod + _Mod) % _Mod;
			}
			template<class _Tp>explicit inline operator _Tp() {
				return (_Tp)_val;
			}

			friend _mll operator+(const _mll& _a, const _mll& _b) {
				if (_a._val + _b._val >= _Mod)return __construct(_mll(), _a._val + _b._val - _Mod);
				return __construct(_mll(), _a._val + _b._val);
			}
			inline _mll& operator+=(const _mll& _b) {
				return *this = *this + _b;
			}
			inline _mll& operator++() {
				return *this = *this + __construct(_mll(), 1);
			}
			inline _mll& operator++(int) {
				_mll _res = *this;
				*this = *this + __construct(_mll(), 1);
				return _res;
			}//plus
			friend _mll operator-(const _mll& _a, const _mll& _b) {
				if (_a._val - _b._val < 0)return __construct(_mll(), _a._val - _b._val + _Mod);
				return __construct(_mll(), _a._val - _b._val);
			}
			inline _mll& operator-=(const _mll& _b) {
				return *this = *this - _b;
			}
			inline _mll& operator--() {
				return *this = *this - __construct(_mll(), 1);
			}
			inline _mll& operator--(int) {
				_mll _res = *this;
				*this = *this - __construct(_mll(), 1);
				return _res;
			}//minus
			friend inline _mll
			operator*(const _mll& _a, const _mll& _b) {
				return __construct(_mll(), _a._val * _b._val % _Mod);
			}
			inline _mll& operator*=(const _mll& _b) {
				return *this = *this * _b;   //multiplies
			}
			_mll operator-() {
				return __construct(_mll(), _val ? _Mod - _val : _val);   //negative
			}
			friend inline _mll
			operator%(const _mll& _a, const _mll& _b) {
				return __construct(_mll(), _a._val % _b._val);
			}
			inline _mll& operator%=(const _mll& _b) {
				return *this = *this % _b;   //modulus
			}

			friend inline bool
			operator==(const _mll& _a, const _mll& _b) {
				return _a._val == _b._val;
			}
			friend inline bool
			operator!=(const _mll& _a, const _mll& _b) {
				return _a._val != _b._val;
			}
			friend inline bool
			operator<(const _mll& _a, const _mll& _b) {
				return _a._val < _b._val;
			}
			friend inline bool
			operator>(const _mll& _a, const _mll& _b) {
				return _a._val > _b._val;
			}
			friend inline bool
			operator<=(const _mll& _a, const _mll& _b) {
				return _a._val <= _b._val;
			}
			friend inline bool
			operator>=(const _mll& _a, const _mll& _b) {
				return _a._val >= _b._val;
			}

			friend inline _mll
			operator&(const _mll& _a, const _mll& _b) {
				return _a._val & _b._val;
			}
			inline _mll& operator&=(const _mll& _b) {
				return *this = *this & _b;
			}
			friend inline _mll
			operator|(const _mll& _a, const _mll& _b) {
				return _a._val | _b._val;
			}
			inline _mll& operator|=(const _mll& _b) {
				return *this = *this | _b;
			}
			friend inline _mll
			operator^(const _mll& _a, const _mll& _b) {
				return _a._val ^ _b._val;
			}
			inline _mll& operator^=(const _mll& _b) {
				return *this = *this ^ _b;
			}
			friend inline _mll
			operator<<(const _mll& _a, const _mll& _b) {
				return _a._val << _b._val;
			}
			inline _mll& operator<<=(const _mll& _b) {
				return *this = *this << _b;
			}
			friend inline _mll
			operator>>(const _mll& _a, const _mll& _b) {
				return _a._val >> _b._val;
			}
			inline _mll& operator>>=(const _mll& _b) {
				return *this = *this >> _b;
			}
			inline _mll operator~()const {
				return __construct(_mll(), ~_val);
			}
			inline bool  operator!()const {
				return !_val;
			}

			friend inline std::istream&
			operator>>(std::istream& _is, _mll& _b) {
				return _is >> _b._val;
			}
			friend inline std::ostream&
			operator<<(std::ostream& _os, const _mll& _b) {
				return _os << _b._val;
			}

			template<class _Tp>_mll
			power(_Tp _n)const {
				return __quickly_power(*this, _n);
			}
			inline _mll inv()const {
				return __quickly_power(*this, _Mod - 2);
			}

			friend inline _mll
			operator/(const _mll& _a, const _mll& _b) {
				return __construct(_mll(), _a._val * _b.inv()._val % _Mod);
			}
			inline _mll& operator/=(const _mll& _b) {
				return *this = *this / _b;
			}
	};
}

#endif
