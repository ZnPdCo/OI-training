#include <cstdio>
#include <ctime>
#include <random>
#define ll long long
using namespace std;
ll n, m;
int main() {
	timeb tb;
	ftime(&tb);
	mt19937 rnd(tb.millitm);
	n = rnd() % 10000+1, m = rnd() % 200000+1;
	printf("%lld %lld\n", n, m);
	for(ll i = 1; i <= m; i++) {
		printf("%lld %lld\n", rnd() % n+1, rnd() % n+1);
	}
	printf("%lld %lld", rnd() % n+1, rnd() % n+1);
}
