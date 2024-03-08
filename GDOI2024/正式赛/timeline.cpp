#include <cstdio>
#define ll long long
#define N 15*15
#define P 1000000007
ll n, m, k;
struct node {
	ll u, v;
} a[N];
ll qpow(ll x, ll y) {
	if(y == 0) return 1;
	if(y % 2 == 1) return x * qpow(x, y - 1) % P;
	ll tmp = qpow(x, y / 2);
	return tmp * tmp % P;
}
ll C(ll x, ll y) {
	ll res = 1;
	for(ll i = 1; i <= y; i++) {
		(res *= (x - i + 1)) %= P;
	}
	for(ll i = 1; i <= y; i++) {
		(res *= qpow(i, P-2)) %= P;
	}
	return res;
}
namespace bf {
	void solve() {
		
	}
}
namespace m0 {
	void solve() {
		printf("1");
	}
}
namespace B {
	void solve() {
		ll ans = qpow(n, P-2) * (n-1) % P;
		for(ll i = 1; i <= k; i++) {
			(ans *= (n+i-1) * qpow(n+i, P - 2) % P) %= P;
		}
		printf("%lld", 1+P-ans);
	}
}
int main() {
	freopen("timeline.in", "r", stdin);
	freopen("timeline.out", "w", stdout);
	scanf("%lld %lld %lld", &n, &m, &k);
	bool isB = 1;
	for(ll i = 1; i <= m; i++) {
		scanf("%lld %lld", &a[i].u, &a[i].v);
		if(a[i].u != 1) isB = 0;
	}
	if(m == 0) m0::solve();
	if(isB) B::solve();
}
