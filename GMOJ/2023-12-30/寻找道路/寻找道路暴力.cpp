#include <cstdio>
#include <queue>
#define ll long long
#define N 110
#define M 200010
using namespace std;
ll n, m, st, ed;
bool road[N][N];


ll head[N];
ll nxt[N];
ll to[N], cnt;
void addEdge(ll u, ll v) {
	cnt++;
	to[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
}

ll f[N][N];
void fo() {
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= n; j++) if(i != j) {
			for(ll k = 1; k <= n; k++) {
				f[i][j] = min(f[i][j], f[i][j] + f[j][k]);
			}
		}
	}
}

priority_queue<pair<ll, ll> > q;
ll dis[N];
bool vis1[N];
void dij() {
	for(ll i = 1; i <= n; i++) dis[i] = 1e15;
	dis[st] = 0;
	q.push(make_pair(0, st));
	while(!q.empty()) {
		ll u = q.top().second;
		q.pop();
		if(vis1[u]) continue;
		vis1[u] = 1;
		for(ll i = head[u]; i; i = nxt[i]) {
			ll v = to[i];
			bool flag = true;
			for(ll j = head[v]; j; j = nxt[j]) {
				ll x = to[j];
				if(f[x][ed] == 1e15) flag = false; 
			}
			if(!vis1[v] && flag) {
				if(dis[v] > dis[u] + 1) {
					dis[v] = dis[u] + 1;
					q.push(make_pair(-dis[v], v));
				}
			}
		}
	}
}

int main() {
	scanf("%lld %lld", &n, &m);
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= n; j++) if(i != j) {
			f[i][j] = 1e15;
		}
	}
	for(ll i = 1; i <= m; i++) {
		ll u, v;
		scanf("%lld %lld", &u, &v);
		f[u][v] = min(f[u][v], 1ll);
		addEdge(u, v);
	}
	scanf("%lld %lld", &st, &ed);
	fo();
	dij();
	if(dis[ed] == 1e15) printf("-1");
	else printf("%lld", dis[ed]);
}
