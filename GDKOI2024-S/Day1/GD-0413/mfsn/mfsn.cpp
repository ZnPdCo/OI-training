#include <cstdio>
#define ll long long 
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define N 500010
ll n, m, q, sum[N];
struct node {
	ll op, l, r, v;
} a[N];

ll t[4*N], lazy[4*N];

void build(ll l, ll r, ll pos) {
	t[pos] = 0;
	lazy[pos] = 0;
	if(l == r) {
		return;
	}
	ll mid = (l + r) >> 1;
	build(l, mid, ls(pos));
	build(mid+1, r, rs(pos));
}
void pushup(ll pos) {
	t[pos] = t[ls(pos)] + t[rs(pos)];
}
inline void f(ll l, ll r, ll pos, ll k) {
	lazy[pos] = k;
	t[pos] = k * (r - l + 1);
}
void pushdown(ll l, ll r, ll pos) {
	ll mid = (l + r) >> 1;
	f(l, mid, ls(pos), lazy[pos]);
	f(mid+1, r, rs(pos), lazy[pos]);
	lazy[pos] = 0;
}
void update(ll nl, ll nr, ll l, ll r, ll pos, ll k) {
	if(nl <= l && r <= nr) {
		t[pos] = k * (r - l + 1);
		lazy[pos] = k;
		return;
	}
	if(lazy[pos]) {
		pushdown(l, r, pos);
	}
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
	if(lazy[pos]) {
		pushdown(l, r, pos);
	}
	ll mid = (l + r) >> 1;
	ll res = 0;
	if(nl <= mid)
		res += query(nl, nr, l, mid, ls(pos));
	if(mid < nr)
		res += query(nl, nr, mid+1, r, rs(pos));
	return res;
}
int main() {
	freopen("mfsn.in", "r", stdin);
	freopen("mfsn.out", "w", stdout);
	scanf("%lld %lld %lld", &n, &m, &q);
	for(ll i = 1; i <= m; i++) {
		scanf("%lld %lld %lld", &a[i].op, &a[i].l, &a[i].r);
		if(a[i].op == 1) {
			scanf("%lld", &a[i].v);
			update(a[i].l, a[i].r, 1, n, 1, a[i].v);
		} else {
			sum[i] = query(a[i].l, a[i].r, 1, n, 1);
		}
		sum[i] += sum[i-1];
	}
	for(ll i = 1; i <= q; i++) {
		ll l, r;
		scanf("%lld %lld", &l, &r);
		if(l == 1) { 	// Ç°×ººÍ 
			printf("%lld\n", sum[r]);
		} else {
			build(1, n, 1);
			ll ans = 0;
			for(ll j = l; j <= r; j++) {
				if(a[j].op == 1) {
					update(a[j].l, a[j].r, 1, n, 1, a[j].v);
				} else {
					ans += query(a[j].l, a[j].r, 1, n, 1);
				}
			}
			printf("%lld\n", ans);
		}
	} 
}
