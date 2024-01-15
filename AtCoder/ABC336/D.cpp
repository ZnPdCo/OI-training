/**
 * @file D.cpp 
 * @tag: #AtCoder#ABC#ABC336
 * @author: ZnPdCo
 * @date: 2023-12-23 13:55:50
 * @problem: https://atcoder.jp/contests/abc336/tasks/abc336_d
 **/
#include<bits/stdc++.h>
#define ll long long
#define N 200010
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
ll n, m, Case=1, ans;
ll a[N];
ll s[N], g[N];
void solve();
int main() {
	while(Case--) solve();
}

void solve() {
	input(n);
	s[0] = 0;
	for(ll i = 1; i <= n; i++) {
		input(a[i]);
		s[i] = s[i-1];
		if(i - a[i] + 1 >= s[i]) {
			s[i] = i - a[i] + 1;
		}
	}
	g[n+1] = 1e15;
	for(ll i = n; i >= 1; i--) {
		g[i] = g[i+1];
		if(i + a[i] - 1 <= g[i]) {
			g[i] = i + a[i] - 1;
		}
	}
	for(ll i = 1; i <= n; i++) {
		ll left = max(s[i], 1ll);
		ll right = min(g[i], n);
		ans = max(ans, min(i-left+1, right-i+1));
	}
	print(ans);
}
