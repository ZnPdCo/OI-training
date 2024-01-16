#include <cstdio>
#include <random>
#include <ctime>
#define ll long long
ll fa[110];
ll find(ll x) {
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
int main() {
	timeb tb;
	ftime(&tb);
	std::mt19937 rnd(tb.millitm);
	ll n = 5;
	printf("%lld\n", n);
	for(ll i = 1; i <= n; i++) {
		printf("%lld ", rnd() % 5 + 1);
	}
	ll m = 100;
	for(ll i = 0; i <= m; i++)
		fa[i] = i;
	printf("\n%lld\n", m);
	for(ll i = 1; i <= m; i++) {
		ll t = rnd() % 3 + 1;
		printf("%lld ", t);
		if(t == 1) {
			printf("%lld %lld\n", rnd() % n+1, rnd() % 5+1);
		}
		if(t == 2) {
			printf("%lld\n", rnd() % 5+1);
		}
		if(t == 3) {
			ll c = rnd() % 2+1;
			printf("%lld ", c);
			for(ll j = 1; j <= c; j++) {
				ll a;
				for(ll k = 1; k <= m; k++) {
					a = k;
					if(find(a) != find(i)) break;
				}
				if(find(a) == find(i)) {
					return 0&printf("-1");
				}
				fa[find(i)] = find(a);
				printf("%lld ", a);
			}
			printf("\n");
		}
	}
	ll q = 1;
	ll a;
	for(ll j = 1; j <= q; j++) {
		for(ll k = 1; k <= m; k++) {
			a = k;
			if(find(a) != find(0)) break;
		}
		if(find(a) == find(0)) return 0&printf("0");
		fa[find(0)] = find(a);
	}
	printf("%lld\n%lld", q, a);
}
