/**
 * @file 飞扬的小鸟.cpp 
 * @tag: #GMOJ#dp
 * @author: ZnPdCo
 * @date: 2023-12-30 14:27:53
 * @problem: https://gmoj.net/senior/#main/show/3932
 **/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define N 10010
using namespace std;
ll n, m, k, ans2;
ll x[N], y[N];
ll f[2][N];
struct node {
	ll p, h, l;
} a[N];
ll pos = 1;
bool cmp(node x, node y) {
	return x.p < y.p;
}
int main() {
	scanf("%lld %lld %lld", &n, &m, &k);
	for(ll i = 1; i <= n; i++) {
		scanf("%lld %lld", &x[i], &y[i]);
	}
	for(ll i = 1; i <= k; i++) {
		scanf("%lld %lld %lld", &a[i].p, &a[i].l, &a[i].h);
	}
	sort(a+1, a+1+k, cmp);
	for(ll i = 1; i <= n; i++) {
		for(ll j = 0; j <= m; j++) f[i%2][j] = 1e15;
		for(ll j = x[i]+1; j < m; j++) {
			f[i%2][j] = min(f[i%2][j], min(f[(i-1)%2][j-x[i]], f[i%2][j-x[i]]) + 1);
		}
		for(ll j = m - x[i]; j <= m; j++) {
			f[i%2][m] = min(f[i%2][m], min(f[(i-1)%2][j], f[i%2][j]) + 1);
		}
		for(ll j = 0; j <= m - y[i]; j++) {
			f[i%2][j] = min(f[i%2][j], f[(i-1)%2][j+y[i]]);
		}
//		for(ll j = 0; j <= m; j++) printf("f[%lld][%lld]=%lld\n", i, j, f[i%2][j]);
		if(pos <= k && a[pos].p == i) {
			for(ll j = 0; j <= a[pos].l; j++) f[i%2][j] = 1e15;
			for(ll j = a[pos].h; j <= m; j++) f[i%2][j] = 1e15;
			for(ll j = 0; j <= m; j++) {
				if(f[i%2][j] != 1e15) {
					ans2 = max(ans2, pos);
				}
			}
			pos++;
		}
	}
	ll ans = 1e15;
	for(ll i = 1; i <= m; i++) {
		ans = min(ans, f[n%2][i]);
	}
	if(ans != 1e15) {
		printf("1\n");
		printf("%lld", ans);
	} else {
		printf("0\n");
		printf("%lld", ans2);
	}
}
