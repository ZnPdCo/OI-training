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
ll n, m, Case=1;
ll a[N], b[N];
ll s[N];
ll sum, ans = -1e18;
ll mn = 0;
void solve();
int main() {
	while(Case--) solve();
}
void solve() {
	input(n, m);
	for(ll i = 1; i <= n; i++) {
		input(a[i]);
		sum += a[i];
		b[i] = a[i] * m - a[i];
		s[i] = s[i-1] + b[i];
	}
	for(ll i = 1; i <= n; i++) {
		mn = min(mn, s[i]);
		ans = max(ans, sum + s[i] - mn);
	}
	print(ans);
}
