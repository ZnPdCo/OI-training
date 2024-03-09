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
ll f[N][N];
char t[N], s[N];
void solve();
int main() {
//	input(Case);
	while(Case--) solve();
}
void solve() {
	scanf("%s", t+1);
	ll tlen = strlen(t+1);
	input(n);
	for(ll i = 0; i <= n; i++) {
		for(ll j = 1; j <= tlen; j++) f[i][j] = 1e15;
	}
	for(ll i = 1; i <= n; i++) {
		input(m);
		for(ll j = 1; j <= m; j++) {
			scanf("%s", s+1);
			ll slen = strlen(s+1);
			for(ll k = 0; k <= tlen; k++) {
				f[i][k] = min(f[i][k], f[i-1][k]);
				if(k < slen) continue;
				bool flag = 1;
				for(ll x = 1; x <= slen; x++) {
					if(s[x] != t[k - slen + x]) {
						flag = 0;
						break;
					}
				} 
				if(flag) f[i][k] = min(f[i][k], f[i-1][k - slen] + 1);
//				printf("f[%lld][%lld]=%lld\n", i, k, f[i][k]);
			}
		}
	}
	if(f[n][tlen] == 1e15) printf("-1");
	else print(f[n][tlen]);
}
