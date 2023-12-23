#include <cstdio>
#include <random>
#define ll long long
#define N 100010
using namespace std;
ll n, m;
int main() {
	timeb ft;
	ftime(&ft);
	mt19937 rnd(ft.millitm);
//	n = 100000;
//	m = 100000;
	n = 10, m = 10;
	printf("%lld %lld\n", n, m);
	for(ll i = 1; i <= m; i++) {
		ll l = rnd() % n + 1;
		ll r;
//		if(rnd() % 10 == 0) r = min(l + rnd() % 100000000, n);
//		else r = min(l + rnd() % 100, n);
		if(rnd() % 10 == 0) r = min(l + rnd() % 10, n);
		else r = min(l + rnd() % 10, n);
		if(rnd() % 2) {
			printf("D %lld %lld\n", l, r);
		} else {
			printf("Q %lld %lld\n", l, r);
		}
	}
}
