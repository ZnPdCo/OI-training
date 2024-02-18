#include <cstdio>
#define ll long long
#define N 100010
ll t, n, m, mx1, mn2;
ll a[N], b[N], c[N], v[N];
void dfs(ll x) {
	if(x > n) {
		ll tmp = m, mo=0, ans1=0, ans2=0;
		for(ll i = 1; i <= n; i++) {
			if(mo) {
				mo--;
				mo += b[c[i]];
				ans1++;
			} else if(tmp >= a[c[i]]) {
				ans2 += a[c[i]];
				ans1++;
				mo += b[c[i]];
				tmp -= a[c[i]];
			} else break;
		}
		if(ans1 > mx1) mx1=ans1, mn2 = ans2;
		else if(ans1 == mx1) {
			if(ans2 < mn2) {
				mn2 = ans2;
			}
		}
		return;
	}
	for(ll i = 1; i <= n; i++) if(!v[i]) {
		v[i] = 1;
		c[x] = i;
		dfs(x+1);
		v[i] = 0;
	}
}
int main() {
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld %lld", &n, &m);
		for(ll i = 1; i <= n; i++) {
			scanf("%lld %lld", &a[i], &b[i]);
		}
		mx1 = 0, mn2=m;
		dfs(1);
		printf("%lld %lld\n", mx1, mn2);
	}
}
