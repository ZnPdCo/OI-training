#include <bits/stdc++.h>
#define ll long long
#define N 6000010
#define ls(x) (t[x].lson)
#define rs(x) (t[x].rson)
ll m, n, rt;
ll a[N];

struct node {
	ll siz, x, y;
	ll lson, rson;
} t[4*N];
ll cnt = 0;

inline char gc() {
	const int BUF = 1e6;
	static char ch[BUF], *l, *r;
	return (l == r && (r = (l = ch) + fread(ch, 1, BUF, stdin), l == r)) ? EOF : *l++;
}
template <typename T> inline void read(T &x) {
	x = 0; int f = 1; char c = gc();
	for (; !isdigit(c); c = gc()) if (c == '-') f = -f;
	for (; isdigit(c); c = gc()) x = (x << 1) + (x << 3) + (c ^ 48);
	x *= f;
}

inline ll calc(ll a, ll x, ll y) {
	return (a - y + x - 1) / x;
}

void pushdown(ll l, ll r, ll pos) {
	if(l == r) return;
	ll mid = (l + r) >> 1;
	if(!ls(pos)) {
		ls(pos) = ++cnt;
		t[ls(pos)].siz = mid - l + 1;
		t[ls(pos)].x = 1;
	}
	if(!rs(pos)) {
		rs(pos) = ++cnt;
		t[rs(pos)].siz = r - mid;
		t[rs(pos)].x = 1;
	}
	ll oldlsum = ls(pos) ? t[ls(pos)].siz : (mid - l + 1);	// 左边操作之前的值，右边的y要减去这个值
	
	ll x = t[pos].x, y = t[pos].y;
	if(t[ls(pos)].siz == 0);
	else if(t[ls(pos)].siz == 1 && y == 0);
	else {
		t[ls(pos)].y = (y * t[ls(pos)].x + t[ls(pos)].y) % (t[ls(pos)].x * x);
		t[ls(pos)].x *= x;
		t[ls(pos)].siz = calc(t[ls(pos)].siz, x, y);
	}
	
	y = ((y - oldlsum) % x + x) % x;
	if(t[rs(pos)].siz == 0);
	else if(t[rs(pos)].siz == 1 && y == 0);
	else {
		t[rs(pos)].y = (y * t[rs(pos)].x + t[rs(pos)].y) % (t[rs(pos)].x * x);
		t[rs(pos)].x *= x;
		t[rs(pos)].siz = calc(t[rs(pos)].siz, x, y);
	}
	
	t[pos].x = 1;
	t[pos].y = 0;
}

void update(ll nl, ll nr, ll l, ll r, ll &pos, ll x, ll y) {
	if(!pos) {
		pos = ++cnt;
		t[pos].siz = r - l + 1;
		t[pos].x = 1;
	}
	if(nl <= l && r <= nr) {
		if(t[pos].siz == 0);
		else if(t[pos].siz == 1 && y == 0);
		else {
			t[pos].y = (y * t[pos].x + t[pos].y) % (t[pos].x * x);
			t[pos].x *= x;
			t[pos].siz = calc(t[pos].siz, x, y);
		}
		return;
	}
	if(t[pos].x != 1) pushdown(l, r, pos);
	ll mid = (l + r) >> 1;
	
	ll oldlsum = ls(pos) ? t[ls(pos)].siz : (mid - l + 1);	// 左边操作之前的值，右边的y要减去这个值
	
	if(nl <= mid)
		update(nl, nr, l, mid, ls(pos), x, y);
	if(mid < nr)
		update(nl, nr, mid+1, r, rs(pos), x, ((y - oldlsum) % x + x) % x);
	
	ll lsum = ls(pos) ? t[ls(pos)].siz : (mid - l + 1);
	ll rsum = rs(pos) ? t[rs(pos)].siz : (r - mid);
	t[pos].siz = lsum + rsum;
}
ll query(ll x, ll l, ll r, ll &pos) {
	if(!pos) {
		pos = ++cnt;
		t[pos].siz = r - l + 1;
		t[pos].x = 1;
	}
	if(l == r) {
		return l;
	}
	if(t[pos].x != 1) pushdown(l, r, pos);
	ll mid = (l + r) >> 1;
	ll lsum = ls(pos) ? t[ls(pos)].siz : (mid - l + 1);
	if(x <= lsum)
		return query(x, l, mid, ls(pos));
	else
		return query(x-lsum, mid+1, r, rs(pos));
}

int main() {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	read(m), read(n);
	for(ll i = 1; i <= m; i++) {
		ll l, r;
		read(l), read(r);
		ll L = query(l, 1, n, rt);
		ll R = query(r, 1, n, rt);
		printf("%lld %lld\n", L, R);
		update(L, R, 1, n, rt, 2, l % 2);
	}
	return 0;
}
