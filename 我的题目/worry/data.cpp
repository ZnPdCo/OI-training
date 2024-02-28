#include <random>
#include <cstdio>
#include <ctime>
#define ll long long
using namespace std;
int main() {
	timeb tb;
	ftime(&tb);
	mt19937 rnd(tb.millitm);
	ll n = rnd() % 1000 + 1;
	ll m = rnd() % 1000 + 1;
	ll k = rnd() % 1000 + 1;
	ll g = rnd() % 10 + 1;
	printf("%lld %lld %lld %lld", n, m, k, g);
}
