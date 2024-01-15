#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 7010
int n, m;
inline char get() { static char buf[100000], *p1 = buf, *p2 = buf; return p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,100000,stdin),p1 == p2) ? EOF : *p1 ++; }
int read() {
	int x = 0;
	char c = '.';
	while(c < '0' || c > '9') c = get();
	while(c >= '0' && c <= '9') {
		x = (x<<1)+(x<<3)+(c^'0');
		c = get();
	}
	return x;
}

struct node {
	int u, v;
} side[N];

int road[N][N];
int stopu, stopv;

bool vis[N];
bool finish;
int co[N], num;
int dfs1(int u, int fa) {
	if(finish) return 0;
	vis[u] = 1;
	for(int i = 1; i <= road[u][0]; i++) {
		int v = road[u][i];
		if(v == fa) continue;
		if(!vis[v]) {
			int res = dfs1(v, u);
			if(!res) continue;
			co[++num] = u;
			if(res == u) {
				finish = true;
				return 0;
			}
			return res;
		} else {
			co[++num] = u;
			return v;
		}
	}
	return 0;
}

int mn[N], ans[N], tot;

void dfs2(int u, int fa) {
	ans[++tot] = u;
	for(int i = 1; i <= road[u][0]; i++) {
		int v = road[u][i];
		if(v == fa || (stopu == u && stopv == v) || (stopu == v && stopv == u)) continue;
		dfs2(v, u);
	}
}
void getans() {
	for(int i = 1; i <= n; i++) {
		if(ans[i] < mn[i]) break;
		if(ans[i] > mn[i]) return;
	}
	for(int i = 1; i <= n; i++) {
		mn[i] = ans[i];
	}
}
bool cmp(node x, node y) {
	if(x.u == y.u) return x.v < y.v;
	return x.u < y.u;
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= m; i++) {
		side[2*i].u = side[2*i-1].v = read();
		side[2*i].v = side[2*i-1].u = read();
	}
	sort(side+1, side+1+2*m, cmp);
	for(int i = 1; i <= 2*m; i++) {
		road[side[i].u][++road[side[i].u][0]] = side[i].v;
	}
	mn[1] = 1e9;
	dfs1(1, 0);
	
	
	
	stopu = co[num];
	stopv = co[1];
	dfs2(1, 0);
	getans();
	for(int i = 1; i < num; i++) {
		tot = 0;
		stopu = co[i];
		stopv = co[i+1];
		dfs2(1, 0);
		getans();
	}
	for(int i = 1; i <= n; i++) {
		printf("%d ", mn[i]);
	}
}
