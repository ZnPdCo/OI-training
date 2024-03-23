#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
#define P 998244353
#define N 4000010
ll n, m;
ll f[N], g[N];
ll siz = 1, l;
ll r[N];
ll G = 3, Gi, si;
ll qpow(ll x, ll y) {
	if(y == 0) return 1;
	if(y % 2 == 1) return qpow(x, y - 1) * x % P;
	ll tmp = qpow(x, y / 2);
	return tmp * tmp % P;
}
void ntt(ll *a, ll type) {
	for(ll i = 0; i < siz; i++) {
		if(i < r[i]) swap(a[i], a[r[i]]);
	}
	for(ll x = 2; x <= siz; x <<= 1) {
		ll wn = qpow(type == 1 ? G : Gi, (P - 1) / x);
		for(ll i = 0; i < siz; i += x) {
			ll w = 1;
			for(ll j = 0; j < (x >> 1); j++, w = w * wn % P) {
				ll A = a[i + j], B = a[i + (x >> 1) + j];
				a[i + j] = ((A + w * B) % P + P) % P;
				a[i + (x >> 1) + j] = ((A - w * B) % P + P) % P;
			}
		}
	}
}
int main() {
	Gi = qpow(G, P - 2);
	scanf("%lld %lld", &n, &m);
	for(ll i = 0; i <= n; i ++) {
		scanf("%lld", &f[i]);
		f[i] = (f[i] % P + P) % P;
	}
	for(ll i = 0; i <= m; i ++) {
		scanf("%lld", &g[i]);
		g[i] = (g[i] % P + P) % P;
	}
	while(siz <= n + m) siz <<= 1, l ++;
	si = qpow(siz, P - 2);
	for(ll i = 1; i < siz; i++) {
		r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
	}
	ntt(f, 1);
	ntt(g, 1);
	for(ll i = 0; i < siz; i++) {
		f[i] = f[i] * g[i] % P;
	}
	ntt(f, -1);
	for(ll i = 0; i <= n + m; i++) {
		printf("%lld ", f[i] * si % P);
	}
}
