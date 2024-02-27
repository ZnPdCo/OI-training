#include <cstdio>
#include <ctime>
#include <random>
#define ll long long
using namespace std;
ll n = 100, x = 0;
int main() {
	timeb tb;
	ftime(&tb);
mt19937 rnd(tb.millitm);
	printf("%lld\n", n);
	for(ll i = 1; i <= n; i++) {
		x = x + rnd() % 4 + 1;
		printf("%lld %lld\n", x, rnd() % 3 + 1);
	}
}
