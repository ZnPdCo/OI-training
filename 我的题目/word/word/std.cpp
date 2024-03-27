#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define N 110
#define M 5
#define P 998244353
ll n, m, k, q;
ll a[M], e[M];
ll ans[N];
ll f[2][600000];
ll dp[2][M];
ll inf, mx;
inline ll zip() {
	ll x = 0;
	ll base = inf + 1;
	for(ll i = 0; i < m; i++) {
		x = x * base + dp[1][i];
	}
	return x;
}
inline void unzip(ll x) {
	ll base = inf + 1;
	for(ll i = m - 1; i >= 0; i--) {
		dp[0][i] = x % base;
		x /= base;
	}
}
int main() {
	scanf("%lld %lld %lld", &n, &m, &k);
	
	for(ll i = 1; i <= m; i ++) {
		scanf("%lld", &a[i]);
		e[i] = a[i];
	}
	sort(e + 1, e + 1 + m);
	for(ll i = 1; i <= m; i++) {
		a[i] = lower_bound(e + 1, e + 1 + m, a[i]) - e;
	}
	
	inf = n / m + 1;
	for(ll i = 0; i < m; i ++) dp[1][i] = inf;	// 获取mx状态
	mx = zip();
	
	dp[1][0] = 0;	// 获取初始状态
	f[0][zip()] = 1;
	
	for(ll i = 1; i <= n; i ++) {
		memset(f[i % 2], 0, sizeof f[i % 2]);
		for(ll s = 0; s <= mx; s ++) {
			if(!f[(i - 1) % 2][s]) continue;
			unzip(s);
			for(ll c = 0; c <= m; c ++) {
				for(ll j = 0; j < m; j ++) {
					dp[1][j] = inf;
				}
				for(ll j = 0; j < m; j ++) {
					ll u = j;
					if(c != a[u + 1]) u = 0;
					if(c == a[u + 1]) u ++;
					if(u < m) dp[1][u] = min(dp[1][u], dp[0][j]);
					dp[1][j] = min(dp[1][j], dp[0][j] + 1);
				}
				if(c == 0) (f[i % 2][zip()] += f[(i - 1) % 2][s] * (k - m) % P) %= P;
				else (f[i % 2][zip()] += f[(i - 1) % 2][s]) %= P;
			}
		}
	}
	
	for(ll s = 0; s <= mx; s ++) {
		if(!f[n % 2][s]) continue;
		unzip(s);
		
		ll mn = inf;
		for(ll j = 0; j < m; j++) {
			mn = min(mn, dp[0][j]);
		}
		
		(ans[mn] += f[n % 2][s]) %= P;
	}
	
	for(ll i = 0; i <= n; i ++) {
		(ans[i] += ans[i - 1]) %= P;
	}
	
	scanf("%lld", &q);
	while(q --) {
		ll x;
		scanf("%lld", &x);
		printf("%lld\n", ans[x]);
	}
}
