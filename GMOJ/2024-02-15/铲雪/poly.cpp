#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
#define ll long long
int n, m, q;
bool vis[60][60];
int a[60][60];
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
struct PI {
	int x, y, z;
	PI(int a=0,int b=0,int c=0) {x=a,y=b,z=c;}
};

int main() {
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 1; i <= q; i++) {
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= m; k++) {
				a[j][k]++;
			}
		}
		int op;
		scanf("%d", &op);
		if(op == 1) {
			int x;
			scanf("%d", &x);
			for(int j = 1; j <= m; j++) a[x][j]=0; 
		} else if(op == 2) {
			int x;
			scanf("%d", &x);
			for(int j = 1; j <= n; j++) a[j][x]=0; 
		} else if(op == 3) {
			int x1, y1, x2, y2, k;
			scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &k);
			if(a[x1][y1] > k) {
				printf("-1\n");
				continue;
			}
			bool flag = true;
			queue<PI> que;
			que.push(PI(x1, y1, 0));
			memset(vis, 0, sizeof vis);
			vis[x1][y1] = 1;
			while(!que.empty() && flag) {
				int x = que.front().x;
				int y = que.front().y;
				int z = que.front().z;
				que.pop();
				for(int i = 0; i < 4; i++) {
					int xx = x + dx[i];
					int yy = y + dy[i];
					if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && a[xx][yy] <= k && !vis[xx][yy]) {
						vis[xx][yy] = 1;
						que.push(PI(xx, yy, z+1));
						if(xx == x2 && yy == y2) {
							printf("%d\n", z+1);
							flag = false;
							break;
						}
						
					}
				}
			}
			if(flag) printf("-1\n");
		}
		if(i == 558) {
			for(int j = 1; j <= n; j++) {
				for(int k = 1; k <= m; k++) {
					printf("%d,", a[j][k]);
				}
				printf("\n");
			}
			printf(" ");
		}
	}
}
