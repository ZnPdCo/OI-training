#include <cstdio>
#include <random>
#define ll long long
#define N 100010
using namespace std;
ll n, k;
int main() {
	timeb ft;
	ftime(&ft);
	mt19937 rnd(ft.millitm);
	n = rnd() % 10000 + 1;
	k = rnd() % 10000;
	printf("%lld %lld\n", n, k);
	for(ll i = 1; i <= n; i++) {
		printf("%lld ", rnd() % n);
	}
}
