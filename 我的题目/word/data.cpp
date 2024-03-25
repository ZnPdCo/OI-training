#include <random>
#include <ctime>
#include <cstdio>
#define ll long long
using namespace std;
int main() {
	timeb tb;
	ftime(&tb);
	mt19937 rnd(tb.millitm);
	
	ll n = 8, m = 4, k = 5;
	printf("%lld %lld %lld\n", n, m, k);
	for(ll i = 1; i <= m; i ++) {
		printf("%lld ", i);
	}
	printf("\n%lld\n", n);
	for(ll i = 1; i <= n; i ++) {
		printf("%lld\n", i);
	}
}
