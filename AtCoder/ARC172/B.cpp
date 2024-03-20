#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
#define P 998244353
ll n, k, l, ans = 1;
int main() {
	scanf("%lld %lld %lld", &n, &k, &l);
	if(n - k > l) return printf("0"), 0;
	for(ll i = 1; i <= n; i++) {
		(ans *= l - min(i - 1, n - k)) %= P;
	}
	printf("%lld", ans);
}
