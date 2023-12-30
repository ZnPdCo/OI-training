/**
 * @file 联合权值.cpp 
 * @tag: #GMOJ#树
 * @author: ZnPdCo
 * @date: 2023-12-30 14:26:53
 * @problem: https://gmoj.net/senior/#main/show/3931
 **/
#include <cstdio>
#include <algorithm>
#define ll long long
#define N 200010
#define P 10007
using namespace std;
ll n, w[N], ans1, ans2;
ll fa[N];
ll dep[N];
ll f[N], mx[N];
ll head[N];
ll nxt[2*N];
ll to[2*N], cnt;
void addEdge(ll u, ll v) {
	cnt++;
	to[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
}
int main() {
	scanf("%lld", &n);
	for(ll i = 1; i < n; i++) {
		ll u, v;
		scanf("%lld %lld", &u, &v);
		addEdge(u, v);
		addEdge(v, u);
	}
	for(ll i = 1; i <= n; i++) {
		scanf("%lld", &w[i]);
	}
	for(ll u = 1; u <= n; u++) {
		ll sum1 = 0, sum2 = 0, mx1 = 0, mx2 = 0;
		for(ll j = head[u]; j; j = nxt[j]) {
			ll v = to[j];
			(sum1 += w[v]) %= P;
			(sum2 += w[v]*w[v]) %= P;
			if(w[v] > mx1) mx1 = w[v];
			else if(w[v] > mx2) mx2 = w[v];
		}
		
		ans1 = max(ans1, mx1*mx2);
		(ans2 += sum1 * sum1 - sum2) %= P;
	}
	printf("%lld %lld", ans1, ans2);
}
