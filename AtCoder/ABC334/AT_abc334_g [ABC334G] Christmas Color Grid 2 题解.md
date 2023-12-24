枚举要修改的点，我们可以把相邻的绿色互相连边。原题就成了一个无向图上删掉一个点剩下的连通块个数。

用 Tarjan 算法，设 $u$ 为当前结点，$v$ 为子节点，若跑完 $v$ 后，得到 $\text{low}_v \ge \text{dfn}_u$ 则说明从 $u$ 的父亲结点，经过 $u$ 才能够到达 $v$ ，如果把结点 $u$ 删掉，则不能到达结点 $v$ 了。

这就相当于删去结点 $u$ 时，$u$ 的父亲结点与结点 $v$ 会被分成两个连通块，即这两部分无法相互到达，因此只需要数一下对于结点 $u$，它有多少个 $v$，满足 $\text{low}_v \ge \text{dfn}_u$，当然其实 $u$ 的父亲结点也算是一个儿子节点，因此需要加上一表示算上父亲节点。但每次 Tarjan 的起点是没有父亲节点的，所以不需要加一.

综上所述，删去一个结点 $u$ 会造成怎样的影响呢？假设删去结点 $u$ 会增加 $\text{block}_u$ 个连通块，这个无向图初始包含 $m$ 个连通块，这个节点原来是属于 $1$ 个连通块的，它删去后会增加 $\text{block}_u$ 个连通块，那么删去这个结点后连通块的数量应为 $m-1+\text{block}_u$。

```c++
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
#define N 2000
using namespace std;
ll n, m;
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
			if(xx > 0 && xx <= n && yy > 0 && yy <= m && a[xx][yy] != '.') {
				addEdge(zip(x, y), zip(xx, yy));
				if(a[xx][yy] == '#') {
					a[xx][yy] = '*';
					q.push(make_pair(xx, yy));
				}
			}
		}
		q.pop();
	}
}
ll dfn[N*N], low[N*N], t;
ll block[N*N];
void tarjan(ll u, ll fa) {
	dfn[u] = low[u] = ++t;
	if(fa) block[u]++;
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
ll num;
int main() {
	scanf("%lld %lld", &n, &m);
	for(ll i = 1; i <= n; i++) {
		scanf("%s", a[i]+1);
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
			if(a[i][j] == '*' && !dfn[zip(i,j)]) {
				tarjan(zip(i, j), 0);
			}
		}
	}
	ll point = 0;
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= m; j++) {
			if(a[i][j] == '*') {
				(ans += (num + block[zip(i, j)] - 1)) %= P;
				point++;
			}
		}
	}
	(ans *= qpow(point, P-2))%= P;
	printf("%lld", ans);
}
```