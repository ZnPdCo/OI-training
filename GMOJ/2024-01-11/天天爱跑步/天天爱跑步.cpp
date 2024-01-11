#include <cstdio>
#include <algorithm>
#define ll long long
#define N 300000
using namespace std;
ll n, m;
ll head[N];
ll nxt[2*N];
ll to[2*N], cnt;
ll w[N], s[N], t[N];
ll lc[N];
void addEdge(ll u, ll v) {
	cnt++;
	to[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
}
ll f[N][30], dep[N];
ll logn[N];
void dfs(ll u, ll fa) {
	dep[u] = dep[fa] + 1;
	f[u][0] = fa;
	for(ll i = head[u]; i; i = nxt[i]) {
		ll v = to[i];
		if(v == fa) continue;
		dfs(v, u);
	}
}
ll lca(ll x, ll y) {
	if(dep[x] < dep[y]) swap(x, y);
	while(dep[x] != dep[y]) x = f[x][logn[dep[x]-dep[y]]];
	if(x == y) return x;
	for(ll i = logn[dep[x]]; i >= 0; i--) {
		if(f[x][i] && f[y][i] && f[x][i] != f[y][i]) {
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}

int main() {
//	freopen("running.in", "r", stdin);
//	freopen("running.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	logn[1] = 0;
	for(ll i = 2; i <= n; i++) {
		logn[i] = logn[i>>1]+1;
	}
	for(ll i = 1; i < n; i++) {
		ll u, v;
		scanf("%lld %lld", &u, &v);
		addEdge(u, v);
		addEdge(v, u);
	}
	dfs(1, 0);
	for(ll j = 1; j <= 20; j++) {
		for(ll i = 1; i <= n; i++) {
			f[i][j] = f[f[i][j-1]][j-1];
		}
	}
	for(ll i = 1; i <= n; i++) {
		scanf("%lld", &w[i]);
	}
	for(ll i = 1; i <= m; i++) {
		scanf("%lld %lld", &s[i], &t[i]);
		lc[i] = lca(s[i], t[i]);
	}
	for(ll i = 1; i <= m; i++) {
		
	}
}
