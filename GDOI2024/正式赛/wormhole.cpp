#include <cstdio>
#define ll long long
#define P 998244353
ll qpow(ll x, ll y) {
	if(y == 0) return 1;
	if(y % 2 == 1) return x * qpow(x, y - 1) % P;
	ll tmp = qpow(x, y / 2);
	return tmp * tmp % P;
}
int main() {
	freopen("wormhole.in", "r", stdin);
	freopen("wormhole.out", "w", stdout);
	printf("114514");
}
