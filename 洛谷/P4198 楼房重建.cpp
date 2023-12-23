/**
 * @file P4198 楼房重建.cpp 
 * @tag: #GMOJ#线段树#兔队线段树
 * @author: ZnPdCo
 * @date: 2023-10-06 08:11:12
 * @problem: https://www.luogu.com.cn/problem/P4198
 **/
#include <cstdio>
#define ll long long
#define ld long double
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define N 100010
ll n, m;

ld mx[N * 4];
ll len[N * 4];

template <typename T> inline T max(T x, T y) {
	return x > y ? x : y;
}

ll query(ll l, ll r, ll pos, ld k) {
	if(mx[pos] <= k) return 0;						// ⭐
	if(l == r) return mx[pos] > k;
	ll mid = (l + r) >> 1;
	if(mx[ls(pos)] <= k) return query(mid + 1, r, rs(pos), k);
	else return query(l, mid, ls(pos), k) + len[pos] - len[ls(pos)];
}

void push_up(ll l, ll r, ll pos) {
	ll mid = (l + r) >> 1;
	len[pos] = len[ls(pos)] + query(mid + 1, r, rs(pos), mx[ls(pos)]);
	mx[pos] = max(mx[ls(pos)], mx[rs(pos)]);
}

void update(ll l, ll r, ll pos, ll x, ll k) {
	if(l == r) {
		mx[pos] = (ld)(k) / (ld)(x);
		len[pos] = 1;
		return;
	}
	ll mid = (l + r) >> 1;
	if(x <= mid)
		update(l, mid, ls(pos), x, k);
	else
		update(mid + 1, r, rs(pos), x, k);
	push_up(l, r, pos);
}

int main() {
	scanf("%lld %lld", &n, &m);
	for(ll i = 1; i <= m; i++) {
		ll x, y;
		scanf("%lld %lld", &x, &y);
		update(1, n, 1, x, y);
		printf("%lld\n", len[1]);
	}
}
