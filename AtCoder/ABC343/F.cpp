#include<bits/stdc++.h>
#define ll long long
#define N 81
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
ll p[N][N], r[N][N],d[N][N],f[N][N][N][N],g[N][N][2];
void solve();
int main() {
	while(Case--) solve();
}
void solve() {
	input(n);
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= n; j++) {
			input(p[i][j]);
		}
	}
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j < n; j++) {
			input(r[i][j]);
		}
	}
	for(ll i = 1; i < n; i++) {
		for(ll j = 1; j <= n; j++) {
			input(d[i][j]);
		}
	}
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= n; j++) {
			g[i][j][0] = 1e15;
			for(ll x = i; x <= n; x++) {
				for(ll y = j; y <= n; y++) {
					if(x == i && y == j) continue;
					if(x == i) f[i][j][x][y] = f[i][j][x][y-1] + r[x][y-1];
					else if(y == j) f[i][j][x][y] = f[i][j][x-1][y] + d[x-1][y];
					else f[i][j][x][y] = min(f[i][j][x][y-1] + r[x][y-1], f[i][j][x-1][y] + d[x-1][y]);
				}
			}
		}
	}
	g[1][1][0] = 0;
	g[1][1][1] = 0;
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= n; j++) {
			for(ll x = 1; x <= i; x++) {
				for(ll y = 1; y <= j; y++) {
					if(i == 3 && j == 3 && x == 2 && y == 1) {
//						printf("a");
					}
					if(x == i && y == j) continue;
					ll need = max(f[x][y][i][j] - g[x][y][1], 0ll);
					ll times = (p[x][y] + need - 1) / p[x][y];
					if(g[x][y][0] + i-x+j-y + times < g[i][j][0]) {
						g[i][j][0] = g[x][y][0] + i-x+j-y + times;
						g[i][j][1] = times * p[x][y] + g[x][y][1] - f[x][y][i][j];
					} else if(g[x][y][0] + i-x+j-y + times == g[i][j][0]) {
						if(times * p[x][y] + g[x][y][1] - f[x][y][i][j] > g[i][j][1]) {
							g[i][j][1] = times * p[x][y] + g[x][y][1] - f[x][y][i][j];
						}
					}
				}
			}
//			printf("g[%lld][%lld]=%lld\n", i, j,g[i][j][0]);
		}
	}
	printf("%lld", g[n][n][0]);
}
