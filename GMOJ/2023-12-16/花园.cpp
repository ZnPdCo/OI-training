#include <cstdio>
#include <algorithm>
#define N 1501
using namespace std;
int n;
int r, c, ans;
struct node {
	bool use;
	short x, y;
	int val;
} a[N*N], mxh[N][6], mxl[N][6];
int f[N*N];
int cnt, lst;
bool flag;
bool cmp(node x, node y) {
	return x.val < y.val;
}
bool cmp1(node x, node y) {
	if(x.use != y.use) return x.use > y.use;
	return x.val > y.val;
}
int main() {
	scanf("%d %d %d", &n, &r, &c);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			scanf("%d", &a[++cnt].val);
			a[cnt].x = i;
			a[cnt].y = j;
			f[cnt] = -1e9;
		}
	}
	sort(a+1, a+1+cnt, cmp);
	for(int i = 1; i <= cnt; i++) {
		if(flag) {
			if(a[i].val != a[i-1].val) {
				for(int j = lst; j < i; j++) {
					mxh[a[j].x][5].x = a[j].x;
					mxh[a[j].x][5].use = 1;
					mxh[a[j].x][5].y = a[j].y;
					mxh[a[j].x][5].val = f[j];
					sort(mxh[a[j].x]+1, mxh[a[j].x]+1+5, cmp1);
					
					mxl[a[j].y][5].x = a[j].x;
					mxl[a[j].y][5].use = 1;
					mxl[a[j].y][5].y = a[j].y;
					mxl[a[j].y][5].val = f[j];
					sort(mxl[a[j].y]+1, mxl[a[j].y]+1+5, cmp1);
				}
				lst = i;
			}
			
			for(int j = 1; j <= 4; j++) {
				if(abs(mxh[a[i].x-1][j].y - a[i].y) > 1 && mxh[a[i].x-1][j].use) {
					f[i] = max(f[i], mxh[a[i].x-1][j].val+1);
				}
				if(abs(mxh[a[i].x+1][j].y - a[i].y) > 1 && mxh[a[i].x+1][j].use) {
					f[i] = max(f[i], mxh[a[i].x+1][j].val+1);
				}
				if(abs(mxl[a[i].y-1][j].x - a[i].x) > 1 && mxl[a[i].y-1][j].use) {
					f[i] = max(f[i], mxl[a[i].y-1][j].val+1);
				}
				if(abs(mxl[a[i].y+1][j].x - a[i].x) > 1 && mxl[a[i].y+1][j].use) {
					f[i] = max(f[i], mxl[a[i].y+1][j].val+1);
				}
			}
			
			ans = max(ans, f[i]);
			
		}
		if(a[i].x == r && a[i].y == c) {
			flag = true;
			f[i] = 1;
			lst = i;
		}
	}
	
	printf("%d", ans);
}
