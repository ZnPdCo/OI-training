#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
#define N 1000010
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
ll n, ge, re, mod, q;
ll a[N], mp[N], e[N], bs[N];

struct node {
	ll val, id, rk;
} b[N];

ll t[4*N];

void build(ll l, ll r, ll pos) {
	t[pos] = 1e15;
	if(l == r) {
		return;
	}
	ll mid = (l + r) >> 1;
	build(l, mid, ls(pos));
	build(mid+1, r, rs(pos));
}

void update(ll l, ll r, ll pos, ll x, ll k) {
	if(l == r) {
		t[pos] = k;
		return;
	}
	ll mid = (l + r) >> 1;
	if(x <= mid)
		update(l, mid, ls(pos), x, k);
	else 
		update(mid+1, r, rs(pos), x, k);
	t[pos] = min(t[ls(pos)], t[rs(pos)]);
}

ll query(ll nl, ll nr, ll l, ll r, ll pos) {
	if(nl <= l && r <= nr) {
		return t[pos];
	}
	ll mid = (l + r) >> 1;
	ll res = 1e15;
	if(nl <= mid)
		res = query(nl, nr, l, mid, ls(pos));
	if(mid < nr)
		res = min(res, query(nl, nr, mid+1, r, rs(pos)));
	return res;
}

ll qAns(ll l, ll r) {
	ll pl = lower_bound(e+1, e+1+n, l) - e;
	ll pr = lower_bound(e+1, e+1+n, r) - e;
	ll prr = upper_bound(e+1, e+1+n, r) - e;
	if(pr == prr) pr--;	// 不存在这个数，缩小范围
	else pr = prr-1;	// 存在这个数，找到最大的缩小范围
	
	if(pr > n) pr = n;
	if(pl < 1) pl = 1;
	
	if(pl > pr) return 1e15;
	else return query(pl, pr, 1, n, 1);
}

int main() {
	scanf("%lld %lld %lld", &n, &ge, &re);
	build(1, n, 1);
	mod = ge + re;
	for(ll i = 1; i <= n+1; i++) {
		scanf("%lld", &a[i]);
		mp[i] = mp[i-1] + a[i];
		e[i] = b[i].val = mp[i] % mod;
		b[i].id = i;
	}
	
	sort(e+1, e+1+n, [](const auto &x, const auto &y) {return x < y;});
	sort(b+1, b+1+n, [](const auto &x, const auto &y) {return x.val < y.val;});
	for(ll i = 1; i <= n; i++) b[i].rk = i; 
	sort(b+1, b+1+n, [](const auto &x, const auto &y) {return x.id < y.id;});
	
	
	for(ll i = n; i >= 1; i--) {
		ll ti = mp[i] % mod, mn = 1e15;
		ll l = (ge + ti) % mod, r = (ge + re + ti - 1) % mod;
		if(l > r) {
			mn = qAns(l, mod);
			mn = min(mn, qAns(0, r));
		} else {
			mn = qAns(l, r);
		}
		
		if(mn != 1e15) {
			ll tmp = mp[mn] - mp[i];
			bs[i] = bs[mn] + tmp + (mod - tmp % mod) % mod;
		} else {
			bs[i] = mp[n] - mp[i];
		}
		
		update(1, n, 1, b[i].rk, i);
	}
	
	scanf("%lld", &q);
	
	while(q--) {
		ll ti, t, mn=1e15;
		scanf("%lld", &t);
		ti = t % mod;
		
		ll l = (ge + mod - ti) % mod, r = (ge + re - ti - 1) % mod;
		
		if(l > r) {
			mn = qAns(l, mod);
			mn = min(mn, qAns(0, r));
		} else {
			mn = qAns(l, r);
		}
		
		if(mn != 1e15) {
			ll tmp = t + mp[mn];
			printf("%lld\n", tmp + bs[mn] + a[n+1] + (mod - tmp % mod) % mod);
		} else {
			printf("%lld\n", t + mp[n+1]);
		}
	}
}
