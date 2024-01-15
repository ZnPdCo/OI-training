#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;
#define N 50010

struct node {
	int num, val;
} f[N];
// 第几个节点

int n, m;

int head[N];
int nxt[2*N];
int to[2*N], cnt;
int cost[2*N];

void addEdge(int u, int v, int w) {
	cnt++;
	to[cnt] = v;
	cost[cnt] = w;
	nxt[cnt] = head[u];
	head[u] = cnt;
}

void dfs(int u, int fa, int len) {
	multiset<int> child;
	for(int i = head[u]; i; i = nxt[i]) {
		int v = to[i];
		if(v == fa) continue;
		dfs(v, u, len);
		
		// 当前答案显然可以加上子树的答案
		f[u].num += f[v].num;
		
		if(f[v].val + cost[i] >= len) {
			f[u].num++;
		} else {
			// 统计每个子树多出来的最长链
			child.insert(f[v].val + cost[i]);
		}
	}
	
	
	// 子树多出来的最长链互相匹配，最后剩下的最大的作为新的最长链
	while(!child.empty()) {
		int num = *child.begin();
		child.erase(child.begin());
		auto pos = child.lower_bound(len - num);
		if(pos == child.end()) {
			f[u].val = max(f[u].val, num);
		} else {
			f[u].num++;
			child.erase(pos);
		}
	}
}

int c, d[N];

void dfs1(int u, int fa) {
	for(int i = head[u]; i; i = nxt[i]) {
		int v = to[i];
		if (v == fa) continue;
		d[v] = d[u] + cost[i];
		if (d[v] > d[c]) c = v;
		dfs1(v, u);
	}
}


int main() {
//	freopen("track.in", "r", stdin);
//	freopen("track.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1; i < n; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		addEdge(u, v, w);
		addEdge(v, u, w);
	}
	
	
	dfs1(1, 0);
	d[c] = 0, dfs1(c, 0);
	
	
	
	int l = 1, r = d[c], ans;
	while(l <= r) {
		int mid = (l + r) >> 1;
		memset(f, 0, sizeof f);
		dfs(1, 0, mid);
		if(f[1].num >= m) {
			ans = mid;
			l = mid+1;
		} else {
			r = mid-1;
		}
	}
	printf("%d", ans);
}
