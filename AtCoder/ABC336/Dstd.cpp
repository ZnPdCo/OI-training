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
struct node {
	ll val, pos;
} s[N], g[N];
void solve();
int main() {
	while(Case--) solve();
}

void solve() {
	input(n);
	for(ll i = 1; i <= n; i++) {
		input(a[i]);
	}
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= a[i]; j++) {
			bool flag = true;
			for(ll k = 1; k <= j; k++) {
				if(a[i-j+k] < k) flag = false;
				if(a[i+j-k] < k) flag = false;
			}
			if(flag) {
				ans = max(ans, j);
			}
		}
	}
	print(ans);
}
