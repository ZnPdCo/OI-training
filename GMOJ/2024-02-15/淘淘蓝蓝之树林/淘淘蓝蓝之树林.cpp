#include <cstdio>
#include <cstring>
#include <ctime>
#include <string>
#include <iostream>
using namespace std;
#define N 2024
inline int min(int x, int y) {return x > y ? y : x;}

const int dx[8] = {0,1,0,-1,1,1,-1,-1};
const int dy[8] = {1,0,-1,0,1,-1,1,-1};

int n, m;
char a[N][N];

int px[10], py[10];

int mxx, mxy, mnx, mny, ans;

int f[10][10];

struct PI {
	int x, y;
	PI(int a=0, int b=0) {x = a, y = b;}
};

PI que[N*N];
int h, t;
bool vis[N][N];
int dis[N][N];
void bfs(int stx, int sty) {
	h = t = 1;
	que[1] = PI(stx, sty);
	memset(vis, 0, sizeof vis);
	for(int i = 0; i <= n+1; i++) {
		for(int j = 0; j <= m+1; j++) {
			dis[i][j] = 1e9;
		}
	}
	dis[stx][sty] = 0;
	vis[stx][sty] = 1;
	
	int x, y, xx, yy, i;
	
	while(h <= t) {
		x = que[h].x;
		y = que[h].y;
		h++;
		for(i = 0; i < 8; i++) {
			xx = x + dx[i];
			yy = y + dy[i];
			
			
			
			if(!vis[xx][yy] && a[xx][yy] != 'X' && xx >= 1 && xx <= n && yy >= 1 && yy <= m) {
				dis[xx][yy] = dis[x][y] + 1;
				vis[xx][yy] = 1;
				que[++t] = PI(xx, yy);
			}
		}
	}
}


bool v[10];

void dfs(int x, int lst, int tot) {
	if(x > 4) {
		ans = min(ans, tot + f[lst][1]);
		return;
	}
	for(int i = 2; i <= 5; i++) {
		if(!v[i]) {
			v[i] = 1;
			dfs(x+1, i, tot + f[lst][i]);
			v[i] = 0;
		}
	}
}

int main() {
	freopen("forest.in", "r", stdin);
	freopen("forest.out", "w", stdout);
	scanf("%d %d", &n, &m);
	mxx = mxy = 0;
	mnx = mny = 1e9;
	for(int i = 1; i <= n; i++) {
		scanf("%s", a[i]+1);
		for(int j = 1; j <= m; j++) {
			if(a[i][j] == '*') {
				px[1] = i, py[1] = j;
			}
			if(a[i][j] == 'X') {
				if(j > mxy) {
					mxy = j;
					px[2] = i, py[2] = j;
				}
				if(j < mny) {
					mny = j;
					px[3] = i, py[3] = j;
				}
			}
		}
	}
	
	
	ans = 1e9;
	
	if(px[1] == px[3] && py[1] < py[3]) {
		for(int i = py[2] + 1; i <= m; i++) {
			a[px[2]][i] = 'X';
		}
	} else {
		for(int i = 1; i < py[3]; i++) {
			a[px[3]][i] = 'X';
		}
	}
	
	bfs(px[1], py[1]);
	
	if(px[1] == px[3] && py[1] < py[3]) {
		for(int i = py[2] + 1; i <= m; i++) {
			for(int j = -1; j <= 1; j++) {
				for(int k = -1; k <= 1; k++) {
					ans = min(ans, dis[px[2]-1][i+j] + dis[px[2]+1][i+k] + 2);
				}
			}
		}
	} else {
		for(int i = 1; i < py[3]; i++) {
			for(int j = -1; j <= 1; j++) {
				for(int k = -1; k <= 1; k++) {
					ans = min(ans, dis[px[3]-1][i+j] + dis[px[3]+1][i+k] + 2);
				}
			}
		}
	}
	
	
	printf("%d", ans);
}
