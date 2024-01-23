/**
 * @file A.cpp 
 * @tag: #AtCoder#ABC#ABC336
 * @author: ZnPdCo
 * @date: 2023-12-23 13:55:50
 * @problem: https://atcoder.jp/contests/abc336/tasks/abc336_a
 **/
#include<bits/stdc++.h>
#define ll long long
#define N 300010
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
ll n, Case=1;
ll a[N];
ll b[N];
ll c[N];
void solve();
int main() {
	while(Case--) solve();
}
void solve() {
	input(n);
	for(ll i = 1; i <= n; i++) {
		input(a[i]);
		if(a[i] == -1) c[1] = i;
		else {
			b[a[i]] = i;
		}
	}
	for(ll i = 2; i <= n; i++) {
		c[i] = b[c[i-1]];
	}
	for(ll i = 1; i <= n; i++) {
		print(c[i]);
	}
}
