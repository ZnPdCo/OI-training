/**
 * @file C.cpp
 * @tag: #AtCoder#ABC#ABC334
 * @author: ZnPdCo
 * @date: 2023-12-23 19:50:12
 * @problem: https://atcoder.jp/contests/abc334/tasks/abc334_c
 **/
#include <bits/stdc++.h>
#define ll long long
#define N 400010
#define debug() printf("debug");
#define newll(x) ll x = 0
#define newarr(x) ll x[N] = {0}
#define newvis(x) bool x[N] = {0}
#define outt printf
#define inn scanf
using namespace std;
ll n, m, Case=1, ans;
ll a[N], b[N], cnt;
ll f[N], h[N];
void solve();
int main() {
	while(Case--) solve();
}
void solve() {
	inn("%lld %lld", &n, &m);
	ll lst = 0;
	for(ll i = 1; i <= m; i++) {
		inn("%lld", &a[i]);
		for(ll j = lst+1; j < a[i]; j++) {
			b[++cnt] = j;
			b[++cnt] = j;
		}
		b[++cnt] = a[i];
		lst = a[i];
	}
	for(ll j = lst+1; j <= n; j++) {
		b[++cnt] = j;
		b[++cnt] = j;
	}
	if(cnt % 2 == 1) {
		for(ll i = 1; i <= cnt; i+=2) {
			f[i+1] = f[i-1] + (b[i+1] - b[i]);
		}
		for(ll i = cnt; i >= 1; i-=2) {
			h[i-1] = h[i+1] + (b[i] - b[i-1]);
		}
		ans = 1e15;

		for(ll i = 1; i <= cnt; i+=2) {
			ans = min(ans, f[i-1]+h[i+1]);
		}
		outt("%lld", ans);
	} else {
		for(ll i = 1; i <= cnt; i+=2) {
			ans += b[i+1] - b[i];
		}
		outt("%lld", ans);
	}
}
