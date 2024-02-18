#include <cstdio>
#include <random>
#include <ctime>
#define ll long long
ll n = 100000, g=400000015, r=425124110, q=100000;
int main() {
	timeb tb;
	ftime(&tb);
	
	std::mt19937 rnd(tb.millitm);
	printf("%lld %lld %lld\n", n, g, r);
	for(ll i = 1; i <= n; i++) {
		printf("%lld ", rnd() % 1000000+1);
	}
	printf("\n%lld\n", q);
	for(ll i = 1; i <= q; i++) {
		printf("%lld\n", rnd() % 1000000+1);
	}
}
