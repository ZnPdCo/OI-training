/**
 * @file 换教室.cpp 
 * @tag: #GMOJ#dp
 * @author: ZnPdCo
 * @date: 2024-01-11 20:57:17
 * @problem: https://gmoj.net/senior/#main/show/4905
 **/
#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
#define N 2010
#define V 310
ll n, m, v, e;
ll c[N], d[N];
double k[N];
int dis[V][V];
double ans = 1e15;
double f[N][N][2];
// 第i节课 换了j次 当前换没换
int main() {
	freopen("classroom.in", "r", stdin);
	freopen("classroom.out", "w", stdout);
	scanf("%lld %lld %lld %lld", &n, &m, &v, &e);
	for(ll i = 1; i <= n; i++) scanf("%lld", &c[i]);
	for(ll i = 1; i <= n; i++) scanf("%lld", &d[i]);
	for(ll i = 1; i <= n; i++) scanf("%lf", &k[i]);
	for(ll i = 1; i <= v; i++) {
		for(ll j = i+1; j <= v; j++) {
			dis[i][j] = dis[j][i] = 1e9;
		}
	}
	for(ll i = 1; i <= e; i++) {
		ll u, v, w;
		scanf("%lld %lld %lld", &u, &v, &w);
		if(w < dis[u][v]) {
			dis[u][v] = dis[v][u] = w;
		}
	}
	for(ll k = 1; k <= v; k++) {
		for(ll i = 1; i <= v; i++) {
			for(ll j = 1; j <= v; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
			}
		}
	}
	for(ll i = 1; i <= n; i++) {
		for(ll j = 0; j <= m; j++) {
			f[i][j][0] = f[i][j][1] = 1e15;
		}
	}
	f[1][0][0] = f[1][1][1] = 0;
	for(ll i = 2; i <= n; i++) {
		f[i][0][0] = f[i-1][0][0] + dis[c[i-1]][c[i]];
		for(ll j = 1; j <= m; j++) {
			f[i][j][0] = min(f[i-1][j][0] + dis[c[i-1]][c[i]],
				f[i-1][j][1] + k[i-1] * dis[d[i-1]][c[i]] + 
				(1-k[i-1]) * dis[c[i-1]][c[i]]);
			f[i][j][1] = min(f[i-1][j-1][0] + k[i] * dis[c[i-1]][d[i]] + 
				(1-k[i]) * dis[c[i-1]][c[i]],
				f[i-1][j-1][1] + k[i-1] * k[i] * dis[d[i-1]][d[i]] + 
				(1-k[i-1]) * k[i] * dis[c[i-1]][d[i]] + 
				k[i-1] * (1-k[i]) * dis[d[i-1]][c[i]] + 
				(1-k[i-1]) * (1-k[i]) * dis[c[i-1]][c[i]]);
		}
	}
	for(ll i = 0; i <= m; i++) {
		ans = min(ans, f[n][i][0]);
		ans = min(ans, f[n][i][1]);
	}
	printf("%.2lf", ans);
}
