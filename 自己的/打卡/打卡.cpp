#include <cstdio>
#include <cstring>
#define ll long long
#define N 1000010
ll t, n, m;

ll head[N];
ll nxt[2*N];
ll to[2*N], cnt;

void addEdge(ll u, ll v) {
	cnt++;
	to[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
}

bool vis[N];
bool flag[N];
ll co[N], tot;

ll dfs1(ll u, ll fa) {
	if(vis[u]) {
		flag[u] = 1;
		co[++tot] = u;
		return u;
	}
	vis[u] = 1;
	for(ll i = head[u]; i; i = nxt[i]) {
		ll v = to[i];
		if(v == fa) continue;
		ll res = dfs1(v, u);
		if(res == u) return 0;
		else if(res) {
			flag[u] = 1;
			co[++tot] = u;
			return res;
		}
	}
	return 0;
}

ll dfs2(ll u, ll fa) {
	for(ll i = head[u]; i; i = nxt[i]) {
		ll v = to[i];
		if(v == fa) continue;
		if(flag[v]) continue;
		dfs2(v, u);
	}
	return 0;
}

int main() {
	scanf("%lld", &t);
	while(t--) {
		memset(head, 0, sizeof head);
		memset(vis, 0, sizeof vis);
		memset(flag, 0, sizeof flag);
		cnt = 0, tot = 0;
		scanf("%lld %lld", &n, &m);
		for(ll i = 1; i <= m; i++) {
			ll u, v;
			scanf("%lld %lld", &u, &v);
			addEdge(u, v);
			addEdge(v, u);
		}
		
		dfs1(1, 0);
		
		if(!tot) {
			flag[1] = 1;
			co[++tot] = 1;
		}
		
		for(ll i = 1; i <= tot; i++) {
			ll u = co[i];
			dfs2(u, 0);
		}
	}
}
