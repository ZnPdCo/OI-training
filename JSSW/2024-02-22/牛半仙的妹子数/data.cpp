#include <cstdio>
#include <random>
#include <ctime>
#define ll long long
using namespace std;
mt19937 rnd(time(0));
int main() {
	freopen("sam.in","w", stdout);
	ll t = 100000;
	printf("%lld\n", t);
	while(t--) {
		ll a = rnd() % 10000 + (1000000000 - 10000);
		ll b = rnd() % 10000 + (1000000000 - 10000);
		ll c = rnd() % 10000 + (1000000000 - 10000);
		ll k = rnd() % 10000 + (1000000000 - 10000);
		printf("%lld %lld %lld %lld\n", a, b, c, k);
	}
}
