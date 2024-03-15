#include<bits/stdc++.h>
#define ll long long
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
ll n, m,l, Case=1;
ll a[N], b[N], c[N];
char s[N];
map<ll, bool> ma;
void solve();
int main() {
	while(Case--) solve();
}
void solve() {
	input(n);
	for(ll i = 1; i <= n; i++) {
		input(a[i]);
	}
	input(m);
	for(ll i = 1; i <= m; i++) {
		input(b[i]);
	}
	input(l);
	for(ll i = 1; i <= l; i++) {
		input(c[i]);
	}
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= m; j++) {
			for(ll k = 1; k <= l; k++) {
				ma[a[i]+b[j]+c[k]] = 1;
			}
		}
	}
	ll q;
	input(q);
	for(ll i = 1; i <= q; i++) {
		ll x;
		input(x);
		if(ma.find(x) != ma.end()) printf("Yes\n");
		else printf("No\n");
	}
}
