#include <ctime>
#include <cstdio>
#include <random>
using namespace std;
#define ll long long
int main() {
	timeb tb;
	ftime(&tb);
	mt19937 rnd(tb.millitm);
	ll t = 100;
	printf("1 %lld\n", t);
	while(t--) {
		ll n = 1000, m = rnd() % 1000, k = 10;
		printf("%lld %lld %lld\n", n, m, k);
		for(ll i = 1; i <= n; i++) {
			printf("%lld ", rnd() % (1ll<<k));
		}
		printf("\n");
		for(ll i = 1; i <= n; i++) {
			printf("%lld ", rnd() % 2000);
		}
		printf("\n");
	}
	
}
