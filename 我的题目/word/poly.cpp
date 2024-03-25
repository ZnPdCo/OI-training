#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define N 110
#define M 5
#define P 998244353
ll n, m, k, q;
ll a[M], b[N];
ll ans[N];
ll nxt[M];
ll f[N][M];
ll flag = 0;
ll solve() {
	if(flag == 1) {
		printf("");
	}
	for(ll i = 0; i <= n; i ++)
		for(ll j = 0; j <= 4; j ++) f[i][j] = 0x3f3f3f;
	f[0][0] = 0;
	for(ll i = 0; i < n; i ++) {
		for(ll j = 0; j < m; j ++) {
			ll u = j;
			while(u && b[i + 1] != a[u + 1]) u = nxt[u];
			if(b[i + 1] == a[u + 1]) u++;
			if(u < m) f[i + 1][u] = min(f[i + 1][u], f[i][j]);
			f[i + 1][j] = min(f[i + 1][j], f[i][j] + 1);
			if(flag == 1) printf("f[%lld][%lld]=%lld\n", i, j, f[i][j]);
		}
	}
	ll res = 0x3f3f3f;
	for(ll i = 0; i < m; i ++) res = min(res, f[n][i]);
	if(flag == 1) flag = 2;
	return res;
}
void dfs(ll x) {
	if(x > n) {
		ans[solve()] ++;
		if(solve() == 3 && flag == 0) {
			flag = 1;
			solve();
		}
		return;
	}
	for(ll i = 1; i <= k; i ++) {
		b[x] = i;
		dfs(x + 1);
	}
}
int main() {
	scanf("%lld %lld %lld", &n, &m, &k);
	
	for(ll i = 1; i <= m; i ++) {
		scanf("%lld", &a[i]);
	}
	
	for(ll i = 2, j = 0; i <= m; i ++) {
		while(j && a[i] != a[j + 1]) j = nxt[j];
		if(a[i] == a[j + 1]) j++;
		nxt[i] = j;
	}
	
	dfs(1);
	
	for(ll i = 0; i <= n; i ++) {
		(ans[i] += ans[i - 1]) %= P;
	}
	
	scanf("%lld", &q);
	while(q --) {
		ll x;
		scanf("%lld", &x);
		printf("%lld\n", ans[x]);
	}
}
