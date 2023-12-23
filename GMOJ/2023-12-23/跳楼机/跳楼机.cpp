/**
 * @file 跳楼机.cpp 
 * @tag: #GMOJ#同余最短路
 * @author: ZnPdCo
 * @date: 2023-12-23 16:03:06
 * @problem: https://gmoj.net/senior/#main/show/4722
 **/
#include <cstdio>
#include <queue>
#define ll long long
using namespace std;
ll h, x, y, z, ans;
ll f[100010];

ll head[100010];
ll nxt[200010];
ll cost[200010];
ll to[200010], cnt;
void addEdge(ll u, ll v, ll w) {
	cnt++;
	to[cnt] = v;
	cost[cnt] = w;
	nxt[cnt] = head[u];
	head[u] = cnt;
}
ll dis[100010];
ll vis[100010];
priority_queue<pair<ll,ll> > que;
void dij() {
	for(ll i = 0; i < x; i++) dis[i] = h+1;
	dis[0] = 0;
	que.push(make_pair(0, 0));
	while(!que.empty()) {
		ll u = que.top().second;
		que.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(ll i = head[u]; i; i = nxt[i]) {
			ll v = to[i];
			if(!vis[v]) {
				if(dis[v] > dis[u] + cost[i]) {
					dis[v] = dis[u] + cost[i];
					que.push(make_pair(-dis[v], v));
				}
			}
		}
	}
}
int main() {
	scanf("%lld%lld%lld%lld", &h, &x, &y, &z);
	h--;
	for(ll i = 0; i < x; i++) {
		addEdge(i, (i+y)%x, y);
		addEdge(i, (i+z)%x, z);
	}
	dij();
	for(ll i = 0; i < x; i++) {
		if(dis[i] <= h) ans += (h - dis[i]) / x + 1;
	}
	printf("%lld", ans);
}
