#include <cstdio>
#include <random>
#include <ctime>
#define ll long long
using namespace std;
int main() {
	timeb tb;
	ftime(&tb);
	mt19937 rnd(tb.time * 1000 + tb.millitm);
	ll n = rnd() % 10 + 1, k = rnd() % 4;
	printf("%lld %lld\n", n, k);
	for(ll i = 1; i <= k; i++) {
		ll len = rnd() % 3 + 1;
		for(ll j = 1; j <= len; j++) {
			printf("%c", rnd() % 5 + 'a');
		}
		printf("\n");
	}
	ll m = 5;
	printf("%lld\n", m);
	for(ll i = 0; i < 5; i++) {
		printf("%c", i + 'a');
	}
	printf("\n");
}
//#include <cstdio>
//#include <random>
//#include <ctime>
//#define ll long long
//using namespace std;
//int main() {
//	timeb tb;
//	ftime(&tb);
//	mt19937 rnd(tb.time * 1000 + tb.millitm);
//	ll n = 100, k = 8;
//	printf("%lld %lld\n", n, k);
//	for(ll i = 1; i <= k; i++) {
//		ll len = 30;
//		for(ll j = 1; j <= len; j++) {
//			printf("%c", rnd() % 5 + 'a');
//		}
//		printf("\n");
//	}
//	ll m = 10;
//	printf("%lld\n", m);
//	for(ll i = 1; i <= m; i++) {
//		printf("%c", rnd() % 5 + 'a');
//	}
//	printf("\n");
//}
