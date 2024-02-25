#include <cstdio>
#define ll long long
ll t, n;
ll H(ll n) {
	ll res = 0;
	for(ll l = 1, r = 0; l <= n; l = r + 1) {
		r = n / (n / l);
		res += (r - l + 1) * (n / l);
	}
	return res;
}
int main() {
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld", &n);
		printf("%lld\n", H(n));
	}
}
