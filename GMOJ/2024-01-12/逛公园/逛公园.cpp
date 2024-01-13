/**
 * @file 逛公园.cpp 
 * @tag: #GMOJ#图论#最短路
 * @author: ZnPdCo
 * @date: 2024-01-13
 * @problem: https://gmoj.net/senior/#main/show/5475
 **/
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define N 100010
#define M 200010
#define K 100
ll he1[N];
ll he2[N];
ll nxt[2*M];
ll cost[2*M];
ll to[2*M], cnt;
ll T;
ll n, m, k, p;

void addEdge(ll head[], ll u, ll v, ll w) {
	++cnt;
	to[cnt] = v;
	nxt[cnt] = head[u];
	cost[cnt] = w;
	head[u] = cnt;
}

bool vis[N];
ll dis[N];
priority_queue<pair<ll, ll> > q;
void dij() {
	memset(vis, 0, sizeof vis);
	dis[1] = 0;
	for(ll i = 2; i <= n; i++) dis[i] = 1e15;
	q.push(make_pair(0, 1));
	while(!q.empty()) {
		ll u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(ll i = he1[u]; i; i = nxt[i]) {
			ll v = to[i];
			if(!vis[v]) {
				if(dis[v] > dis[u] + cost[i]) {
					dis[v] = dis[u] + cost[i];
					q.push(make_pair(-dis[v], v));
				}
			}
		}
	}
}

ll f[N][K];
bool flag[N][K];

ll dfs(ll u, ll x) {
	if(x < 0 || x > k) return 0;
	if(flag[u][x]) return -1;
	if(f[u][x] != -1) return f[u][x];
	flag[u][x] = 1;
	f[u][x] = 0;
	for(ll i = he2[u]; i; i = nxt[i]) {
		ll v = to[i];
		ll res = dfs(v, x - ((dis[v] + cost[i]) - dis[u]));
		if(res == -1) return -1;
		(f[u][x] += res) %= p;
	}
	if(u == 1 && x == 0) {
		(f[u][x] += 1) %= p;
	}
	flag[u][x] = 0;
	return f[u][x];
}

int main() {
//	freopen("park.in", "r", stdin);
//	freopen("park.out", "w", stdout);
	scanf("%lld", &T);
	while(T--) {
		memset(he1, 0, sizeof he1);
		memset(he2, 0, sizeof he2);
		cnt = 0;
		scanf("%lld %lld %lld %lld", &n, &m, &k, &p);
		for(ll i = 1; i <= m; i++) {
			ll u, v, w;
			scanf("%lld %lld %lld", &u, &v, &w);
			addEdge(he1, u, v, w);
			addEdge(he2, v, u, w);
		}
		dij();
		for(ll i = 1; i <= n; i++) {
			for(ll j = 0; j <= k; j++) {
				flag[i][j] = 0;
				f[i][j] = -1;
			}
		}
		ll ans = 0;
		bool isans = true;
		for(ll i = 0; i <= k; i++) {
			ll res = dfs(n, i);
			if(res == -1) isans = false;
			else (ans += res) %= p;
		}
		if(isans) printf("%lld\n", ans);
		else printf("-1\n");
	}
}
