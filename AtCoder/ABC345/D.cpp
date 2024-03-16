#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
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
ll n, h, w, Case=1;
ll a[N], b[N];
ll s[N];
void solve();
int main() {
	while(Case--) solve();
}
bool vis[N][N];
bool v[N];
void dfs(ll z) {
	if(z > n) {
		for(ll i = 1; i <= h; i++) {
			for(ll j = 1; j <= w; j++) {
				if(!vis[i][j]) return;
			}
		}
		printf("Yes");
		exit(0);
		return;
	}
	for(ll i = 1; i <= n; i ++) {
		if(v[i]) continue;
		v[i] = 1;
		bool ok = 0;
		
		for(ll j = 1; j <= h - b[i] + 1; j ++) {
			for(ll k = 1; k <= w - a[i] + 1; k ++) {
				bool flag = 1;
				for(ll x = j; x <= j + b[i] - 1; x++) {
					for(ll y = k; y <= k + a[i] - 1; y++) {
						if(vis[x][y]) {
							flag = 0;
							break;
						}
					}
					if(!flag) break; 
				}
				if(flag) {
					for(ll x = j; x <= j + b[i] - 1; x++) {
						for(ll y = k; y <= k + a[i] - 1; y++) {
							vis[x][y] = 1;
						}
					}
					dfs(z+1);
					for(ll x = j; x <= j + b[i] - 1; x++) {
						for(ll y = k; y <= k + a[i] - 1; y++) {
							vis[x][y] = 0;
						}
					}
					ok = 1;
					break;
				}
			}
			if(ok) break;
		}
		ok = 0;
		for(ll j = 1; j <= h - a[i] + 1; j ++) {
			for(ll k = 1; k <= w - b[i] + 1; k ++) {
				bool flag = 1;
				for(ll x = j; x <= j + a[i] - 1; x++) {
					for(ll y = k; y <= k + b[i] - 1; y++) {
						if(vis[x][y]) {
							flag = 0;
							break;
						}
					}
					if(!flag) break; 
				}
				if(flag) {
					for(ll x = j; x <= j + a[i] - 1; x++) {
						for(ll y = k; y <= k + b[i] - 1; y++) {
							vis[x][y] = 1;
						}
					}
					dfs(z+1);
					for(ll x = j; x <= j + a[i] - 1; x++) {
						for(ll y = k; y <= k + b[i] - 1; y++) {
							vis[x][y] = 0;
						}
					}
					ok = 1;
					break;
				}
			}
			if(ok) break;
		}
		dfs(z+1);
		v[i] = 0;
	}
}
void solve() {
	input(n, h, w);
	for(ll i = 1; i <= n; i++) {
		input(a[i], b[i]);
	}
	for(ll i = n; i >= 1; i--) {
		s[i] = s[i+1] + a[i] * b[i];
	}
	if(s[1] < h * w) {
		printf("No");
		return;
	}
	dfs(1);
	printf("No");
}
