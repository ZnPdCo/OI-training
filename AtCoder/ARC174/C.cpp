#include<bits/stdc++.h>
#define ll long long
#define N 1000010
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
ll qpow(ll x, ll y) {
	if(y == 0) return 1;
	if(y % 2 == 1) return x * qpow(x, y - 1) % P;
	ll tmp = qpow(x, y / 2);
	return tmp * tmp % P;
}
ll n, Case=1;
ll f[N][2], ans[2], inv;
void solve();
int main() {
	while(Case--) solve();
}
void solve() {
	input(n);
	inv = qpow(n, P - 2);
	f[1][1] = 1;
	for(ll i = 1; i < n; i++) {
		for(ll j = 0; j <= 1; j++) {
			ll p = i * inv % P;
			(ans[j] += f[i][j] * p % P * qpow(1 - p * p % P + P, P - 2) % P) %= P;
			(ans[j^1] += f[i][j] * p % P * p % P * qpow(1 - p * p % P + P, P - 2) % P) %= P;
			(f[i+1][j^1] += f[i][j] * qpow((1 + p) % P, P - 2) % P) %= P;
			(f[i+1][j] += f[i][j] * p % P * qpow((1 + p) % P, P - 2) % P) %= P;
		}
	}
	print(ans[0], ans[1]);
}
