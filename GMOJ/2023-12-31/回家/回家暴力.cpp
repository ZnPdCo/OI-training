#include <cstdio>
#include <queue>
#define ll long long
#define N 510
using namespace std;
const ll dx[4]={0,1,0,-1};
const ll dy[4]={1,0,-1,0};
ll n, m;
char s[N][N];
ll w[N][N], ans;
ll stx, sty, edx, edy;
bool vis[N][N];
inline ll min(ll x, ll y) {
	return x < y ? x : y;
}
inline ll abs(ll x) {
	return x < 0 ? -x : x;
}
void dfs(ll x, ll y, ll c) {
	if(x == edx && y == edy) {
		ans = max(ans, c);
		return;
	}
	for(ll i = 0; i < 4; i++) {
		ll xx = x + dx[i];
		ll yy = y + dy[i];
		if(xx > 0 && yy > 0 && xx <= n && yy <= m) {
			if(!vis[xx][yy]) {
				vis[xx][yy] = 1;
				dfs(xx, yy, min(w[xx][yy], c));
				vis[xx][yy] = 0;
			}
		}
	}
}
int main() {
	scanf("%lld %lld", &n, &m);
	for(ll i = 1; i <= n; i++) {
		scanf("%s", s[i]+1);
	}
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= m; j++) {
			if(s[i][j] == 'V') {
				stx = i, sty = j;
			} else if(s[i][j] == 'J') {
				edx = i, edy = j;
			}
		}
	}
	
	
	// 遍历每个点，计算其危险系数
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= m; j++) {
			w[i][j] = 1e15;
			for(ll x = 1; x <= n; x++) {
				for(ll y = 1; y <= m; y++) {
					if(s[x][y] == '+') {
						w[i][j] = min(w[i][j], abs(i-x)+abs(j-y));
					}
				}
			}
		}
	}
	vis[stx][sty] = 1;
	dfs(stx, sty, w[stx][sty]);
	printf("%lld", ans);
}
