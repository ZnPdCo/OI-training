/**
 * @file 微信步数.cpp 
 * @tag: #GMOJ#推式子#插值
 * @author: ZnPdCo
 * @date: 2024-01-18 20:43:55
 * @problem: https://gmoj.net/senior/#main/show/6925
 **/
#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
#define K 20
#define N 500010
#define P 1000000007
ll n, k, ans = 1;
ll w[K];
ll c[N], d[N];

ll l[K], r[K], p[K], a[K];

ll f[N][K], g[N];

ll t;

inline ll fun(ll x) {
	return (x % P + P) % P;
}

ll qpow(ll x, ll y) {
	if(y == 0) return 1;
	if(y % 2 == 1) return x * qpow(x, y - 1) % P;
	ll tmp = qpow(x, y/2);
	return tmp * tmp % P;
}

ll calc(ll x) {
	if(x <= k+1) return g[x];
	ll res = 0;
	for(ll i = 0; i <= k+1; i++) {
		ll s = g[i];
		for(ll j = 0; j <= k+1; j++) {
			if(i == j) continue;
			(s *= fun(x - j) * qpow(fun(i - j), P - 2) % P) %= P;
		}
		(res += s) %= P;
	}
	return res;
}

int main() {
//	freopen("C:\\Users\\Administrator\\Downloads\\walk7.in", "r", stdin);
//	freopen("walk.in", "r", stdin);
//	freopen("walk.out", "w", stdout);
	
	scanf("%lld %lld", &n, &k);
	for(ll i = 1; i <= k; i++) {
		scanf("%lld", &w[i]);
	}
	for(ll i = 1; i <= n; i++) {
		scanf("%lld %lld", &c[i], &d[i]);
	}
	for(ll i = 1; i <= k; i++) {
		(ans *= w[i]) %= P;
	}
	
	// 第一轮
	for(ll i = 1; i <= n; i++) {
		p[c[i]] += d[i];
		l[c[i]] = min(l[c[i]], p[c[i]]);
		r[c[i]] = max(r[c[i]], p[c[i]]);
		if(r[c[i]] - l[c[i]] > w[c[i]]) {
			return printf("%lld", ans), 0;
		}
		ll s = 1;
		for(ll j = 1; j <= k; j++) {
			(s *= (w[j] - (r[j] - l[j]))) %= P;
		}
		(ans += s) %= P;
	}
	
	for(ll i = 1; i <= k; i++) {
		a[i] = p[i];
	}
	
	// 无限
	bool forever = true;
	for(ll i = 1; i <= k; i++) {
		if(p[i] != 0) {
			forever = false;
			break;
		}
		if(r[i] - l[i] >= w[i]) {
			forever = false;
			break;
		}
	}
	if(forever) {
		return printf("-1"), 0;
	}
	
	// 第二轮
	for(ll i = 1; i <= n; i++) {
		p[c[i]] += d[i];
		for(ll j = 1; j <= k; j++) f[i][j] = f[i-1][j];
		
		if(a[c[i]] > 0) {	// 每次向右移动
			f[i][c[i]] = max(f[i][c[i]], p[c[i]] - r[c[i]]);
		} else {			// 每次向左移动
			f[i][c[i]] = max(f[i][c[i]], l[c[i]] - p[c[i]]);
		}
	}
	
	for(ll i = 1; i <= k; i++) {
		w[i] -= (r[i] - l[i]);
		a[i] = abs(a[i]);
	}
	
	t = 1e15;
	
	for(ll i = 1; i <= k; i++) {
		if(a[i]) t = min(t, w[i] / a[i]);
	}
	
	for(ll x = 1; x <= k+1; x++) {
		ll sum = 0;
		for(ll i = 1; i <= n; i++) {
			ll s = 1;
			for(ll j = 1; j <= k; j++) {
				s = ((s * (w[j] - (x-1) * a[j] % P - f[i][j])) % P + P) % P;
			}
			(sum += s) %= P;
		}
		g[x] = (g[x - 1] + sum) % P;
	}
	
	(ans += calc(t)) %= P;
	
	
	for(ll i = 1; i <= k; i++) {
		w[i] -= t * a[i];
	}
	
	for(ll i = 1; i <= n; i++) {
		if(f[i][c[i]] > w[c[i]]) break;
		ll s = 1;
		for(ll j = 1; j <= k; j++) {
			(s *= (w[j] - f[i][j])) %= P;
		}
		(ans += s) %= P;
	}
	
	printf("%lld", ans);
	return 0;
}
