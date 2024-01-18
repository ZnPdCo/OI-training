/**
 * @file 移球游戏.cpp 
 * @tag: #GMOJ#构造#分治
 * @author: ZnPdCo
 * @date: 2024-01-18 20:43:55
 * @problem: https://gmoj.net/senior/#main/show/6924
 **/
#include <cstdio>
#include <vector>
using namespace std;
#define ll long long
#define N 60
#define M 410
#define debug false
ll n, m;
ll top[N];
ll num[N][M];	// 某一行某种颜色的个数
ll a[N][M];		// 给定的颜色分布
bool b[N][M];	// 黑白球规定


struct node {
	ll x, y;
} ans[820010];
ll cnt;


void show() {
	for(ll i = 1; i <= n+1; i++) {
		for(ll j = 1; j <= top[i]; j++) {
			printf("%lld ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void mov(ll x, ll y) {
	ans[++cnt].x = x;
	ans[cnt].y = y;
	
	a[y][++top[y]] = a[x][top[x]--];
	
	if(debug) show();
}

void fun(ll x, ll y, ll mid) {
	ll numx = 0, numy = 0;
	for(ll i = 1; i <= m; i++) {
		if(a[x][i] <= mid) numx++, b[x][i] = 1;
		else b[x][i] = 0;
		if(a[y][i] <= mid) numy++, b[y][i] = 1;
		else b[y][i] = 0;
	}
	
	// 1.如果太多黑球则取反
	if(numx + numy > m) {
		numx = m - numx, numy = m - numy;
		for(ll i = 1; i <= m; i++) b[x][i] ^= 1, b[y][i] ^= 1;
	}
	
	// 2.如果太少则添加虚拟黑球（把黑球放到y）
	for(ll i = 1; i <= m; i++) {
		if(!b[x][i] && numx + numy < m) {
			numx++;
			b[x][i] = 1;
		}
	}
	
	// 3.把y中的numx个取到n+1中
	if(debug) printf("把y中的numx个取到n+1中\n");
	for(ll i = 1; i <= numx; i++) {
		mov(y, n+1);
	}
	// 4.把x中的黑球放到y，白球放到n+1
	if(debug) printf("把x中的黑球放到y，白球放到n+1\n");
	for(ll i = 1; i <= m; i++) {
		if(b[x][top[x]]) {
			mov(x, y);
		} else {
			mov(x, n+1);
		}
	}
	// 5.把n+1中的m-numx个白球放回到x
	if(debug) printf("把n+1中的m-numx个白球放回到x\n");
	for(ll i = 1; i <= m-numx; i++) mov(n+1, x);
	
	// 6.把y中的numx个黑球放回到x（x现在前面是白球，后面是黑球）
	if(debug) printf("把y中的numx个黑球放回到x（x现在前面是白球，后面是黑球）\n");
	for(ll i = 1; i <= numx; i++) mov(y, x);
	
	// 7.把n+1中的numx放回到y（y现在不变）
	if(debug) printf("把n+1中的numx放回到y（y现在不变）\n");
	for(ll i = 1; i <= numx; i++) mov(n+1, y);
	
	// 8.把x中的numx个黑球放到n+1（x现在只有白球）
	if(debug) printf("把x中的numx个黑球放到n+1（x现在只有白球）\n");
	for(ll i = 1; i <= numx; i++) mov(x, n+1);
	
	// 9.把y中的黑球放到n+1，白球放到x
	if(debug) printf("把y中的黑球放到n+1，白球放到x\n");
	for(ll i = 1; i <= m; i++) {
		if(b[y][top[y]]) {
			mov(y, n+1);
		} else {
			mov(y, x);
		}
	}
	
	// 10.把n+1中的黑球放回y
	if(debug) printf("把n+1中的黑球放回y\n");
	for(ll i = 1; i <= m; i++) {
		mov(n+1, y);
	}
}

void solve(ll l, ll r) {
	if(debug) printf("===%lld %lld===\n", l, r);
	
	if(l == r) return;
	
	ll mid = (l + r) >> 1;
	vector<ll> now;
	for(ll i = 1; i <= n; i++) {
		if(l <= a[i][1] && a[i][1] <= r) {
			now.push_back(i);
		}
	}
	for(ll i = 0; i < now.size() - 1; i++) {
		fun(now[i], now[i+1], mid);
	}
	
	solve(l, mid);
	solve(mid+1, r);
}

int main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	
	scanf("%lld %lld", &n, &m);
	
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= m; j++) {
			scanf("%lld", &a[i][j]);
			num[i][a[i][j]]++;
		}
		top[i] = m;
	}
	
	solve(1, n);
	
	printf("%lld\n", cnt);
	for(ll i = 1; i <= cnt; i++) {
		printf("%lld %lld\n", ans[i].x, ans[i].y);
	}
	
//	show();
}
