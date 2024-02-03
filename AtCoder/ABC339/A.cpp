/**
 * @file A.cpp 
 * @tag: #AtCoder#ABC#ABC336
 * @author: ZnPdCo
 * @date: 2023-12-23 13:55:50
 * @problem: https://atcoder.jp/contests/abc336/tasks/abc336_a
 **/
#include<bits/stdc++.h>
#define ll long long
#define N 1010
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
char s[N];
char ans[N];
void solve();
int main() {
	while(Case--) solve();
}
void solve() {
	scanf("%s", s+1);
	ll cnt = 0;
	for(ll i = 1; s[i] != '\0'; i++) {
		if(s[i] == '.') cnt = 0;
		else {
			ans[++cnt] = s[i];
		}
	}
	ans[++cnt] = '\0';
	printf("%s", ans+1);
}
