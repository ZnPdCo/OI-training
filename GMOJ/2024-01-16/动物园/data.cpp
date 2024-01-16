#include <cstdio>
#include <random>
#define ll long long
ll vis[10000000];
int main() {
	ll seed;
	scanf("%lld", &seed);
	std::mt19937 rnd(seed);
	ll k = rnd() % 20 + 1;
	ll n = rnd() % std::min((1ll<<k)+1, 1000ll), m = rnd() % std::min(k, 20ll), c = 114514;
	printf("%lld %lld %lld %lld\n", n, m, c, k);
	for(ll i = 1; i <= n; i++) {
		ll a ;
		while(true) {
			a = rnd() % (1<<k);
			if(!vis[a]) break;
		}
		vis[a] = 1;
		printf("%lld ", a);
	}
	printf("\n");
	for(ll i = 1; i <= m; i++) {
		ll a = rnd() % k;
		printf("%lld 114514\n", a);
	}
}
