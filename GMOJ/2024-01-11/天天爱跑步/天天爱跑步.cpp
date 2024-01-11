/**
 * @file 天天爱跑步.cpp 
 * @tag: #GMOJ#桶#LCA
 * @author: ZnPdCo
 * @date: 2024-01-11 20:57:17
 * @problem: https://gmoj.net/senior/#main/show/4904
 **/
#include <cstdio>
#include <algorithm>
#include <vector>
#define ll long long
#define N 300000
using namespace std;
ll n, m;
ll head[N];
ll nxt[2*N];
ll to[2*N], cnt;
ll w[N], s[N], t[N];
ll ans[N];

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
ll LCA(ll x, ll y) {
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

vector<pair<ll, ll> > opt1[N], opt2[N];
ll b1[N], b2[2*N];
void dfs1(ll u, ll fa) {
	ll od = b1[dep[u]+w[u]];
	for(ll i = head[u]; i; i = nxt[i]) {
		ll v = to[i];
		if(v == fa) continue;
		dfs1(v, u);
	}
	for(auto x : opt1[u]) {
		b1[x.first] += x.second;
	}
	ll nw = b1[dep[u]+w[u]];
	ans[u] += nw-od;
}
void dfs2(ll u, ll fa) {
	ll od = b2[w[u]-dep[u]+N];
	for(ll i = head[u]; i; i = nxt[i]) {
		ll v = to[i];
		if(v == fa) continue;
		dfs2(v, u);
	}
	for(auto x : opt2[u]) {
		b2[x.first+N] += x.second;
	}
	ll nw = b2[w[u]-dep[u]+N];
	ans[u] += nw-od;
}

int main() {
	freopen("running.in", "r", stdin);
	freopen("running.out", "w", stdout);
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
		ll ca = LCA(s[i], t[i]);
		// dep_s=dep_{ca}-w_{ca}
		opt1[s[i]].push_back(make_pair(dep[s[i]], 1));	// 在到达s[i]时添加贡献
		opt1[ca].push_back(make_pair(dep[s[i]], -1));	// 在离开会统计s[i]的lca时删除贡献
	}
	dfs1(1, 0);
	for(ll i = 1; i <= m; i++) {
		ll ca = LCA(s[i], t[i]);
		ll dist = dep[s[i]] + dep[t[i]] - 2*dep[ca];
		// dist_{s,t}-w_{ca}=dep_t-dep_{ca}
		// dist_{s,t}-dep_t=w_{ca}-dep_{ca}
		opt2[t[i]].push_back(make_pair(dist - dep[t[i]], 1));		// 在到达t[i]时添加贡献
		opt2[f[ca][0]].push_back(make_pair(dist - dep[t[i]], -1));	// 在离开会统计t[i]的lca时删除贡献
		// 这里为了统计lca自己
	}
	dfs2(1, 0);
	for(ll i = 1; i <= n; i++) {
		printf("%lld ", ans[i]);
	}
}
