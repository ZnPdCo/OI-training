#include <cstdio>
#include <cstring>
#include <random>
#include <ctime>
#define ll long long
#define N 1010
#define M 500000
using namespace std;
ll T;
ll n, m;
struct side {
	ll u, v, c;
} a[M];
ll u[N];
ll v[N];
bool vis[N];
ll cnt[2];
bool isans;
mt19937 rnd(time(0));
void dfs(ll x) {
	if(isans) return;
	if(x > n) {
		if(cnt[1] % 2 == 1) return;
		for(ll i = 1; i <= 2*n; i++) if(!vis[i]) return;
		for(ll i = 1; i <= n; i++) printf("%lld ", u[i]);
		printf("\n");
		isans = 1;
		return;
	}
	for(ll i = 1; i <= m; i++) if(!v[i]) {
		if(vis[a[i].u] || vis[a[i].v]) continue;
		v[i] = 1;
		u[x] = i;
		vis[a[i].u] = 1;
		vis[a[i].v] = 1;
		cnt[a[i].c]++;
		dfs(x+1);
		cnt[a[i].c]--;
		vis[a[i].u] = 0;
		vis[a[i].v] = 0;
		v[i] = 0;
	}
}
int main() {
	freopen("matching.in", "r", stdin);
	freopen("matching.out", "w", stdout);
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld %lld", &n, &m);
		for(ll i = 1; i <= m; i++) {
			scanf("%lld %lld %lld", &a[i].u, &a[i].v, &a[i].c); 
		}
		isans = 0;
		dfs(1);
		if(!isans) printf("-1\n");
	}
}
