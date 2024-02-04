/**
 * @file A.cpp 
 * @tag: #AtCoder#ABC#ABC336
 * @author: ZnPdCo
 * @date: 2023-12-23 13:55:50
 * @problem: https://atcoder.jp/contests/abc336/tasks/abc336_a
 **/
#include<bits/stdc++.h>
#define ll long long
#define N 1000010
#define P 998244353
using namespace std;
void print() {}
template<typename T, typename... Ts>
void print(const T& x, const Ts&... y) {
	cout << x << ' ';
	print(y...);
}
void input() {}
template<typename T, typename... Ts>
void input(T& x, Ts&... y) {
	cin >> x;
	input(y...);
}
ll n, m, Case=1;
ll a[N];
ll f[N];
char s[N];
void solve();
int main() {
	while(Case--) solve();
}

#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
ll t[4*N];
void update(ll x, ll l, ll r, ll pos, ll k) {
	if(l == r) {
		t[pos] = max(t[pos], k);
		return;
	}
	
	ll mid = (l + r) >> 1;
	if(x <= mid) {
		update(x, l, mid, ls(pos), k);
	}
	if(mid < x) {
		update(x, mid+1, r, rs(pos), k);
	}
	t[pos] = max(t[ls(pos)], t[rs(pos)]);
}

ll query(ll nl, ll nr, ll l, ll r, ll pos) {
	if(nl <= l && r <= nr) {
		return t[pos];
	}
	
	ll mid = (l + r) >> 1;
	ll res = 0;
	if(nl <= mid) {
		res = max(res, query(nl, nr, l, mid, ls(pos)));
	}
	if(mid < nr) {
		res = max(res, query(nl, nr, mid+1, r, rs(pos)));
	}
	return res;
}
ll ans = 0;
void solve() {
	input(n, m);
	for(ll i = 1; i <= n; i++) {
		input(a[i]);
	}
	for(ll i = 1; i <= n; i++) {
		f[i] = query(max(a[i]-m, 1ll), min(a[i]+m, 500000ll), 1, 500000ll, 1) + 1;
		update(a[i], 1, 500000ll, 1, f[i]);
		ans = max(ans, f[i]);
	}
	
	print(ans);
}
