#include <cstdio>
#include <random>
#include <ctime>
#include <climits>
#define ll long long
using namespace std;
mt19937_64 rnd(time(0));
int main() {
	freopen("in.in", "w", stdout);
	ll n = 100, m = 1000000;
	printf("%lld %lld\n", n, m);
	ll sum = 0;
	for(ll i = 0; i < n; i++) {
		ll x = rnd() * (rnd()%2==0?-1ll:1ll);
		printf("%lld ", x);
		sum += x;
	}
	printf("%lld", -sum);
}
