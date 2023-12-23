/**
 * @file P3803 【模板】多项式乘法（FFT）（无递归版）.cpp
 * @tag: #洛谷#FFT
 * @author: ZnPdCo
 * @date: 2023-12-23 18:48:45
 * @problem: https://www.luogu.com.cn/problem/P3803
 **/
#include <cstdio>
#include <cmath>
#include <iostream>
#define N 10000010
#define ll long long
using namespace std;
struct complex {
	//   实部 虚部 
	double x, y;
	complex (double xx=0, double yy=0) {x=xx, y=yy;}
	friend complex operator +(const complex &a, const complex &b) {return complex(a.x+b.x, a.y+b.y);}
	friend complex operator -(const complex &a, const complex &b) {return complex(a.x-b.x, a.y-b.y);}
	friend complex operator *(const complex &a, const complex &b) {return complex(a.x*b.x-a.y*b.y, a.x*b.y+b.x*a.y);}
} f[N], g[N];
const double PI = acos(-1);
ll siz = 1;

ll l, r[N];

void FFT(complex *a, ll type) {
	for(ll i = 0; i < siz; i++) {
		if(i < r[i]) swap(a[i], a[r[i]]);
	} 
	for(ll x = 2; x <= siz; x <<= 1) {
		complex wn = complex(cos(2 * PI / x), type * sin(2 * PI / x));
		for(ll i = 0; i < siz; i += x) {
			complex w = complex(1, 0);
			for(ll j = 0; j < (x >> 1); j++, w = w*wn) {
				complex A = a[i+j], B = a[i+(x>>1)+j];
				a[i+j] = A + w * B;
				a[i+(x>>1)+j] = A - w * B;
			}
		}
	}
}
ll n, m;
int main() {
	scanf("%lld %lld", &n, &m);
	for(ll i = 0; i <= n; i++) {
		scanf("%lf", &f[i].x);
	}
	for(ll i = 0; i <= m; i++) {
		scanf("%lf", &g[i].x);
	}
	while(siz <= n+m) siz <<= 1, l++;
	for(ll i = 0; i < siz; i++) {
		r[i] = (r[i>>1] >> 1) | ((i & 1) << (l-1));
	}
	FFT(f, 1);
	FFT(g, 1);
	for(ll i = 0; i <= siz; i++) {
		f[i] = f[i] * g[i];
	}
	FFT(f, -1);
	for(ll i = 0; i <= n+m; i++) {
		printf("%lld ", (ll)(f[i].x / siz + 0.5));
	}
	return 0;
} 
