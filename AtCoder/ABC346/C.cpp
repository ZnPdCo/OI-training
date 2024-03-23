#include<bits/stdc++.h>
#define ll unsigned long long
#define N 200010
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
ll a[N];
map<ll, bool> ma;
ll ans = 0;
char s[N];
void solve();
int main() {
	while(Case--) solve();
}
void solve() {
	input(n, m);
	ans = (1 + m) * m / 2;
	for(ll i = 1; i <= n; i++) {
		input(a[i]);
		if(a[i] <= m && ma.find(a[i]) == ma.end()) {
			ma[a[i]] = 1;
			ans -= a[i];
		}
	}
	print(ans);
}
