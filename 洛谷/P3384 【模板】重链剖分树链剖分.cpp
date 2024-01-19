#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define N 100010

ll n, m, r, p;
ll dep[N], siz[N], son[N], fa[N], top[N], dfn[N];
ll head[N];
ll nxt[2*N];
ll to[2*N];
ll a[N];
ll w[N];
ll t[4*N];
ll lazy[4*N];
ll cnt, ti;

void dfs1(ll u, ll f) {
	fa[u] = f;
	siz[u] = 1;
	dep[u] = dep[f] + 1;
	ll mx = -1;
	for(ll i = head[u]; i; i = nxt[i]) {
		ll v = to[i];
		if(v == f) continue;
		dfs1(v, u);
		siz[u] += siz[v];
		if(siz[v] > mx) {
			mx = siz[v];
			son[u] = v;
		}
	}
}

void dfs2(ll u, ll t) {
	top[u] = t;
	dfn[u] = ++ti;
	w[ti] = a[u];
	if(son[u] == 0) return;
	dfs2(son[u], t);
	for(ll i = head[u]; i; i = nxt[i]) {
		ll v = to[i];
		if(v == fa[u] || v == son[u]) continue;
		dfs2(v, v);
	}
}

inline void pushup(ll pos) {
	(t[pos] = t[ls(pos)] + t[rs(pos)]) %= p;
}

inline void pushdown(ll l, ll r, ll pos) {
	ll mid = (l + r) >> 1;
	(t[ls(pos)] += (mid-l+1)*lazy[pos]) %= p;
	(lazy[ls(pos)] += lazy[pos]) %= p;
	(t[rs(pos)] += (r-mid)*lazy[pos]) %= p;
	(lazy[rs(pos)] += lazy[pos]) %= p;
	lazy[pos] = 0;
}

void build(ll l, ll r, ll pos) {
	if(l == r) {
		t[pos] = w[l] % p;
		return;
	}
	ll mid = (l + r) >> 1;
	build(l, mid, ls(pos));
	build(mid+1, r, rs(pos));
	pushup(pos);
}

void update(ll nl, ll nr, ll l, ll r, ll pos, ll k) {
	if(nl <= l && r <= nr) {
		(t[pos] += (r-l+1) * k) %= p;
		(lazy[pos] += k) %= p;
		return;
	}
	pushdown(l, r, pos);
	
	
	ll mid = (l + r) >> 1;
	if(nl <= mid)
		update(nl, nr, l, mid, ls(pos), k);
	if(mid < nr)
		update(nl, nr, mid+1, r, rs(pos), k);
	pushup(pos);
}



ll query(ll nl, ll nr, ll l, ll r, ll pos) {
	if(nl <= l && r <= nr) {
		return t[pos];
	}
	pushdown(l, r, pos);
	ll res = 0;
	
	ll mid = (l + r) >> 1;
	if(nl <= mid)
		(res += query(nl, nr, l, mid, ls(pos))) %= p;
	if(mid < nr)
		(res += query(nl, nr, mid+1, r, rs(pos))) %= p;
	
	return res;
}

void addEdge(ll u, ll v) {
	cnt++;
	to[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
}

ll qRange(ll x, ll y) {
	ll res = 0;
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		(res += query(dfn[top[x]], dfn[x], 1, n, 1)) %= p;
		x = fa[top[x]];
	}
	
	if(dep[x] > dep[y]) swap(x, y);
	(res += query(dfn[x], dfn[y], 1, n, 1)) %= p;
	return res;
}

void updRange(ll x, ll y, ll k) {
	k %= p;
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		update(dfn[top[x]], dfn[x], 1, n, 1, k);
		x = fa[top[x]];
	}
	
	if(dep[x] > dep[y]) swap(x, y);
	update(dfn[x], dfn[y], 1, n, 1, k);
}

inline ll qSon(ll x) {
	return query(dfn[x], dfn[x] + siz[x] - 1, 1, n, 1);
}

inline void updSon(ll x, ll k) {
	update(dfn[x], dfn[x] + siz[x] - 1, 1, n, 1, k);
}

int main() {
	scanf("%lld %lld %lld %lld", &n, &m, &r, &p);
	for(ll i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	for(ll i = 1; i < n; i++) {
		ll u, v;
		scanf("%lld %lld", &u, &v);
		addEdge(u, v);
		addEdge(v, u);
	}
	dfs1(r, 0);
	dfs2(r, 0);
	build(1, n, 1);
	
	while(m--) {
		ll op;
		scanf("%lld", &op);
		if(op == 1) {
			ll x, y, k;
			scanf("%lld %lld %lld", &x, &y, &k);
			updRange(x, y, k);
		}
		else if(op == 2) {
			ll x, y;
			scanf("%lld %lld", &x, &y);
			printf("%lld\n", qRange(x, y));
		}
		else if(op == 3) {
			ll x, k;
			scanf("%lld %lld", &x, &k);
			updSon(x, k);
		}
		else if(op == 4) {
			ll x;
			scanf("%lld",&x);
			printf("%lld\n", qSon(x));
		}
	}
}
