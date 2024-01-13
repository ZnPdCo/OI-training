/**
 * @file 列队.cpp 
 * @tag: #GMOJ#数据结构#ds
 * @author: ZnPdCo
 * @date: 2024-01-13
 * @problem: https://gmoj.net/senior/#main/show/5475
 **/
#include <cstdio>
#include <algorithm>
#include <vector>
#define ll long long
#define N 1000010
using namespace std;
ll n, m, q, mx;
ll rt[N], cnt;
vector <ll> v[N];
struct node {
	ll ls, rs, mov;
	// mov是删掉了多少个（存区间个数还要初始化，我懒）
} t[4*N];
ll query(ll x, ll l, ll r, ll pos) {
	if(l == r) return l;
	ll mid = (l + r) >> 1;
	ll num = mid - l + 1 - t[t[pos].ls].mov;
	if(x <= num) {
		return query(x, l, mid, t[pos].ls);
	} else {
		return query(x-num, mid+1, r, t[pos].rs);
	}
}
void update(ll x, ll l, ll r, ll &pos, ll k) {
	if(!pos) pos = ++cnt;
	t[pos].mov += k;
	if(l == r) return;
	ll mid = (l + r) >> 1;
	if(x <= mid) {
		update(x, l, mid, t[pos].ls, k);
	} else {
		update(x, mid+1, r, t[pos].rs, k);
	}
}
// 向前看齐
ll front(ll x, ll add) {
	ll res = query(x, 1, mx, rt[n+1]);
	update(res, 1, mx, rt[n+1], 1);
	ll id;
	if(res <= n) {
		id = res * m;
	} else {
		id = v[n+1][res - n - 1];
	}
	if(add) v[n+1].push_back(add);
	else v[n+1].push_back(id);
	return id;
}
// 向左看齐
ll left(ll x, ll y) {
	ll res = query(y, 1, mx, rt[x]);
	update(res, 1, mx, rt[x], 1);
	ll id;
	if(res < m) {
		id = (x - 1) * m + res;
	} else {
		id = v[x][res - m];
	}
	v[x].push_back(front(x, id));
	return id;
}
int main() {
//	freopen("phalanx.in", "r", stdin);
//	freopen("phalanx.out", "w", stdout);
	scanf("%lld %lld %lld", &n, &m, &q);
	mx = max(n, m) + q;
	for(ll i = 1; i <= q; i++) {
		ll x, y;
		scanf("%lld %lld", &x, &y);
		if(y == m) printf("%lld\n", front(x, 0));
		else printf("%lld\n", left(x, y));
	}
}
