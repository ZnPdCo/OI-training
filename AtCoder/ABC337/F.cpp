/**
 * @file A.cpp 
 * @tag: #AtCoder#ABC#ABC336
 * @author: ZnPdCo
 * @date: 2023-12-23 13:55:50
 * @problem: https://atcoder.jp/contests/abc336/tasks/abc336_a
 **/
#include<bits/stdc++.h>
#define ll long long
#define N 400010
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
ll n, m, k, Case=1;
ll a[N];
ll num[N];
ll type, ans;
ll cnt[N];
void solve();
int main() {
	while(Case--) solve();
}
void solve() {
	input(n, m, k);
	for(ll i = 1; i <= n; i++) {
		input(a[i]);
		a[i+n] = a[i];
		num[a[i]] = min(num[a[i]] + 1, k);
	}
	ll r = 1;
	for(ll l = 1; l <= n; l++) {
		bool flag = false;
		while(r < 2*n) {
			flag = true;
			if(cnt[a[r]] == 0) {
				type++;
				ans += num[a[r]];
			}
			cnt[a[r]]++;
			if(type > m) break;
			r++;
		}
		if(flag && r < 2*n) {
			cnt[a[r]]--;
			if(cnt[a[r]] == 0) {
				type--;
				ans -= num[a[r]];
			}
		}
		
		
		
		print(ans);
		putchar('\n');
		
		
		cnt[a[l]]--;
		if(cnt[a[l]] == 0) {
			type--;
			ans -= num[a[l]];
		}
	}
}
