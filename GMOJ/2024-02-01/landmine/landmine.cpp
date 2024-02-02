#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
#define N 75
ll n;
struct node {
	ll p, q, r, s;
} a[N];

ll b[N], v[N];

inline ll pow2(ll x) {
	return x*x;
}

inline ll w(ll x, ll y, ll z, ll e) {
	return pow2(a[x].p - a[y].q) +
	pow2(a[y].p - a[z].r) +
	pow2(a[z].p - a[e].s);
}

ll f[N][N][N][N];

int main() {
	freopen("landmine.in", "r", stdin);
	freopen("landmine.out", "w", stdout);
	scanf("%lld", &n);
	for(ll i = 1; i <= n; i++) scanf("%lld", &a[i].p);
	for(ll i = 1; i <= n; i++) scanf("%lld", &a[i].q);
	for(ll i = 1; i <= n; i++) scanf("%lld", &a[i].r);
	for(ll i = 1; i <= n; i++) scanf("%lld", &a[i].s);
	
	for(ll i = n; i >= 1; i --) {
		for(ll j = i; j <= n; j++) {
			for(ll t = j+1; t <= n+1; t++) {
				for(ll u = i; u <= j; u++) {
					ll res = 0;
					for(ll k = u; k <= j; k++) {
						for(ll v = k+1; v <= j+1; v++) {
							res = max(res, f[i][k-1][v][u>k-1?i:u]+f[k+1][j][t][v>j?k+1:v]+w(i-1, k, j+1, t));
						}
					}
					f[i][j][t][u] = res;
				}
			}
		}
	}

	printf("%lld", f[1][n][n+1][1]);
}
