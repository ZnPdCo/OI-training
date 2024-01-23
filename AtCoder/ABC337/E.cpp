/**
 * @file A.cpp 
 * @tag: #AtCoder#ABC#ABC336
 * @author: ZnPdCo
 * @date: 2023-12-23 13:55:50
 * @problem: https://atcoder.jp/contests/abc336/tasks/abc336_a
 **/
#include<bits/stdc++.h>
#define ll long long
#define flush fflush(stdin);fflush(stdout);
#define N 110
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
ll ans;
ll a[N];
char s[N];
void solve();
int main() {
	while(Case--) solve();
}
void solve() {
	scanf("%lld", &n);
	flush
	m = floor(log2(n-1));
	printf("%lld\n", m+1);
	flush
	for(ll i = 0; i <= m; i++) {
		ll cnt = 0;
		for(ll j = 0; j < n; j++) {
			if(j & (1<<i)) {
				a[++cnt] = j;
			}
		}
		printf("%lld ", cnt);
		flush
		for(ll j = 1; j <= cnt; j++) {
			printf("%lld ", a[j]+1);
			flush
		}
		printf("\n");
		flush
	}
	scanf("%s", s+1);
	flush
	for(ll i = m+1; i >= 1; i--) {
		if(s[i] == '1') ans = ans * 2 + 1;
		else ans = ans * 2;
	}
	printf("%lld", ans+1);
	flush
}
