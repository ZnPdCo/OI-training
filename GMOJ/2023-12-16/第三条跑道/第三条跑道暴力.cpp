#include <cstdio>
#define ll long long
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define N 10010
#define M 600000
#define P 100000007
ll n, q;
ll phi[M+10];
bool flag[M+10];
ll prime[M+10], cnt;
ll a[N];
void init() {
	phi[1] = 1;
	for(ll i = 2; i <= M; i++) {
		if(flag[i] == 0) {
			phi[i] = i-1;
			prime[++cnt] = i; 
		}
		for(ll j = 1; j <= cnt && i*prime[j] <= M; j++) {
			flag[i*prime[j]] = 1;
			if(i % prime[j] == 0) {
				phi[i*prime[j]] = phi[i] * prime[j];
				break;
			}
			phi[i*prime[j]] = phi[i] * phi[prime[j]];
		}
	}
}
int main() {
	init();
	scanf("%lld", &n);
	for(ll i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	scanf("%lld", &q);
	for(ll i = 1; i <= q; i++) {
		ll op, l, r, x;
		scanf("%lld %lld %lld", &op, &l, &r);
		if(op == 0) {
			scanf("%lld", &x);
			for(ll j = l; j <= r; j++) {
				a[j] *= x;
			}
		} else {
			ll ans = 1;
			for(ll j = l; j <= r; j++) {
				(ans *= phi[a[j]]) %= P;
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}
/*
10
4 4 4 6 5 5 1 3 6 3
3
0 2 10 4
0 7 10 4
1 10 10
 */
