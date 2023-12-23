#include <random>
#include <ctime>
#define ll long long
#include <cstdio>
using namespace std;
mt19937 rnd(time(0));
int main() {
	ll n = rnd() % 100 + 1700, k = 10;
	printf("%lld %lld", n, k);
}
