#include <cstdio>
#include <ctime>
#include <random>
#define ll long long
int main() {
	timeb tb;
	ftime(&tb);
	std::mt19937 rnd(tb.millitm);
	ll n = 100;
	printf("%lld\n", n);
	for(ll i = 1; i <= n; i++) {
		printf("%lld ", rnd() % 100+1);
	}
}
