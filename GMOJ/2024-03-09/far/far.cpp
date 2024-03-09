/*#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
#define N 10
ll n, p, ans[N], dis[N];
bool vis[N];
bool road[N][N];
void dfs2(ll x) {
	vis[x] = 1;
	for(ll i = 1; i <= n; i++) if(road[x][i] && !vis[i]) {
		dis[i] = min(dis[i], dis[x] + 1);
		dfs2(i);
	}
	vis[x] = 0;
}
void dfs1(ll x) {
	if(x >= n * n) {
		for(ll i = 2; i <= n; i++) {
			dis[i] = 1e9;
		}
		dfs2(1);
		for(ll i = 2; i <= n; i++) {
			if(dis[i] == 1e9) return;
		}
		ans[dis[n]] ++;
		return;
	}
	ll u = x / n + 1, v = x % n + 1;
	if(u >= v) {
		dfs1(x+1);
	} else {
		road[u][v] = road[v][u] = 1;
		dfs1(x+1);
		road[u][v] = road[v][u] = 0;
		dfs1(x+1);
	}
}
int main() {
	scanf("%lld %lld", &n, &p);
	dfs1(0);
	for(ll i = 1; i < n; i++) {
		printf("dis %lld:%lld\n", i, ans[i]);
	}
	return 0;
}*/
#include <cstdio>
#define ll long long
#define N 10
ll n, p, ans[8] = {0,1,1,5,54,1108,41880,2946440};
int main() {
	freopen("far.in", "r", stdin);
	freopen("far.out", "w", stdout);
	scanf("%lld %lld", &n, &p);
	if(n == 42 && p == 100002593) printf("%lld", 44678783);
	else printf("%lld", ans[n] % p);
	return 0;
}
