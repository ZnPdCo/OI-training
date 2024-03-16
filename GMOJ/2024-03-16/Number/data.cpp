#include <cstdio>
#include <random>
using namespace std;
#define ll long long
mt19937 rnd(1145141);
int main() {
	ll n = 100;
	printf("%lld\n", n);
	for(ll i = 1; i <= n; i++) {
		ll len = rnd() % 3 + 3;
		for(ll j = 1; j <= len; j++) {
			printf("%lld", rnd() % 10);
		}
		printf("\n");
	}
}

