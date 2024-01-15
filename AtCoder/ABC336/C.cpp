/**
 * @file C.cpp 
 * @tag: #AtCoder#ABC#ABC336
 * @author: ZnPdCo
 * @date: 2023-12-23 13:55:50
 * @problem: https://atcoder.jp/contests/abc336/tasks/abc336_c
 **/
#include<bits/stdc++.h>
#define ll long long
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
void solve();
int main() {
	while(Case--) solve();
}
ll dfs(ll x) {
	if(!x) return 0;
	return x%5+10*dfs(x/5);
}
void solve() {
	input(n);
	ll res = dfs(n-1);
	print(res*2);
}
