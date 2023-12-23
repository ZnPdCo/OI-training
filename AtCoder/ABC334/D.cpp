/**
 * @file D.cpp
 * @tag: #AtCoder#ABC#ABC334
 * @author: ZnPdCo
 * @date: 2023-12-23 19:50:12
 * @problem: https://atcoder.jp/contests/abc334/tasks/abc334_d
 **/
#include <bits/stdc++.h>
#define ll long long
#define N 200010
#define debug() printf("debug");
#define newll(x) ll x = 0
#define newarr(x) ll x[N] = {0}
#define newvis(x) bool x[N] = {0}
#define outt printf
#define inn scanf
using namespace std;
ll n, m, Case=1;
ll a[N];
ll s[N];
void solve();
int main() {
	while(Case--) solve();
}
bool cmp(ll x, ll y) {
	return x < y;
}
void solve() {
	inn("%lld %lld", &n, &m);
	for(ll i = 1; i <= n; i++) {
		inn("%lld", &a[i]);
	}
	sort(a+1, a+1+n, cmp);
	for(ll i = 1; i <= n; i++) {
		s[i] = s[i-1] + a[i];
	}
	while(m--) {
		ll q;
		inn("%lld", &q);
		ll l = 1, r = n, ans = 0;
		while(l <= r) {
			ll mid = (l + r) >> 1;
			if(s[mid] <= q) {
				ans = mid;
				l = mid+1;
			} else {
				r = mid-1;
			}
		}
		outt("%lld\n", ans);
	}
}
