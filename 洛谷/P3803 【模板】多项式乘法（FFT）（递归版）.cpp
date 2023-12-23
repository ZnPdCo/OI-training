/**
 * @file P3803 【模板】多项式乘法（FFT）（递归版）.cpp
 * @tag: #洛谷#FFT
 * @author: ZnPdCo
 * @date: 2023-12-23 18:49:31
 * @problem: https://www.luogu.com.cn/problem/P3803
 **/
#include <cstdio>
#include <cmath>
#define N 1000010
#define ll long long
struct complex {
	//   实部 虚部 
	double x, y;
	complex (double xx=0, double yy=0) {x=xx, y=yy;}
	friend complex operator +(const complex &a, const complex &b) {return complex(a.x+b.x, a.y+b.y);}
	friend complex operator -(const complex &a, const complex &b) {return complex(a.x-b.x, a.y-b.y);}
	friend complex operator *(const complex &a, const complex &b) {return complex(a.x*b.x-a.y*b.y, a.x*b.y+b.x*a.y);}
} f[N], g[N];
const double PI = acos(-1);

void FFT(ll x, complex *a, ll type) {
	if(x == 1) return;
	complex a1[x>>1], a2[x>>1];
	for(ll i = 0; i < x; i+=2) {
		a1[i>>1] = a[i];
		a2[i>>1] = a[i+1];
	}
	FFT(x>>1, a1, type);
	FFT(x>>1, a2, type);
	complex wn = complex(cos(2 * PI / x), type * sin(2 * PI / x)), w = complex(1, 0);
	for(ll i = 0; i < (x>>1); i++, w = w*wn) {
		a[i] = a1[i] + w * a2[i];
		a[i+(x>>1)] = a1[i] - w * a2[i];
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
	ll siz = 1;
	while(siz <= n+m) siz <<= 1;
	FFT(siz, f, 1);
	FFT(siz, g, 1);
	for(ll i = 0; i <= siz; i++) {
		f[i] = f[i] * g[i];
	}
	FFT(siz, f, -1);
	for(ll i = 0; i <= n+m; i++) {
		printf("%lld ", (ll)(f[i].x / siz + 0.5));
	}
	return 0;
} 
