#include <cstdio>
#include <vector>
#include <queue>
#define ll long long
#define N 200010
using namespace std;


ll T;
ll n, t;
ll f[N], a[N], k[N];
vector<ll> son[N];


ll dep[N];
ll white[N], black[N];	// 最深的白、黑点

ll q[N], head, tail;
void dfs(ll u, ll fa, ll rt) {
	if(a[u]) black[rt] = max(black[rt], dep[u]);
	else white[rt] = max(white[rt], dep[u]);
	for(ll v : son[u]) {
		if(v == fa) continue;
		dep[v] = dep[u] + 1;
		dfs(v, u, rt);
	}
}

ll far[N];				// 对于每个节点最远的黑色节点距离



int main() {
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld %lld", &n, &t);
		for(ll i = 1; i <= n; i++) son[i].clear();
		for(ll i = t+1; i <= n; i++) {
			scanf("%lld", &f[i]);
			son[f[i]].push_back(i);
		}
		for(ll i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		for(ll i = 1; i <= t; i++) {
			white[i] = black[i] = -1e15;
			dfs(i, 0, i);
		}
		/*
		  维护某个白色节点距离它最远的黑色节点
		  首先先维护每个根节点距离它最远的节点
		  考虑破环成链
		  脑子炸了让我捋捋
		  首先枚举u，然后用单调队列维护v(v<u)，队列长度不超过t/2
		 */ 
		for(ll i = 1; i <= t; i++) {
			k[i] = black[i] - i;	// 维护每个树最深的黑色节点
			k[i+t] = black[i] - (i+t);
		}
		head = tail = 0;
		for(ll i = 1; i <= 2*t; i++) {
			if(head < tail && q[head] < i-t/2) head++;
			if(head < tail && k[i] >= k[q[tail]]) tail--;
			q[++tail] = i;
			far[(i-1)%t+1] = i+k[q[head]];
		}
		
		/*
		  以及用单调队列维护v(v>u)，队列长度不超过t/2
		 */
		for(ll i = 1; i <= t; i++) {
			k[i] = black[i] + i;	// 维护每个树最深的黑色节点
			k[i+t] = black[i] + (i+t);
		}
		head = tail = 0;
		for(ll i = 2*t; i >= 1; i--) {
			if(head < tail && q[head] > i+t/2) head++;
			if(head < tail && k[i] >= k[q[tail]]) tail--;
			q[++tail] = i;
			far[(i-1)%t+1] = max(far[i], k[q[head]]-i);
		}
		for(ll i = 1; i <= t; i++) {
			printf("%lld ", far[i]);
		}
	}
}
