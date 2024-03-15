#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
#define N 410
ll n, p, ans;
ll s[N][N];
ll e[N*N];
ll f[N][N];
ll g[N][N];
ll fac[N], ifac[N];
ll qpow(ll x, ll y) {
	if(y == 0) return 1;
	if(y % 2 == 1) return x * qpow(x, y - 1) % p;
	ll tmp = qpow(x, y / 2);
	return tmp * tmp % p;
}
inline ll C(ll x, ll y) {return fac[x] * ifac[y] % p * ifac[x - y] % p;}

int main() {
	freopen("far.in", "r", stdin);
	freopen("far.out", "w", stdout);
	scanf("%lld %lld", &n, &p);
	
	fac[0] = ifac[0] = 1;
	for(ll i = 1; i <= n; i++)
		fac[i] = fac[i - 1] * i % p;
	
	ifac[n] = qpow(fac[n], p - 2);
	for(ll i = n - 1; i >= 1; i--)
		ifac[i] = ifac[i + 1] * (i + 1) % p;
	
	e[0] = 1;
	for(ll i = 1; i <= n * n; i++)
		e[i] = e[i - 1] * 2 % p;
	
	for(ll i = 1; i <= n; i++)
		for(ll j = 1; j <= n; j++)
			s[i][j] = qpow((e[i] + p - 1) % p, j);
	
	f[1][1] = 1;
	for(ll i = 1; i < n; i++) {
		for(ll j = 1; j <= i; j++) {
			for(ll k = 1; k <= n - i; k++) {
				ll d = C(n - i, k) * s[j][k] % p * e[k * (k - 1) / 2] % p;
				(f[i + k][k] += f[i][j] * d) %= p;
				(g[i + k][k] += (g[i][j] + f[i][j] * (n - i) % p) % p * d % p) %= p;
			}
		}
	}
	
	for(ll i = 1; i <= n; i++) {
		(ans += g[n][i]) %= p;
	}
	
	(ans *= qpow(n - 1, p - 2)) %= p;
	
	printf("%lld", ans);
	return 0;
}
