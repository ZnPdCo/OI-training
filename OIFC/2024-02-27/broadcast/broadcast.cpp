#include <cstdio>
#include <cctype>
#include <algorithm>
#include <queue>
using namespace std;
#define N 1000010
int n;
struct broad {
	int x, d, l, r;
} a[N];

namespace graph {
	int he1[N*4], he2[N*4], nxt[N*8], to[N*8], EdgeTot;
	int inDeg[N*4];
	bool isNode[N*4];
	
	void addEdge(int head[], int u, int v) {
		EdgeTot++;
		to[EdgeTot] = v;
		nxt[EdgeTot] = head[u];
		head[u] = EdgeTot;
	}
} using namespace graph;

namespace seg {
	struct node {
		int ls, rs;
	} t[N*4];
	
	int nodeTot, root;
	
	int build(int l, int r) {
		if(l == r) {
			return l;
		}
		int pos = ++nodeTot;
		int mid = (l + r) >> 1;
		t[pos].ls = build(l, mid);
		t[pos].rs = build(mid + 1, r);
		addEdge(he1, pos, t[pos].ls);
		addEdge(he1, pos, t[pos].rs);
		return pos;
	}
	
	void add(int nl, int nr, int l, int r, int pos, int u) {
		if(nl <= l && r <= nr) {
			addEdge(he1, u, pos);
			return;
		}
		
		int mid = (l + r) >> 1;
		if(nl <= mid)
			add(nl, nr, l, mid, t[pos].ls, u);
		if(mid < nr)
			add(nl, nr, mid+1, r, t[pos].rs, u);
	}
} using namespace seg;

namespace io {
	inline char gc() {
		const int BUF = 1e6;
		static char ch[BUF], *l, *r;
		return (l == r && (r = (l = ch) + fread(ch, 1, BUF, stdin), l == r)) ? EOF : *l++;
	}
	template <typename T> inline void read(T &x) {
		x = 0; int f = 1; char c = gc();
		for (; !isdigit(c); c = gc()) if (c == '-') f = -f;
		for (; isdigit(c); c = gc()) x = (x << 1) + (x << 3) + (c ^ 48);
		x *= f;
	}
} using namespace io;

namespace tarjan {
	int dfn[N*4], low[N*4], ti, st[N*4], stTot, col, co[N*4];
	
	void solve(int u) {
		dfn[u] = low[u] = ++ti;
		st[++stTot] = u;
		for(int i = he1[u]; i; i = nxt[i]) {
			int v = to[i];
			if(!dfn[v]) {
				solve(v);
				low[u] = min(low[u], low[v]);
			} else if(!co[v]) {
				low[u] = min(low[u], dfn[v]);
			}
		}
		if(low[u] == dfn[u]) {
			co[u] = ++col;
			isNode[col] = (u <= n);
			while(st[stTot] != u) {
				isNode[col] |= (st[stTot] <= n);
				co[st[stTot]] = col;
				stTot--;
			}
			stTot--;
		}
	}
} using namespace tarjan;



int main() {
	// Yze209872
	freopen("broadcast.in", "r", stdin);
	freopen("broadcast.out", "w", stdout);
	
	read(n);
	nodeTot = n;
	
	for(int i = 1; i <= n; i++) {
		read(a[i].x), read(a[i].d);
	}
	
	for(int i = 1; i <= n; i++) {
		int l = 1, r = n;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(a[i].x - a[i].d <= a[mid].x) {
				r = mid - 1;
				a[i].l = mid;
			} else {
				l = mid + 1;
			}
		}
		l = 1, r = n;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(a[mid].x <= a[i].x + a[i].d) {
				l = mid + 1;
				a[i].r = mid;
			} else {
				r = mid - 1;
			}
		}
	}
	
	root = build(1, n);
	
	for(int i = 1; i <= n; i++) {
		add(a[i].l, a[i].r, 1, n, root, i);
	}
	
	for(int i = 1; i <= n; i++) {
		if(!dfn[i]) {
			solve(i);
		}
	}
	
	for(int u = 1; u <= nodeTot; u++) {
		if(!co[u]) continue;
		for(int i = he1[u]; i; i = nxt[i]) {
			int v = to[i];
			if(co[u] == co[v]) continue;
			if(!co[v]) continue;
			inDeg[co[v]] ++;
			addEdge(he2, co[u], co[v]);
		}
	}
	
	queue<int> que;
	
	int ans1 = 0, ans2 = 0;
	for(int i = 1; i <= col; i++) {
		if(inDeg[i] == 0) {
			que.push(i);
		}
	}
	
	while(!que.empty()) {
		int u = que.front();
		que.pop();
		if(isNode[u]) {
			ans1++;
		} else {
			for(int i = he2[u]; i; i = nxt[i]) {
				int v = to[i];
				inDeg[v]--;
				if(inDeg[v] == 0) {
					que.push(v);
				}
			}
		}
	}
	
	for(int i = 1; i <= col; i++) {
		if(isNode[i]) {
			ans2++;
		}
	}
	
	printf("%d\n%d", ans1, ans2);
}
