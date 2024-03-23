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
ll a[N], cnt;
void solve();
int main() {
	while(Case--) solve();
}
void solve() {
	input(n);
	for(ll i = 1; i <= n; i++) {
		ll op, x;
		input(op, x);
		if(op == 1) {
			a[++cnt] = x;
		} else {
			print(a[cnt - x + 1]);
			putchar('\n');
		}
	}
}
