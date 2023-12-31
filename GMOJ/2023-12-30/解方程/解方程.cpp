/**
 * @file 解方程.cpp 
 * @tag: #GMOJ#玄学
 * @author: ZnPdCo
 * @date: 2023-12-30 14:27:22
 * @problem: https://gmoj.net/senior/#main/show/3935
 **/
#include <cstdio>
#include <random>
#include <ctime>
#include <algorithm>
using namespace std;
#define ll long long
#define N 110
#define P 998244353
mt19937 rnd(time(0));
ll n, m;
ll a[N];
bool ismx;
ll ans[N], cnt;

ll read() {
	ll x=0, flag = 0;
	char c = '.';
	while((c < '0' || c > '9') && c != '-') c = getchar();
	if(c == '-') flag = 1, c = getchar();
	while(c >= '0' && c <= '9') {
		x = ((x<<1)%P + (x<<3)%P + (c^'0')) % P;
		c = getchar();
	}
	if(flag) x = (-x % P + P) % P;
	return x;
}

void output() {
	printf("%lld\n", cnt);
	for(ll i = 1; i <= cnt; i++) {
		printf("%lld\n", ans[i]);
	}
}
int main() {
	n = read(), m = read();
	for(ll i = 0; i <= n; i++) {
		a[i] = read();
	}
	for(ll i = 1; i <= m; i++) {
		ll sum = 0, xc = 1;
		for(ll j = 0; j <= n; j++) {
			(sum += a[j] * xc % P) %= P;
			(xc *= i) %= P;
		}
		if(sum == 0) ans[++cnt] = i;
	}
	output();
}
