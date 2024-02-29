#include <cstdio>
#include <ctime>
#include <random>
#include <algorithm>
using namespace std;
#define ll long long
int main() {
	timeb tb;
	ftime(&tb);
	mt19937 rnd(tb.millitm);
	ll n = 10, m = 3;
	printf("%lld %lld\n", m, n);
	for(ll i = 1; i <= m; i++) {
		ll l = rnd() % n + 1;
		ll r = l + rnd() % (n - l) / 2 * 2;
		if(l > r) swap(l, r);
		n -= (r - l) / 2 + 1;
		printf("%lld %lld\n", l, r);
	}
}
