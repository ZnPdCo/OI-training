#include <cstdio>
#define ll long long
ll n, m, len;
ll a[1000010];
ll b[1000010];
int main() {
	scanf("%lld %lld", &n, &m);
	len = n;
	for(ll i = 1; i <= n; i++) a[i] =i;
	while(m--) {
		char op[10]; ll l, r;
		scanf("%s %lld %lld", op, &l, &r);
		if(op[0] == 'D') {
			ll cnt = 0;
			for(ll i = 1; i < l; i++) b[++cnt] = a[i];
			for(ll i = l; i <= r; i++) {
				b[++cnt] = a[i];
				b[++cnt] = a[i];
			}
			for(ll i = r+1; i <= len; i++) {
				b[++cnt] = a[i];
			}
			len = cnt;
			for(ll i = 1; i <= len; i++) {
				a[i] = b[i];
			}
		} else if(op[0] == 'Q') {
			ll ans = 0, cnt = 0;
			for(ll i = l; i <= r; i++) {
				if(a[i] != a[i-1] || i == l) {
					if(cnt > ans) ans = cnt;
					cnt = 1;
				} else cnt++;
			}
			if(cnt > ans) ans = cnt;
			printf("%lld\n", ans);
		}
	}
}
