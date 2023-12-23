/**
 * @file 颜料大乱斗.cpp 
 * @tag: #GMOJ #线段树
 * @author: ZnPdCo
 * @date: 2023-12-23 16:03:45
 * @problem: https://gmoj.net/senior/#main/show/4603
 **/
#include <cstdio>
#include <cstring>
#include <queue>
#define ll long long
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define N 100010
using namespace std;
ll n, c, m;
struct node {
	ll val;
	ll lazy;
	node() {val = 0, lazy = 0;}
} t[N*4];
inline void pushdown(ll l, ll r, ll pos) {
	t[ls(pos)].lazy = t[rs(pos)].lazy = t[pos].lazy;
	t[ls(pos)].val = t[rs(pos)].val = 1 << (t[pos].lazy-1);
	t[pos].lazy = 0;
}
void build(ll l, ll r, ll pos) {
	if(l == r) {
		t[pos].val = 1;
		return;
	}
	ll mid = (l + r) >> 1;
	build(l, mid, ls(pos));
	build(mid+1, r, rs(pos));
	t[pos].val = t[ls(pos)].val | t[rs(pos)].val;
}
void update(ll nl, ll nr, ll l, ll r, ll pos, ll k) {
	if(nl <= l && r <= nr) {
		t[pos].val = 1 << (k-1);
		t[pos].lazy = k;
		return;
	}
	if(t[pos].lazy) {
		pushdown(l, r, pos);
	}
	ll mid = (l + r) >> 1;
	if(nl <= mid)
		update(nl, nr, l, mid, ls(pos), k);
	if(mid < nr)
		update(nl, nr, mid+1, r, rs(pos), k);
	t[pos].val = t[ls(pos)].val | t[rs(pos)].val;
}
ll query(ll nl, ll nr, ll l, ll r, ll pos) {
	if(nl <= l && r <= nr) {
		return t[pos].val;
	}
	if(t[pos].lazy) {
		pushdown(l, r, pos);
	}
	ll mid = (l + r) >> 1;
	ll res = 0;
	if(nl <= mid)
		res = res | query(nl, nr, l, mid, ls(pos));
	if(mid < nr)
		res = res | query(nl, nr, mid+1, r, rs(pos));
	return res;
}
int main() {
	scanf("%lld %lld %lld", &n, &c, &m);
	build(1, n, 1);
	for(ll i = 1; i <= m; i++) {
		char op[10];
		scanf("%s", op);
		if(op[0] == 'P') {
			ll l, r;
			scanf("%lld %lld", &l, &r);
			if(l > r) swap(l, r);
			printf("%lld\n", __builtin_popcountll(query(l, r, 1, n, 1)));
		} else {
			ll l, r, t;
			scanf("%lld %lld %lld", &l, &r, &t);
			if(l > r) swap(l, r);
			update(l, r, 1, n, 1, t);
		}
	}
}
