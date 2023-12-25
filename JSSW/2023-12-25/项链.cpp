/**
 * @file 卡片.cpp 
 * @tag: #JSSW#数论 
 * @author: ZnPdCo
 * @date: 2023-12-25 20:30:25
 * @problem: https://jsswoj.com/oj/#main/show/2973
 **/
#include <cstdio>
#include <queue>
#define ll long long
#define N 100010
using namespace std;
ll n, m;
ll w[N], f[N];
ll mx2[N];	// 次大值
ll rd[N];


ll head[N];
ll nxt[N];
ll to[N], cnt;
void addEdge(ll u, ll v) {
	cnt++;
	to[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
}


queue<ll> q;
int main() {
	scanf("%lld %lld", &n, &m);
	for(ll i = 1; i <= n; i++) {
		scanf("%lld", &w[i]);
		f[i] = w[i];
	}
	for(ll i = 1; i <= m; i++) {
		ll u, v;
		scanf("%lld %lld", &u, &v);
		addEdge(u, v);
		rd[v]++;
	}
	for(ll i = 1; i <= n; i++)
		if(rd[i] == 0) q.push(i);
	while(!q.empty()) {
		ll u = q.front();
		q.pop();
		for(ll i = head[u]; i; i = nxt[i]) {
			ll v = to[i];
			rd[v]--;
			if(f[u] + w[v] > f[v]) {
				f[v] = f[u] + w[v];
			}
			if(rd[v] == 0) {
				q.push(v);
			}
		}
	}
	
	for(ll i = 1; i <= n; i++) {
		printf("%lld %lld\n", f[i], mx2[i]);
	}
}
