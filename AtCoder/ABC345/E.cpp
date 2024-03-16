#include<bits/stdc++.h>
#define ll long long
#define N 200010
#define M 510
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
ll f[N][M];
ll c[N], v[N], s[N];
void solve();
int main() {
	while(Case--) solve();
}
void solve() {
	input(n, m);
	for(ll i = 1; i <= n; i++) {
		input(c[i], v[i]);
		s[i] = s[i - 1] + v[i];
		for(ll j = 0; j <= m; j++) f[i][j] = 1e15;
	}
	for(ll i = 1; i <= n; i++) {
		for(ll j = i - 1; j >= 0; j--) {
			if(c[i] == c[j]) continue;
			for(ll k = 0; k <= j; k++) {
				if(i - j - 1 + k > m) break;
				f[i][i - j - 1 + k] = min(f[i][i - j - 1 + k], f[j][k] + s[i - 1] - s[j]);
//				printf("f[%lld][%lld]=%lld\n", i, i - j - 1 + k, f[i][i - j - 1 + k]);
			}
		}
	}
	ll ans = -1;
	for(ll i = 0; i <= m; i++) {
		ans = max(ans, s[n - i] - f[n - i][m - i]);
	}
	print(ans);
}
