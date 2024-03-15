#include <random>
#include <cstdio>
#include <ctime>
#define ll long long
using namespace std;
mt19937 rnd(time(0));
int main() {
	ll n = 10;
	printf("%lld\n", n);
	for(ll i = 1; i <= n; i++) {
		printf("%lld ", rnd() % 6+1);
	}	
	ll q = 10;
	printf("\n%lld\n", q);
	for(ll i = 1; i <= q; i++) {
		ll op = rnd() % 2;
		if(op == 0) {
			ll l = rnd() % n+1;
			ll r = rnd() % n+1;
			ll x = rnd() % 6+1;
			if(l > r) swap(l, r);
			printf("%lld %lld %lld %lld\n", op, l, r, x);
		} else {
			ll l = rnd() % n+1;
			ll r = rnd() % n+1;
			if(l > r) swap(l, r);
			printf("%lld %lld %lld\n", op, l, r);
		}
	}	
}
