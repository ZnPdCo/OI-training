#include <cstdio>
#include <algorithm>
#include <testlib.h>
#define ll long long
#define N 210
using namespace std;

ll n, m, k;
bool vis[N][N], flag[N];
ll head[N];
ll nxt[N*N];
ll to[N*N], cnt;
ll rd[N];

void addEdge(ll u, ll v) {
	++cnt;
	to[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
}

ll f[N];
ll que[N], h = 1, t;

int main(int argc, char *argv[]) {
	registerTestlibCmd(argc, argv);

	k = inf.readLong();
	n = ouf.readLong(1ll, 200ll), m = ouf.readLong(1ll, n*(n-1));
	
	for (int i = 1; i <= m; i++) {
		ll u = ouf.readLong(1, n), v = ouf.readLong(1, n);
		if(vis[u][v])
			quitf(_wa, "graph have multiple edge in {%lld, %lld}.", u, v);
		if(u == v)
			quitf(_wa, "graph have loop in {%lld}.", u);
		vis[u][v] = 1;
		addEdge(u, v);
		rd[v]++;
	}
	
	for (int i = 1; i <= n;i++) {
		if(!rd[i]) {
			que[++t] = i;
		}
	}
	
	f[1] = 1;
	
	while(h <= t) {
		ll u = que[h++];
		flag[u] = 1;
		
		for(int i = head[u]; i; i = nxt[i]) {
			ll v = to[i];
			f[v] += f[u];
			rd[v]--;
			if(!rd[v]) {
				que[++t] = v;
			}
		}
	}
	
	for (int i = 1; i <= n;i++) {
		if(!flag[i]) {
			quitf(_wa, "graph have cycle in {%d}.", i);
		}
	}
	

	if(f[n] == k) {
		quitf(_ok, "answer is {%lld}.", k);
	} else {
		quitf(_wa, "expected {%lld}, found {%lld}.", k, f[n]);
	}
}
