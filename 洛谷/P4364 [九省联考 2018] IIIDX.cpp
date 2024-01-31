#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define N 500010
ll n;
double k;
ll d[N], ans[N];

namespace Tree {
	ll head[N];
	ll nxt[2*N], to[2*N], tot;
	ll fa[N];
	void addEdge(ll u, ll v) {
		tot++;
		to[tot] = v;
		nxt[tot] = head[u];
		head[u] = tot;
	}
	
	ll siz[N];
	void dfs(ll u, ll fa) {
		siz[u] = 1;
		for(ll i = head[u]; i; i = nxt[i]) {
			ll v = to[i];
			if(v == fa) continue;
			dfs(v, u);
			siz[u] += siz[v];
		}
	}
}

namespace Segment {
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
	ll t[4*N];
	ll lazy[4*N];
	
	void build(ll l, ll r, ll pos) {
		if(l == r) {
			t[pos] = l;
			return;
		}
		ll mid = (l+r) >> 1;
		build(l, mid, ls(pos));
		build(mid+1, r, rs(pos));
		t[pos] = min(t[ls(pos)], t[rs(pos)]);
	}
	
	void pushdown(ll pos) {
		t[ls(pos)] += lazy[pos];
		lazy[ls(pos)] += lazy[pos];
		t[rs(pos)] += lazy[pos];
		lazy[rs(pos)] += lazy[pos];
		lazy[pos] = 0;
	}
	
	void update(ll nl, ll nr, ll l, ll r, ll pos, ll k) {
		if(nl <= l && r <= nr) {
			t[pos] += k;
			lazy[pos] += k;
			return;
		}
		pushdown(pos);
		ll mid = (l + r) >> 1;
		if(nl <= mid)
			update(nl, nr, l, mid, ls(pos), k);
		if(mid < nr)
			update(nl, nr, mid+1, r, rs(pos), k);
		t[pos] = min(t[ls(pos)], t[rs(pos)]);
	}
	
	ll query(ll x, ll l, ll r, ll pos) {
		if(l == r) {
			if(t[pos] >= x) return l;
			else return l+1;
		}
		pushdown(pos);
		ll mid = (l + r) >> 1;
		if(t[rs(pos)] < x) return query(x, mid+1, r, rs(pos));
		return query(x, l, mid, ls(pos));
	}
	
#undef ls
#undef rs
}


ll cnt[N];
int main() {
	scanf("%lld %lf", &n, &k);
	
	for(ll i = 1; i <= n; i++) {
		scanf("%lld", &d[i]);
		ll fa = i / k;
		if(fa == 0) fa = n+1;
		
		Tree::addEdge(i, fa);
		Tree::addEdge(fa, i);
		Tree::fa[i] = fa;
	}
	
	Tree::dfs(n+1, 0);
	
	sort(d+1, d+1+n, [&](const ll &x, const ll &y) {return x > y;});
	
	for(ll i = n; i >= 1; i--) {
		if(d[i] == d[i+1]) cnt[i] = cnt[i+1]+1;
	}
	
	Segment::build(1, n, 1);
	
	for(ll i = 1; i <= n; i++) {
		using namespace Tree;
		if(fa[i] != n+1 && fa[i] != fa[i-1]) {
			Segment::update(ans[fa[i]], n, 1, n, 1, siz[fa[i]]-1);
		}
		ll now = Segment::query(siz[i], 1, n, 1);
		now += cnt[now];
		cnt[now]++;
		ans[i] = now;
		Segment::update(ans[i], n, 1, n, 1, -siz[i]);
	}
	
	for(ll i = 1; i <= n; i++) {
		printf("%lld ", d[ans[i]]);
	}
}
