#include <random>
#include <ctime>
using namespace std;
#include <cstdio>
#define ll long long
int main() {
	timeb tb;
	ftime(&tb);
	mt19937 rnd(tb.millitm);
	ll n = rnd() % 10+1, m = rnd() % 10, u = rnd()%10+1, v = rnd()%10+1, q = rnd()%10+1, t = rnd()%3+1;
	if(u > v) swap(u, v);
	printf("%lld %lld %lld %lld %lld %lld\n", n, m, q, u, v, t);
	for(ll i = 1; i <= n; i++) {
		printf("%lld ", rnd() % 10);
	}
}
