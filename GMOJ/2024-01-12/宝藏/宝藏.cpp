/**
 * @file 宝藏.cpp 
 * @tag: #GMOJ#dp#状压dp
 * @author: ZnPdCo
 * @date: 2024-01-13
 * @problem: https://gmoj.net/senior/#main/show/5477
 **/
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
#define N 13
using namespace std;
ll n, m;
ll road[N][N];
ll f[1<<N][N][N];
ll ans = 1e15;
// 子集状态 根 深度
int main() {
	freopen("treasure.in", "r", stdin);
	freopen("treasure.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for(ll i = 1; i <= n; i++) {
		for(ll j = i+1; j <= n; j++) {
			road[i][j] = road[j][i] = 1e15;
		}
	}
	for(ll i = 1; i <= m; i++) {
		ll u, v, w;
		scanf("%lld %lld %lld", &u, &v, &w);
		if(w < road[u][v]) {
			road[u][v] = road[v][u] = w;
		}
	}
	for(ll s = 0; s < (1<<n); s++) {
		for(ll i = 1; i <= n; i++) {
			for(ll j = 1; j <= n; j++) {
				f[s][i][j] = 1e15;
			}
		}
	}
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= n; j++) {
			f[1<<(i-1)][i][j] = 0;
		}
	}
	for(ll s = 0; s < (1<<n); s++) {		// 包含i、j的集
		for(ll ss = 0; ss < (1<<n); ss++) {		// 不包含i、包含j的s的子集
			if((ss & s) != ss) continue;
			for(ll i = 1; i <= n; i++) {				// 根
				if(!(s & (1<<(i-1)))) continue;
				if(ss & (1<<(i-1))) continue;
				for(ll j = 1; j <= n; j++) {			// 根的儿子
					if(!(s & (1<<(j-1)))) continue;
					if(!(ss & (1<<(j-1)))) continue;
					if(i == j || road[i][j] == 1e15) continue;
					for(ll d = 1; d < n; d++) {		// 深度
						f[s][i][d] = min(f[s][i][d], f[s ^ ss][i][d] + f[ss][j][d+1] + road[i][j] * d);
					}
				}
			}
		}
	}
	
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= n; j++) {
			ans = min(ans, f[(1<<n)-1][i][j]);
		}
	}
	printf("%lld", ans);
}
