/**
 * @file A.cpp 
 * @tag: #AtCoder#ABC#ABC336
 * @author: ZnPdCo
 * @date: 2023-12-23 13:55:50
 * @problem: https://atcoder.jp/contests/abc336/tasks/abc336_a
 **/
#include<bits/stdc++.h>
#define ll long long
#define N 5010
using namespace std;
void print() {}
template<typename T, typename... Ts>
void print(const T& x, const Ts&... y) {
	cout << x << ' ';
	print(y...);
}
void input() {}
template<typename T, typename... Ts>
void input(T& x, Ts&... y) {
	cin >> x;
	input(y...);
}
ll n, m, Case=1;
ll w[N], a[N];
ll U[N], V[N];

ll he1[N], he2[N];
ll nxt[2*N], to[2*N], cnt;

ll cd[N];

ll f[N], dp[N];

queue<ll> que;
void addEdge(ll head[], ll u, ll v) {
	cnt++;
	to[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
}

void solve();
int main() {
	while(Case--) solve();
}
void solve() {
	input(n, m);
	for(ll i = 1; i <= m; i++) {
		scanf("%lld %lld", &U[i], &V[i]);
	}
	for(ll i = 1; i <= n; i++) {
		input(w[i]);
	}
	for(ll i = 1; i <= n; i++) {
		input(a[i]);
	}
	
	for(ll i = 1; i <= m; i++) {
		if(w[U[i]] < w[V[i]]) swap(U[i], V[i]);
		if(w[U[i]] == w[V[i]]) continue;
		addEdge(he1, U[i], V[i]);
		addEdge(he2, V[i], U[i]);
		cd[U[i]] ++;
	}
	
	for(ll i = 1; i <= n; i++) {
		if(cd[i] == 0) que.push(i);
	}
	
	while(!que.empty()) {
		ll u = que.front();
		que.pop();
		
		for(ll i = he2[u]; i; i = nxt[i]) {
			ll v = to[i];
			cd[v]--;
			if(cd[v] == 0) que.push(v);
		}
		
		memset(dp, 0, sizeof dp);
		
		for(ll i = he1[u]; i; i = nxt[i]) {
			ll v = to[i];
			for(ll j = w[u] - 1; j >= w[v]; j--) {
				dp[j] = max(dp[j], dp[j-w[v]]+f[v]);
			}
		}
		
		f[u] = dp[w[u] - 1] + 1;
	}
	
	ll ans = 0;
	
	for(ll i = 1; i <= n; i++) {
//		printf("%lld ", f[i]);
		ans += a[i] * f[i];
	}
	
	print(ans);
}
