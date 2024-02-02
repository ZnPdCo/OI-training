#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define N 300010
ll n, q;
ll g[N], f;
ll head[N];
ll nxt[2*N];
ll to[2*N], cnt;

ll k, p;
bool flag[N];

void addEdge(ll u, ll v) {
	cnt++;
	to[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
}

void dfs(ll u, ll fa, ll dis) {
	if(flag[u]) f = max(f, dis);
	for(ll i = head[u]; i; i = nxt[i]) {
		ll v = to[i];
		if(v == fa) continue;
		dfs(v, u, dis+1);
	}
}

int main() {
	freopen("stone.in", "r", stdin);
	freopen("stone.out", "w", stdout);
	scanf("%lld", &n);
	for(ll i = 2; i <= n; i++) {
		ll fa;
		scanf("%lld", &fa);
		addEdge(fa, i);
		addEdge(i, fa);
	}
	for(ll i = 1; i <= n; i++) g[i] = 1e15;
	scanf("%lld", &q);
	for(ll i = 1; i <= q; i++) {
		scanf("%lld", &k);
		memset(flag, 0, sizeof flag);
		for(ll j = 1; j <= k; j++) {
			scanf("%lld", &p);
			flag[p] = 1;
		}
		for(ll j = 1; j <= n; j++) {
			f = 0;
			dfs(j, 0, 0);
			g[j] = min(g[j], f);
		}
	}
	
	for(ll i = 1; i <= n; i++) {
		printf("%lld\n", g[i]);
	}
}
