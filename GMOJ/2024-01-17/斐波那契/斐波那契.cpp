#include <cstdio>
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define ll long long
#define N 300010
#define P 1000000009
ll n, m;
ll a[N];
ll f[N];

struct node {
	ll f1, f2, v;
} t[4*N];

inline ll fun(ll x) {
	return (x % P + P) % P;
}

void build(ll l, ll r, ll pos) {
	if(l == r) {
		t[pos].v = a[l];
		return;
	}
	
	ll mid = (l + r) >> 1;
	build(l, mid, ls(pos));
	build(mid+1, r, rs(pos));
	
	(t[pos].v = t[ls(pos)].v + t[rs(pos)].v) %= P;
}

void init() {
	f[1] = f[2] = 1;
	for(ll i = 3; i <= n+5; i++) {
		(f[i] = f[i-1] + f[i-2]) %= P;
	}
}

void pushdown(ll l, ll r, ll pos) {
	ll mid = (l + r) >> 1;
	(t[ls(pos)].f1 += t[pos].f1) %= P;
	(t[ls(pos)].f2 += t[pos].f2) %= P;
	(t[ls(pos)].v += f[mid-l+1] * t[pos].f1 % P + fun(f[mid-l+2]-1) * t[pos].f2 % P) %= P;
	
	
	(t[rs(pos)].f1 += f[mid-l+1] * t[pos].f2 % P + f[mid-l] * t[pos].f1 % P) %= P;
	(t[rs(pos)].f2 += f[mid-l+2] * t[pos].f2 % P + f[mid-l+1] * t[pos].f1 % P) %= P;
	(t[rs(pos)].v += f[r-l+1] * t[pos].f1 + fun(f[r-l+2]-1) * t[pos].f2 - 
		f[mid-l+1] * t[pos].f1 - fun(f[mid-l+2]-1) * t[pos].f2) %= P;
	
	t[rs(pos)].v = fun(t[rs(pos)].v);
	
	t[pos].f1 = t[pos].f2 = 0;
}

void update(ll nl, ll nr, ll l, ll r, ll pos) {
	if(nl <= l && r <= nr) {
		(t[pos].f1 += f[l-nl+1]) %= P;
		(t[pos].f2 += f[l-nl+2]) %= P;
		(t[pos].v += f[r-l+1] * f[l-nl+1] % P + fun(f[r-l+2]-1) * f[l-nl+2] % P) %= P;
		return;
	}
	
	pushdown(l, r, pos);
	
	
	ll mid = (l + r) >> 1;
	if(nl <= mid)
		update(nl, nr, l, mid, ls(pos));
	if(mid < nr)
		update(nl, nr, mid+1, r, rs(pos));
	
	(t[pos].v = t[ls(pos)].v + t[rs(pos)].v) %= P;
}

ll query(ll nl, ll nr, ll l, ll r, ll pos) {
	if(nl <= l && r <= nr) {
		return t[pos].v;
	}
	
	pushdown(l, r, pos);
	
	
	ll mid = (l + r) >> 1;
	ll res = 0;
	if(nl <= mid)
		(res += query(nl, nr, l, mid, ls(pos))) %= P;
	if(mid < nr)
		(res += query(nl, nr, mid+1, r, rs(pos))) %= P;
	
	return res;
}

int main() {
	scanf("%lld %lld", &n, &m);
	
	for(ll i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	
	build(1, n, 1);
	init();
	
	for(ll i = 1; i <= m; i++) {
		ll op, l, r;
		scanf("%lld %lld %lld", &op, &l, &r);
		if(op == 1) {
			update(l, r, 1, n, 1);
		} else {
			printf("%lld\n", query(l, r, 1, n, 1));
		}
	}
}
