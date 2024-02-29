#include <cstdio>
#define ll long long
#define N 6000010
#define ls(x) (t[x].lson)
#define rs(x) (t[x].rson)
ll m, n, rt;
ll a[N];

struct node {
	ll siz, x, y, lx, ly;
	ll lson, rson;
} t[4*N];
ll cnt = 0;

inline ll clac(ll a, ll x, ll y) {
	if(a < y) return 0;
	return (a - y) / x + 1;
}

void pushdown(ll l, ll r, ll pos) {
	if(l == r) return;
	ll mid = (l + r) >> 1;
	if(!ls(pos)) {
		ls(pos) = ++cnt;
		t[ls(pos)].siz = mid - l + 1;
		t[ls(pos)].x = t[ls(pos)].lx = 1;
	}
	if(!rs(pos)) {
		rs(pos) = ++cnt;
		t[rs(pos)].siz = r - mid;
		t[rs(pos)].x = t[rs(pos)].lx = 1;
	}
	
	ll x = t[pos].lx, y = t[pos].ly;
	t[ls(pos)].y = (y * t[ls(pos)].x + t[ls(pos)].y) % (t[ls(pos)].x * x);
	t[ls(pos)].x *= x;
	t[pos].siz = clac(mid, t[ls(pos)].x, t[ls(pos)].y) - clac(l - 1, t[ls(pos)].x, t[ls(pos)].y);
	
	t[rs(pos)].y = (y * t[rs(pos)].x + t[rs(pos)].y) % (t[rs(pos)].x * x);
	t[rs(pos)].x *= x;
	t[pos].siz = clac(r, t[rs(pos)].x, t[rs(pos)].y) - clac(mid, t[rs(pos)].x, t[rs(pos)].y);
	
	
	t[ls(pos)].lx = t[rs(pos)].lx = t[pos].lx;
	t[ls(pos)].ly = t[rs(pos)].ly = t[pos].ly;
	t[pos].lx = 1;
	t[pos].ly = 0;
}

void update(ll nl, ll nr, ll l, ll r, ll &pos, ll x, ll y) {
	if(!pos) {
		pos = ++cnt;
		t[pos].siz = r - l + 1;
		t[pos].x = t[pos].lx = 1;
	}
	if(nl <= l && r <= nr) {
		t[pos].ly = (y * t[pos].lx + t[pos].ly) % (t[pos].lx * x);
		t[pos].lx *= x;
		
		t[pos].y = (y * t[pos].x + t[pos].y) % (t[pos].x * x);
		t[pos].x *= x;
		
		t[pos].siz = clac(r, t[pos].x, t[pos].y) - clac(l - 1, t[pos].x, t[pos].y);
		return;
	}
	if(t[pos].lx != 1) pushdown(l, r, pos);
	ll mid = (l + r) >> 1;
	
	if(nl <= mid)
		update(nl, nr, l, mid, ls(pos), x, y);
	if(mid < nr)
		update(nl, nr, mid+1, r, rs(pos), x, y);
	
	ll lsum = ls(pos) ? t[ls(pos)].siz : (mid - l + 1);
	ll rsum = rs(pos) ? t[rs(pos)].siz : (r - mid);
	t[pos].siz = lsum + rsum;
}
ll query(ll x, ll l, ll r, ll &pos) {
	if(!pos) {
		pos = ++cnt;
		t[pos].siz = r - l + 1;
		t[pos].x = t[pos].lx = 1;
	}
	if(l == r) {
		return l;
	}
	if(t[pos].lx != 1) pushdown(l, r, pos);
	ll mid = (l + r) >> 1;
	ll lsum = ls(pos) ? t[ls(pos)].siz : (mid - l + 1);
	if(x <= lsum)
		return query(x, l, mid, ls(pos));
	else
		return query(x-lsum, mid+1, r, rs(pos));
}

int main() {
//	freopen("ex_flower4.in", "r", stdin);
//	freopen("ex_flower4.out", "w", stdout);
//	freopen("b.in", "r", stdin);
//	freopen("b.out", "w", stdout);
	scanf("%lld %lld", &m, &n);
	for(ll i = 1; i <= m; i++) {
		ll l, r;
		scanf("%lld %lld", &l, &r);
		ll L = query(l, 1, n, rt);
		ll R = query(r, 1, n, rt);
		printf("%lld %lld\n", L, R);
		update(L, R, 1, n, rt, 2, l % 2);
	}
}
