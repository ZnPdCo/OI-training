#include <cstdio>
#include <ctime>
#include <random>
#define ll long long
using namespace std;
ll t = 5;
int main() {
	timeb tb;
	ftime(&tb);
	mt19937 rnd(tb.millitm);
	printf("%lld\n", t);
	while(t--) {
		ll n = 10, m = 5, k = 4;
		printf("%lld %lld %lld\n", n, m, k);
		for(ll i = 1; i <= m; i++) {
			for(ll j = 1; j <= k; j++) {
				printf("%lld ", rnd() % 10 + 1);
			}
			printf("\n");
		}
	}
}
