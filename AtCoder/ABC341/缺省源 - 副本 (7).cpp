/**
 * @file A.cpp 
 * @tag: #AtCoder#ABC#ABC336
 * @author: ZnPdCo
 * @date: 2023-12-23 13:55:50
 * @problem: https://atcoder.jp/contests/abc336/tasks/abc336_a
 **/
#include<bits/stdc++.h>
#define ll long long
#define N 1010 10010 100010 1000010
#define M 
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
ll a[N][M];
char s[N];
void solve();
int main() {
	input(Case);
	while(Case--) solve();
}
void solve() {
	input(n, m);
	for(ll i = 1; i <= n; i++) {
		input(a[i]);
		for(ll j = 1; j <= m; j++) {
			input(a[i][j]);
		}
	}
	print();
}
