/**
 * @file 寻找道路.cpp 
 * @tag: #GMOJ#最短路
 * @author: ZnPdCo
 * @date: 2023-12-30 14:26:11
 * @problem: https://gmoj.net/senior/#main/show/3934
 **/
#include <cstdio>
#include <queue>
#define ll long long
#define N 10010
#define M 200010
using namespace std;
ll n, m, st, ed;
bool flag[N], go[N];


ll head[N];
ll nxt[2*M];
bool type[2*M];
ll to[2*M], cnt;
void addEdge(ll u, ll v, ll t) {
	cnt++;
	to[cnt] = v;
	nxt[cnt] = head[u];
	type[cnt] = t;
	head[u] = cnt;
}

void dfs(ll u) {
	flag[u] = 1;
	for(ll i = head[u]; i; i = nxt[i]) if(type[i] == 1) {
		ll v = to[i];
		if(!flag[v]) dfs(v);
	}
}

priority_queue<pair<ll, ll> > q;
ll dis[N];
bool vis[N];
void dij() {
	for(ll i = 1; i <= n; i++) dis[i] = 1e15;
	dis[st] = 0;
	q.push(make_pair(0, st));
	while(!q.empty()) {
		ll u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(ll i = head[u]; i; i = nxt[i]) if(type[i] == 0) {
			ll v = to[i];
			if(!go[v]) continue;
			if(!vis[v]) {
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
	for(ll i = 1; i <= m; i++) {
		ll u, v;
		scanf("%lld %lld", &u, &v);
		addEdge(u, v, 0);
		addEdge(v, u, 1);
	}
	scanf("%lld %lld", &st, &ed);
	dfs(ed);
	
	for(ll u = 1; u <= n; u++) {
		go[u] = true;
		for(ll i = head[u]; i; i = nxt[i]) {
			ll v = to[i];
			if(flag[v] == 0) go[u] = false;
		}
	}
	dij();
	if(dis[ed] == 1e15) printf("-1");
	else printf("%lld", dis[ed]);
}
/*
3 3
1 2
2 3
3 1
1 2
*/
