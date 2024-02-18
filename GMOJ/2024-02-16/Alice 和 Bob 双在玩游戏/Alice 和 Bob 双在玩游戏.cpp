#include <cstdio>
#include <queue>
using namespace std;
#define ll long long
#define P 998244353
#define N 310
#define M 90000
ll n, m;
ll rd[N];
char s[N];

ll head[N];
ll nxt[M], to[M], cnt;
void addEdge(ll u, ll v) {
	to[++cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
}

ll f[N], dp[N][N*N*2];
bool vis[N];

void dfs(ll u) {
	if(vis[u]) return;
	vis[u] = 1;
	f[u] = 0;
	
	for(ll i = head[u]; i; i = nxt[i]) {
		ll v = to[i];
		
		dfs(v);
		
		if(s[u] == 'B') {
			f[u] = min(f[u], f[v] - 1);
		}
		else {
			f[u] = max(f[u], f[v] + 1);
		}
	}
}

int main() {
//	freopen("gametwice.in", "r", stdin);
//	freopen("gametwice.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	scanf("%s", s+1);
	for(ll i = 1; i <= m; i++) {
		ll u, v;
		scanf("%lld %lld", &u, &v);
		rd[v]++;
		addEdge(u, v);
	}
	for(ll i = 1; i <= n; i++) {
		if(rd[i] == 0) {
			dfs(i);
		}
	}
	
	dp[0][n*n] = 1;
	for(ll i = 1; i <= n; i++) {
		for(ll j = n*n*2; j >= 0; j--) {
			(dp[i][j] += dp[i-1][j - f[i]]) %= P;
			(dp[i][j] += dp[i-1][j]) %= P;
		}
	}
	
	ll ans = 0;
	for(ll i = n*n+1; i <= n*n*2; i++) {
		(ans += dp[n][i]) %= P;
	}
	printf("%lld", ans);
}
