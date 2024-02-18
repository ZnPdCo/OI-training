#include <cstdio>
#include <cstring>
#define ll long long
#define N 14
ll q, n, m;
ll v[N];
ll f[N][N][1<<N];
ll g[N][N][1<<N];
//   C-2,C-1,s
ll road[N][N];
ll ans1, ans2;


int main() {
	scanf("%lld", &q);
	while(q--) {
		memset(road, 0, sizeof road);
		memset(f, 0, sizeof f);
		memset(g, 0, sizeof g);
		ans1 = ans2 = 0;
		
		scanf("%lld %lld", &n, &m);
		for(ll i = 1; i <= n; i++) {
			scanf("%lld", &v[i]);
			f[0][i][1<<(i-1)] = v[i];
			g[0][i][1<<(i-1)] = 1;
		}
		for(ll i = 1; i <= m; i++) {
			ll x, y;
			scanf("%lld %lld", &x, &y);
			road[x][y] = road[y][x] = 1;
		}
		for(ll s = 1; s < (1<<n); s++) {
			for(ll i = 0; i <= n; i++) if((i == 0 && __builtin_popcount(s) == 1) || (s & (1<<(i-1)))) {
				for(ll j = 1; j <= n; j++) if(g[i][j][s] && i != j && (s & (1<<(j-1)))) {
					for(ll k = 1; k <= n; k++) if(k != i && k != j && !(s & (1<<(k-1))) && road[j][k]) {
						ll val = f[i][j][s] + v[k] + v[j] * v[k] + v[i] * v[j] * v[k] * road[i][k];
						ll nxt = s | (1<<(k-1));
						if(val > f[j][k][nxt]) {
							f[j][k][nxt] = val;
							g[j][k][nxt] = g[i][j][s];
							
						} else if(val == f[j][k][nxt]) {
							g[j][k][nxt] += g[i][j][s];
						}
					}
//					prllf("f[%d][%d][%d]=%d\n", i, j, s, f[i][j][s]);
				}
			}
		}
		for(ll i = 0; i <= n; i++) {
			for(ll j = 1; j <= n; j++) {
				if(f[i][j][(1<<n)-1] > ans1) {
					ans1 = f[i][j][(1<<n)-1];
					ans2 = g[i][j][(1<<n)-1];
				} else if(f[i][j][(1<<n)-1] == ans1) {
					ans2 += g[i][j][(1<<n)-1];
				}
			}
		}
		printf("%lld %lld\n", ans1, (ans2 + 1) / 2);
	}
	return 0;
}
