/**
 * @file A.cpp 
 * @tag: #AtCoder#ABC#ABC336
 * @author: ZnPdCo
 * @date: 2023-12-23 13:55:50
 * @problem: https://atcoder.jp/contests/abc336/tasks/abc336_a
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
ll n, m, k ,Case=1;
void solve();
int main() {
	while(Case--) solve();
}
void solve() {
	input(n, m, k);
	ll lcm = n * m / __gcd(n, m);
	ll l = 1, r = 1e18, ans;
	while(l <= r) {
		ll mid = (l + r) >> 1;
		ll num = mid / lcm * (lcm / n + lcm / m - 2) + (mid % lcm) / n + (mid % lcm) / m;
		if(num >= k) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	print(ans);
}
