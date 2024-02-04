#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define N 600010
ll n, q, k, p;
ll g[N];
ll head[N];
ll nxt[2*N];
ll to[2*N], cnt;

bool flag[N];

void addEdge(ll u, ll v) {
	cnt++;
	to[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
}

void dfs1(ll u, ll fa) {
	for(ll i = head[u]; i; i = nxt[i]) {
		ll v = to[i];
		if(v == fa) continue;
		d1[v] = d1[u] + 1;
		if(d1[v] > d1[c]) c = v;
		dfs1(v, u);
	}
}

void dfs2(ll u, ll fa) {
	for(ll i = head[u]; i; i = nxt[i]) {
		ll v = to[i];
		if(v == fa) continue;
		d2[v] = d2[u] + 1;
		if(d2[v] > d2[c]) c = v;
		dfs2(v, u);
	}
}

int main() {
//	freopen("stone.in", "r", stdin);
//	freopen("stone.out", "w", stdout);
	scanf("%lld", &n);
	for(ll i = 2; i <= n; i++) {
		ll fa;
		scanf("%lld", &fa);
		addEdge(fa, n+i), addEdge(n+i, fa);
		addEdge(i, n+i), addEdge(n+i, i);
	}
	for(ll i = 1; i <= 2*n; i++) g[i] = 1e15;
	scanf("%lld", &q);
	for(ll i = 1; i <= q; i++) {
		scanf("%lld", &k);
		memset(flag, 0, sizeof flag);
		memset(d1, 0, sizeof d1);
		memset(d2, 0, sizeof d2);
		for(ll j = 1; j <= k; j++) {
			scanf("%lld", &p);
			flag[p] = 1;
		}
		
		dfs1(p, 0), p = c;
		dfs2(p, 0);
		
		
	}
	
	for(ll i = 1; i <= n; i++) {
		printf("%lld\n", g[i]);
	}
}
