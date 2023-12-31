#include <random>
#include <ctime>
#include <cstdio>
using namespace std;
#define ll long long
ll n;
int main() {
	timeb tb;
	ftime(&tb);
	mt19937 rnd(tb.millitm);
	n = 200;
	printf("%lld\n", n);
	for(ll i = 1; i <= n; i++) {
		printf("%lld %lld\n", rnd() % 100+1, rnd() % 100+1);
	}
}
