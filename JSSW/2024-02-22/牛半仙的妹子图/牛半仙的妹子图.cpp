#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <bitset>
#define ll long long
#define N 500010
#define C 510
using namespace std;
ll n, m, q, x, opt, p, las;
ll c[N], e[N], len, g[N], s[N];
bitset<C> f[N];

ll head[N], nxt[2*N], cost[2*N], to[2*N], cnt;
void addEdge(ll u, ll v, ll w) {
	++cnt;
	to[cnt] = v;
	cost[cnt] = w;
	nxt[cnt] = head[u];
	head[u] = cnt;
}

priority_queue<pair<ll, ll> > que;
ll dis[N];
bool vis[N];

void dij() {
	for(ll i = 1; i <= n; i++) {
		dis[i] = 1e15;
	}
	dis[x] = 0;
	que.push(make_pair(0, x));
	while(!que.empty()) {
		ll u = que.top().second;
		que.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(ll i = head[u]; i; i = nxt[i]) {
			ll v = to[i], w = cost[i];
			if(!vis[v]) {
				if(dis[v] > max(dis[u], w)) {
					dis[v] = max(dis[u], w);
					que.push(make_pair(-dis[v], v));
				}
			}
		}
	}
}

ll query(ll x) {
	ll l = 1, r = len, pos = -1;
	while(l <= r) {
		ll mid = (l+r) >> 1;
		if(e[mid] <= x) {
			l = mid + 1;
			pos = mid;
		} else {
			r = mid - 1;
		}
	}
	if(pos == -1) return 0;
	return s[pos] - g[pos] * (e[pos+1] - x - 1);
}

int main() {
	scanf("%lld %lld %lld %lld %lld", &n, &m, &q, &x, &opt);
	if(opt) scanf("%lld", &p);
	for(ll i = 1; i <= n; i++) {
		scanf("%lld", &c[i]);
	}
	for(ll i = 1; i <= m; i++) {
		ll u, v, w;
		scanf("%lld %lld %lld", &u, &v, &w);
		e[i] = w;
		addEdge(u, v, w);
		addEdge(v, u, w);
	}
	sort(e+1, e+1+m);
	len = unique(e+1, e+1+m) - e - 1;
	e[len + 1] = m + 1;
	
	dij();
	
	for(ll i = 1; i <= n; i++) {
		ll num = lower_bound(e+1, e+1+len, dis[i]) - e;
		f[num][c[i]] = 1;
	}
	for(ll i = 1; i <= len; i++) {
		f[i] |= f[i-1];
		g[i] = f[i].count();
	}
	for(ll i = 1; i <= len; i++) {
		s[i] = s[i-1] + g[i] * (e[i+1] - e[i]);
	}
	
	for(ll i = 1; i <= q; i++) {
		ll l, r, L, R;
		scanf("%lld %lld", &l, &r);
		if(opt) {
			l = (l ^ las) % p + 1;
			r = (r ^ las) % p + 1;
		}
		if(l > r) swap(l, r);
		las = query(r) - query(l-1);
		printf("%lld\n", las);
	}
} 
