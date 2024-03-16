#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 200010
ll n, m, k, ans;
char a[N], b[N];
ll s[N][4];
int main() {
	freopen("base.in", "r", stdin);
	freopen("base.out", "w", stdout);
	scanf("%lld %s %s", &k, a, b);
	n = strlen(a);
	m = strlen(b);
	for(ll i = 0; i < n; i ++) {
		if(a[i] == 'Z') a[i] = 0;
		if(a[i] == 'P') a[i] = 1;
		if(a[i] == 'S') a[i] = 2;
		if(a[i] == 'B') a[i] = 3;
	}
	for(ll i = 0; i < m; i ++) {
		if(b[i] == 'Z') b[i] = 0;
		if(b[i] == 'P') b[i] = 1;
		if(b[i] == 'S') b[i] = 2;
		if(b[i] == 'B') b[i] = 3;
	}
	for(ll i = 0; i < n; i ++) {
		if(i > 0) {
			for(ll j = 0; j < 4; j++) s[i][j] = s[i - 1][j];
		}
		s[i][a[i]] ++;
	}
	for(ll i = 0; i < 4; i++) {
		if(s[n - 1][i] == n) {
			bool flag = 1;
			for(ll j = 0; j < m; j++) {
				if(b[j] != i) {
					flag = 0;
				}
			}
			if(flag) {
				return printf("%lld", n - m + 1), 0;
			}
		}
	}
	for(ll p = 0; p <= n - m; p ++) {
		bool flag = 1;
		for(ll i = m - 1; i >= 0; i--) {
			ll l = max(p + i - k, 0ll);
			ll r = min(p + i + k, n - 1);
			ll num = (l == 0ll) ? s[r][b[i]] : s[r][b[i]] - s[l - 1][b[i]];
			if(!num) {
				flag = 0;
				break;
			}
		}
		ans += flag;
	}
	printf("%lld", ans);
}
