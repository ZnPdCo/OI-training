#include <cstdio>
#define ll long long
#define N 1000010
ll n, m, c, k, old;
unsigned __int128 sum, buy;
unsigned __int128 ans = 0;
ll p[N];
ll q[N];
void print(unsigned __int128 x) {
	if(x >= 10) print(x / 10);
	putchar(x % 10 + '0');
}
int main() {
	scanf("%lld %lld %lld %lld", &n, &m, &c, &k);
	for(ll i = 1; i <= n; i++) {
		ll a;
		scanf("%lld", &a);
		sum |= a;
	}
	for(ll i = 1; i <= m; i++) {
		scanf("%lld %lld", &p[i], &q[i]);
		if(sum & (1<<p[i])) {
			old++;
		}
	}
	for(ll i = 0; i < (1<<k); i++) {
		unsigned __int128 tmp = sum | i;
		ll num = 0;
		for(ll i = 1; i <= m; i++) {
			if(tmp & (1<<p[i])) {
				num++;
			}
		}
		if(num == old) ans++;
	}
	ans -= n;
	print(ans);
}
