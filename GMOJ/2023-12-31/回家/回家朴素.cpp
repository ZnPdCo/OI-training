#include <cstdio>
#include <queue>
#define ll long long
#define N 510
using namespace std;
const ll dx[4]={0,1,0,-1};
const ll dy[4]={1,0,-1,0};
ll n, m;
char s[N][N];
ll pre[N][N];
ll nxt[N][N];
ll w[N][N];
ll stx, sty, edx, edy;
ll dis[N][N];
ll vis[N][N];
inline ll min(ll x, ll y) {
	return x < y ? x : y;
}
inline ll abs(ll x) {
	return x < 0 ? -x : x;
}
struct pos {
	ll x, y;
	pos(ll xx=0, ll yy=0) {x=xx,y=yy;}
	friend bool operator <(const pos& x, const pos& y) {
		return x.x < y.x;
	}
	friend bool operator >(const pos& x, const pos& y) {
		return x.x > y.x;
	}
};
priority_queue<pair<ll, pos> > q;
int main() {
	scanf("%lld %lld", &n, &m);
	for(ll i = 1; i <= n; i++) {
		scanf("%s", s[i]+1);
	}
	// 计算每行每个点上一个和下一个（包括自己）
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= m; j++) {
			if(s[i][j] == '+') {
				pre[i][j] = j;
			} else {
				pre[i][j] = pre[i][j-1];
			}
			
			if(s[i][j] == 'V') {
				stx = i, sty = j;
			} else if(s[i][j] == 'J') {
				edx = i, edy = j;
			}
		}
		for(ll j = m; j >= 1; j--) {
			if(s[i][j] == '+') {
				nxt[i][j] = j;
			} else {
				nxt[i][j] = nxt[i][j+1];
			}
		}
	}
	
	// 遍历每个点，计算其危险系数
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= m; j++) {
			w[i][j] = 1e15;
			for(ll x = 1; x <= n; x++) {	// 怪物所在行
				ll y = pre[x][j];			// 计算怪物所在列
				if(y) w[i][j] = min(w[i][j], abs(i-x)+abs(j-y));
				
				y = nxt[x][j];
				if(y) w[i][j] = min(w[i][j], abs(i-x)+abs(j-y));
			}
//			printf("%lld\t", w[i][j]);
		}
//		printf("\n");
	}
	for(ll i = 1; i <= n; i++) for(ll j = 1; j <= m; j++) dis[i][j] = -1e15;
	dis[stx][sty] = w[stx][sty];
	q.push(make_pair(dis[stx][sty], pos(stx, sty)));
	while(!q.empty()) {
		ll x = q.top().second.x;
		ll y = q.top().second.y;
		q.pop();
		if(vis[x][y]) continue;
		vis[x][y] = 1;
		for(ll i = 0; i < 4; i++) {
			ll xx = x+dx[i];
			ll yy = y+dy[i];
			if(xx > 0 && yy > 0 && xx <= n && yy <= m) {
				if(!vis[xx][yy]) {
					if(dis[xx][yy] < min(w[xx][yy], dis[x][y])) {
						dis[xx][yy] = min(w[xx][yy], dis[x][y]);
						q.push(make_pair(dis[xx][yy], pos(xx, yy)));
					}
				}
			}
		}
	}
	
	printf("%lld", dis[edx][edy]);
}
