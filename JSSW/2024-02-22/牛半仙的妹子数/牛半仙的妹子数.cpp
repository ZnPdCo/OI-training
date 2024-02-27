#include <cstdio>
#define ll long long
ll t, k, a, b, c, mod;
ll qpow(ll x, ll y) {
	if(y == 0) return 1;
	if(y % 2 == 1) return x * qpow(x, y-1) % mod;
	ll tmp = qpow(x, y/2);
	return tmp * tmp % mod;
}
int main() {
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld %lld %lld %lld", &a, &b, &c, &k);
		mod = a+b+c;
		printf("%lld\n", c * qpow(2, k) % mod);
	}
}
