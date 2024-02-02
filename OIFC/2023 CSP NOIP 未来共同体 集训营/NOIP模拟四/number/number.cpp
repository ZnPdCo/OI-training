/**
 * @file number.cpp 
 * @tag: #数学
 * @author: ZnPdCo
 * @date: 2023-12-28 12:54:00
 * @problem: https://www.xinyoudui.com/ac/contest/7770019240002AB00F99BF/problem/19061
 **/
#include <cstdio>
#define ll long long
#define N 1000010
#define P 998244353
ll n;
ll ans = 1;
ll qpow(ll x, ll y) {
	if(y == 0) return 1;
	if(y % 2 == 1) return x * qpow(x, y-1) % P;
	ll tmp = qpow(x, y/2);
	return tmp * tmp % P;
}
ll npow, xpow = 1, nfact = 1;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%lld", &n);
	npow = qpow(2, n);
	for(ll i = 1; i <= n; i++) {
		(ans *= ((npow - xpow)%P+P)%P) %= P;
		(xpow *= 2) %= P;
		(nfact *= i) %= P;
	}
	(ans *= qpow(nfact, P-2)) %= P;
	printf("%lld", ans);
}

