/**
 * @file A.cpp 
 * @tag: #AtCoder#ABC#ABC336
 * @author: ZnPdCo
 * @date: 2023-12-23 13:55:50
 * @problem: https://atcoder.jp/contests/abc336/tasks/abc336_a
 **/
#include<bits/stdc++.h>
#define ll long long
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
ll a,b;
void solve();
int main() {
	while(Case--) solve();
}
void solve() {
	input(n);
	for(ll i = 1; i <= n; i++) {
		ll k,c;
		input(k, c);
		a += k;
		b += c;
	}
	if(a > b) print("Takahashi");
	if(a == b) print("Draw");
	if(a < b) print("Aoki");
}

