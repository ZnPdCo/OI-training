#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
ll n, k;
ll G(ll n, ll k) {
	ll res = n * k;
	for(ll l = 1, r = 0; l <= min(k, n); l = r + 1) {
		r = k / (k / l);
		if(r > n) r = n;
		res -= (l + r) * (r - l + 1) / 2 * (k / l);
	}
	return res;
}
int main() {
	scanf("%lld %lld", &n, &k);
	printf("%lld", G(n, k));
}
