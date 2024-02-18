#include <cstdio>
#include <cstring>
#define ll long long
#define N 14
int q, n, m;
int v[N];
int road[N][N];
int ans1, ans2;

bool vis[N];
int a[N], cnt;

void dfs(int x) {
	a[++cnt] = x;
	vis[x] = 1;
	if(cnt == n) {
		int tmp = 0;
		for(int i = 1; i <= n; i++) {
			tmp += v[i];
		}
		for(int i = 1; i < n; i++) {
			tmp += v[a[i]] * v[a[i+1]];
		}
		for(int i = 1; i < n-1; i++) {
			tmp += v[a[i]] * v[a[i+1]] * v[a[i+2]] * road[a[i]][a[i+2]];
		}
		if(tmp > ans1) {
			ans1 = tmp;
			ans2 = 1;
		} else if(tmp == ans1) {
			ans2++;
		}
		cnt--;
		vis[x] = 0;
		return;
	}
	for(int y = 1; y <= n; y++) {
		if(!road[x][y]) continue;
		if(vis[y]) continue;
		dfs(y);
	}
	vis[x] = 0;
	cnt--;
}

int main() {
	scanf("%d", &q);
	while(q--) {
		memset(road, 0, sizeof road);
		ans1 = ans2 = 0;
		
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; i++) {
			scanf("%d", &v[i]);
		}
		for(int i = 1; i <= m; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			road[x][y] = road[y][x] = 1;
		}
		for(int i = 1; i <= n; i++) {
			dfs(i);
		}
		printf("%d %d\n", ans1, ans2 / 2);
	}
	return 0;
}
