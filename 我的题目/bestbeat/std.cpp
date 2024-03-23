#include <cstdio>
#include <cstring>
#define ll long long
#define M 1010
#define K 10
ll n, m, k;
ll x[M], y[M];
ll c[K];
ll u, q;
ll f[2][1<<K];
ll dp[2][K + 5];
inline void unzip(ll s) {
	dp[0][0] = 0;
	for(ll i = 1; i <= k; i++) {
		dp[0][i] = (s >> (i - 1)) & 1;
	}
}
int main() {
	scanf("%lld %lld %lld", &n, &m, &k);
	for(ll i = 1; i <= m; i ++) {
		scanf("%lld", &x[i]);
	}
	for(ll i = 1; i <= k; i ++) {
		scanf("%lld", &c[i]);
	}
	for(ll i = 1; i <= m; i ++) {
		scanf("%lld", &y[i]);
	}
	scanf("%lld %lld", &u, &q);
	for(ll i = 1; i <= q; i ++) {
		
	}
	f[0][0] = 1;
	for(ll i = 1; i <= m; i ++) {
		memset(f[i % 2], 0, sizeof f[i % 2]);
		for(ll s = 0; s < (1 << k); s ++) {
			if(!f[(i - 1) % 2][s]) continue;
			unzip(s);
		}
	}
}
