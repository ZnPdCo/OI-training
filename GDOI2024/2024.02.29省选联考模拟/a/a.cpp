#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000010
ll t;
ll n, m, a, b, rt;

ll head[N], nxt[2*N], to[2*N], cnt;
ll dep[N], ans[N];
bool vis[N];

struct node {
	ll u, v;
} edge[N];
ll num;

void addEdge(ll u, ll v) {
	cnt++;
	to[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
}

void dfs(ll u, ll fa, ll d) {
	ans[u] = fa;
	dep[u] = d;
	vis[u] = 1;
	for(ll i = head[u]; i; i = nxt[i]) {
		ll v = to[i];
		if(v == fa) continue;
		if(!vis[v]) dfs(v, u, d + 1);
		else if(dep[u] > dep[v]) edge[++num].u = u, edge[num].v = v;
	}
}

int main() {
//	freopen("ex_flower2.in", "r", stdin);
//	freopen("ex_flower2.out", "w", stdout);
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld %lld %lld %lld %lld", &n, &m, &a, &b, &rt);
		for(ll i = 1; i <= n; i++) head[i] = vis[i] = 0;
		cnt = 1; num = 0;
		for(ll i = 1; i <= m; i++) {
			ll u, v;
			scanf("%lld %lld", &u, &v);
			addEdge(u, v);
			addEdge(v, u);
		}
		dfs(rt, 0, 0);
		sort(edge + 1, edge + 1 + num, [](const auto &x, const auto &y) {
			if(dep[x.u] == dep[y.u]) return dep[x.v] > dep[y.v];
			return dep[x.u] > dep[y.u];
		});
		for(ll i = 1; i <= b; i++) {
			ans[edge[i].u] = edge[i].v;
		}
		for(ll i = 1; i <= n; i++) {
			printf("%lld ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}
