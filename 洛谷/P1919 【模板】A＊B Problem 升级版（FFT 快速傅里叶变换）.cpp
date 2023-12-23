/**
 * @file P1919 【模板】A＊B Problem 升级版（FFT 快速傅里叶变换）.cpp
 * @tag: #洛谷#FFT
 * @author: ZnPdCo
 * @date: 2023-12-23 18:52:10
 * @problem: https://www.luogu.com.cn/problem/P1919
 **/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ll long long
#define N 4000010
using namespace std;
char s[N];
struct complex {
	double x, y;
	complex(double xx=0, double yy=0) {x=xx, y=yy;}
	friend complex operator+(const complex &a, const complex &b) {return complex(a.x+b.x, a.y+b.y);}
	friend complex operator-(const complex &a, const complex &b) {return complex(a.x-b.x, a.y-b.y);}
	friend complex operator*(const complex &a, const complex &b) {return complex(a.x*b.x-a.y*b.y, a.x*b.y+a.y*b.x);}
} f[N], g[N];
ll ans[N];
ll l, r[N];
ll n, m, siz = 1;
const double PI = acos(-1);

void FFT(complex *a, ll type) {
	for(ll i = 0; i < siz; i++) {
		if(i < r[i]) swap(a[i], a[r[i]]);
	}
	
	for(ll x = 2; x <= siz; x <<= 1) {
		complex wn(cos(2 * PI / x), type * sin(2 * PI / x));
		for(ll i = 0; i < siz; i += x) {
			complex w(1, 0);
			for(ll j = 0; j < (x>>1); j++, w = w * wn) {
				complex A = a[i + j], B = a[i + (x>>1) + j];
				a[i + j] = A + w * B;
				a[i + (x>>1) + j] = A - w * B;
			}
		}
	}
}

int main() {
	scanf("%s", s);
	n = strlen(s);
	for(ll i = 0; i < n; i++) f[i].x = s[n-i-1] - '0';
	scanf("%s", s);
	m = strlen(s);
	for(ll i = 0; i < m; i++) g[i].x = s[m-i-1] - '0';
	while(siz <= n+m) siz <<= 1, l++;
	for(ll i = 0; i < siz; i++) {
		r[i] = (r[i>>1] >> 1) | ((i & 1) << (l-1));
	}
	FFT(f, 1);
	FFT(g, 1);
	for(ll i = 0; i < siz; i++) {
		f[i] = f[i] * g[i];
	}
	FFT(f, -1);
	bool flag = true;
	for(ll i = 0; i <= 2*n+2*m; i++) {
		ans[i] += (ll)(f[i].x / siz + 0.5);
		ans[i+1] += ans[i] / 10;
		ans[i] %= 10;
	}
	for(ll i = 2*n+2*m; i >= 0; i--) {
		if(ans[i] || !flag) {
			flag = false;
			printf("%lld", ans[i]);
		}
	}
}
