/**
 * @file G.cpp
 * @tag: #AtCoder#ABC#ABC334
 * @author: ZnPdCo
 * @date: 2023-12-23 19:50:12
 * @problem: https://atcoder.jp/contests/abc334/tasks/abc334_g
 **/
#include <bits/stdc++.h>
#define P 998244353
#define ll long long
#define N 1010
#define debug() printf("debug");
#define newll(x) ll x = 0
#define newarr(x) ll x[N] = {0}
#define newvis(x) bool x[N] = {0}
#define outt printf
#define inn scanf
using namespace std;
ll n, m, Case=1;
char a[N][N];

const ll dx[4] = {0, 1, 0, -1};
const ll dy[4] = {1, 0, -1, 0};
ll zip(ll x, ll y) {
	return x * (m+10) + y;
}
ll head[N*N];
ll nxt[4*N*N];
ll to[4*N*N], cnt;
ll qpow(ll x, ll y) {
	if(y == 0) return 1;
	if(y % 2 == 1) return x * qpow(x, y - 1) % P;
	ll tmp = qpow(x, y / 2);
	return tmp * tmp % P;
}
void addEdge(ll u, ll v) {
	cnt++;
	to[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
}
void bfs(ll x, ll y) {
	a[x][y] = '*';
	queue<pair<ll, ll> > q;
	q.push(make_pair(x, y));
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		for(ll i = 0; i < 4; i++) {
			ll xx = x + dx[i];
			ll yy = y + dy[i];
			if(xx > 0 && xx <= n && yy > 0 && yy <= m && a[xx][yy] == '#') {
				a[xx][yy] = '*';
				addEdge(zip(x, y), zip(xx, yy));
				addEdge(zip(xx, yy), zip(x, y));
				q.push(make_pair(xx, yy));
			}
		}
		q.pop();
	}
}
ll dfn[N*N], low[N*N], t;
ll block[N*N];
void tarjan(ll u, ll fa) {
	dfn[u] = low[u] = ++t;
	for(ll i = head[u]; i; i = nxt[i]) {
		ll v = to[i];
		if(v == fa) continue;
		if(!low[v]) {
			tarjan(v, u);
			if(low[v] >= dfn[u]) block[u]++;
			else low[u]=min(low[u], low[v]);
		} else {
			low[u] = min(low[u], dfn[v]);
		}
	}
}
char s[N];
ll ans;
void solve();
int main() {
	while(Case--) solve();
}
ll num;
void solve() {
	inn("%lld %lld", &n, &m);
	for(ll i = 1; i <= n; i++) {
		inn("%s", a[i]+1);
	}
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= m; j++) {
			if(a[i][j] == '#') {
				bfs(i, j);
				num++;
			}
		}
	}
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= m; j++) {
			if(a[i][j] == '*') {
				tarjan(zip(i, j), 0);
			}
		}
	}
	ll uuu = 0;
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= m; j++) {
			if(a[i][j] == '*') {
				(ans += (num - block[zip(i, j)] + 1)) %= P;
				uuu++;
			}
		}
	}
//	(ans *= qpow(uuu, P-2))%= P;
	outt("%lld", ans);
}
