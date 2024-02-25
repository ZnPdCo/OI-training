#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 1000010
int t, n, m, ans;

struct PI {
	int first, second;
	PI(int a, int b) {first = a, second = b;}
};

namespace Graph {
	int head[N];
	int nxt[2*N];
	int to[2*N], cnt;
	
	void addEdge(int u, int v) {
		cnt++;
		to[cnt] = v;
		nxt[cnt] = head[u];
		head[u] = cnt;
	}
	
	void init() {
		__builtin_memset(head, 0, sizeof head);
		cnt = 0;
	}
}

namespace Loop {
	int dfn[N], fa[N], ti;
	int loop[N], num, flag[N];
	void dfs(int u) {
		using namespace Graph;
		dfn[u] = ++ti;
		for(int i = head[u]; i; i = nxt[i]) {
			int v = to[i];
			if(v == fa[u]) continue;
			if(!dfn[v]) {
				fa[v] = u;
				dfs(v);
			} else if(dfn[v] > dfn[u]) {
				for(; v != fa[u]; v = fa[v]) {
					loop[++num] = v;
					flag[v] = 1;
				}
			}
		}
	}
	
	void solve() {
		__builtin_memset(dfn, 0, sizeof dfn);
		__builtin_memset(fa, 0, sizeof fa);
		__builtin_memset(loop, 0, sizeof loop);
		__builtin_memset(flag, 0, sizeof flag);
		ti = num = 0;
		dfs(1);
	}
}

namespace Punch {
	int res;
	bool f[N];
	bool inTree;
	int nou, nov;
	
	void dfs(int u, int fa) {
		using namespace Graph;
		f[u] = 1;
		int sum = 0;
		for(int i = head[u]; i; i = nxt[i]) {
			int v = to[i];
			if(v == fa) continue;
			if(inTree && Loop::flag[v]) continue;
			if(u == nou && v == nov) continue;
			if(u == nov && v == nou) continue;
			
			dfs(v, u);
			sum += f[v];
		}
		
		if(sum) f[u] = 0, sum--;
		res += sum;
	}
	
	PI solve(int u, int _nou, int _nov, bool _inTree) {
		res = 0;
		inTree = _inTree, nou = _nou, nov = _nov;
		
		dfs(u, 0);
		return PI(res, f[u]);
	}
}

int main() {
	scanf("%d", &t);
	while(t--) {
		ans = 0;
		Graph::init();
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= m; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			Graph::addEdge(u, v);
			Graph::addEdge(v, u);
		}
		
		Loop::solve();
		
		if(Loop::num == 0) {
			auto res = Punch::solve(1, 0, 0, 0);
			ans = res.first + res.second;
		} else {
			auto res = Punch::solve(1, Loop::loop[2], Loop::loop[3], 0);
			ans = res.first + res.second;
			
			res = Punch::solve(1, Loop::loop[1], Loop::loop[2], 0);
			ans = min(ans, res.first + res.second);
			
			int sum = 0;
			for(int i = 1; i <= Loop::num; i++) {
				res = Punch::solve(Loop::loop[i], 0, 0, 1);
				sum += res.first + (res.second ^ 1);
			}
			ans = min(ans, sum);
		}
		
		if(ans == 0) printf("Yes\n");
		else printf("%d\n", ans);
	}
	
	return 0;
}
