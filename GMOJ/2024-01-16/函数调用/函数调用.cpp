/**
 * @file 函数调用.cpp 
 * @tag: #GMOJ#图论
 * @author: ZnPdCo
 * @date: 2024-01-16 19:53:25
 * @problem: https://gmoj.net/senior/#main/show/6857
 **/
#include <cstdio>
#include <queue>
#define ll long long
#define N 100010
#define M 1000010
#define P 998244353
using namespace std;
ll n, m, q;
ll a[N];
ll b[N];

struct node {
	ll t, p, v;
	ll cheng, time;
	// cheng:函数内乘的数，方便这里进行加法操作
	// time:这个函数执行的次数（多次乘法算多次），可以拓扑来减少函数执行次数
} k[N];

ll head[N];
ll nxt[2*M], to[2*M], cnt;
void addEdge(ll u, ll v) {
	cnt++;
	to[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
}

ll rd[N];		// 入度

// 记忆化搜索来计算在函数内乘法的结果
ll dfs(ll u) {
	if(k[u].cheng != -1) return k[u].cheng;
	k[u].cheng = 1;	// 默认乘了1
	if(k[u].t == 2) k[u].cheng = k[u].v;
	for(ll i = head[u]; i; i = nxt[i]) {
		ll v = to[i];
		(k[u].cheng *= dfs(v)) %= P;
	}
	return k[u].cheng;
}

int main() {
	freopen("call.in", "r", stdin);
	freopen("call.out", "w", stdout);
	scanf("%lld", &n);
	for(ll i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	scanf("%lld", &m);
	for(ll i = 1; i <= m; i++) {
		scanf("%lld", &k[i].t);
		k[i].cheng = -1;
		if(k[i].t == 1) {
			scanf("%lld %lld", &k[i].p, &k[i].v);
		} else if(k[i].t == 2) {
			scanf("%lld", &k[i].v);
		} else {
			ll c;
			scanf("%lld", &c);
			for(ll j = 1; j <= c; j++) {
				ll g;
				scanf("%lld", &g);
				if(g == -1) return 0&printf("0");
				addEdge(i, g);
				rd[g]++;
			}
		}
	}
	ll q;
	scanf("%lld", &q);
	k[0].cheng = -1;
	k[0].t = 3;
	for(ll i = 1; i <= q; i++) {
		ll f;
		scanf("%lld", &f);
		addEdge(0, f);
		rd[f]++;
	}
	

	k[0].cheng = dfs(0);
	for(ll i = 1; i <= n; i++) {
		(a[i] *= k[0].cheng) %= P;
	}
	
	// 拓扑计算结果
	queue<ll> que;
	for(ll i = 0; i <= m; i++) {
		if(rd[i] == 0) que.push(i);
	}
	k[0].time = 1;
	while(!que.empty()) {
		ll u = que.front();
		que.pop();
		if(k[u].t == 1) {
			(a[k[u].p] += k[u].v * k[u].time) %= P;
		}
		for(ll i = head[u]; i; i = nxt[i]) {
			ll v = to[i];
			(k[v].time += k[u].time) %= P;		// 里面的加法会执行外面这么多次
			(k[u].time *= k[v].cheng) %= P;
			rd[v]--;
			if(!rd[v]) {
				que.push(v);
			}
		}
	}
	for(ll i = 1; i <= n; i++) {
		printf("%lld ", a[i]);
	}
}
