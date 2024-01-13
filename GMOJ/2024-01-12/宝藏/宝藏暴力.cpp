#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
#define N 20
using namespace std;
ll n, m;
ll road[N][N];
ll dis[1<<N];	// 走这些的距离
bool vis[N][N];
ll from[N], to[N];
ll ans = 1e15;
ll sum;
ll able;
ll dep[N];
void dfs2(ll x) {
	if(x >= n) return;
	if(able & (1<<(from[x]-1))) {
		able |= (1<<(to[x]-1));
		dep[to[x]] = dep[from[x]] + 1;
		sum += road[from[x]][to[x]] * dep[to[x]];
		dfs2(x+1);
	} else sum = 1e15;
}
void dfs(ll x) {
	if(x >= n) {
		sum = 0;
		memset(dep, 0, sizeof dep);
		able = 1<<(from[1]-1);
		dfs2(1);
		if(able == (1<<n)-1)
			ans = min(ans, sum);
		return;
	}
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= n; j++) if(i != j) {
			if(vis[i][j] || vis[j][i]) continue;
			if(road[i][j] == 1e15) continue;
			vis[i][j] = vis[j][i] = 1;
			from[x] = i;
			to[x] = j;
			dfs(x+1);
			vis[i][j] = vis[j][i] = 0;
		}
	}
}
int main() {
	freopen("treasure.in", "r", stdin);
	freopen("treasure.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for(ll i = 1; i <= n; i++) {
		for(ll j = i+1; j <= n; j++) {
			road[i][j] = road[j][i] = 1e15;
		}
	}
	for(ll i = 1; i <= m; i++) {
		ll u, v, w;
		scanf("%lld %lld %lld", &u, &v, &w);
		if(w < road[u][v]) {
			road[u][v] = road[v][u] = w;
		}
	}
	dfs(1);
	printf("%lld", ans);
}
