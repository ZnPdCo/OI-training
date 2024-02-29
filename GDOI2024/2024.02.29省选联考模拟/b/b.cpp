#include <cstdio>
#define ll long long
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define N 1000010
ll m, n;
ll a[N];

struct node {
	ll siz, lazy;
} t[4*N];

void build(ll l, ll r, ll pos) {
	t[pos].siz = (r - l + 1);
	t[pos].lazy = 0;
	if(l == r) {
		return;
	}
	ll mid = (l + r) >> 1;
	build(l, mid, ls(pos));
	build(mid + 1, r, rs(pos));
}

void pushdown(ll l, ll r, ll pos) {
	ll mid = (l + r) >> 1;
	if(l % 2 == t[pos].lazy % 2) t[ls(pos)].siz /= 2;
	else t[ls(pos)].siz = (t[ls(pos)].siz+1)/2;
	if((mid+1) % 2 == t[pos].lazy % 2) t[rs(pos)].siz /= 2;
	else t[rs(pos)].siz = (t[rs(pos)].siz+1)/2;
	t[ls(pos)].lazy = t[rs(pos)].lazy = t[pos].lazy;
	t[pos].lazy = 0;
}

void update(ll nl, ll nr, ll l, ll r, ll pos) {
	if(nl <= l && r <= nr) {
		if(t[pos].lazy) pushdown(l, r, pos);
		t[pos].lazy = nl;
		if(l % 2 == nl % 2) t[pos].siz /= 2;
		else t[pos].siz = (t[pos].siz+1)/2;
		return;
	}
	if(t[pos].lazy) pushdown(l, r, pos);
	ll mid = (l + r) >> 1;
	if(nl <= mid)
		update(nl, nr, l, mid, ls(pos));
	if(mid < nr)
		update(nl, nr, mid+1, r, rs(pos));
	t[pos].siz = t[ls(pos)].siz + t[rs(pos)].siz;
}
ll query(ll x, ll l, ll r, ll pos) {
	if(l == r) {
		return l;
	}
	if(t[pos].lazy) pushdown(l, r, pos);
	ll mid = (l + r) >> 1;
	if(x <= t[ls(pos)].siz)
		return query(x, l, mid, ls(pos));
	else
		return query(x-t[ls(pos)].siz, mid+1, r, rs(pos));
}



int main() {
//	freopen("ex_flower3.in", "r", stdin);
//	freopen("ex_flower3.out", "w", stdout);
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	scanf("%lld %lld", &m, &n);
	build(1, n, 1);
	for(ll i = 1; i <= m; i++) {
		ll l, r;
		scanf("%lld %lld", &l, &r);
		ll L = query(l, 1, n, 1);
		ll R = query(r, 1, n, 1);
		printf("%lld %lld\n", L, R);
		update(L, R, 1, n, 1);
	}
}
