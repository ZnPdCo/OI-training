/**
 * @file 回家.cpp 
 * @tag: #GMOJ#最短路#宽搜
 * @author: ZnPdCo
 * @date: 2023-12-31 14:28:25
 * @problem: https://gmoj.net/senior/#main/show/1445
 **/
#include <cstdio>
#include <queue>
#include <cstring>
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
int main() {
	scanf("%lld %lld", &n, &m);
	for(ll i = 1; i <= n; i++) {
		scanf("%s", s[i]+1);
	}
	
	// 计算每行每个点上一个和下一个（包括自己）
	// 方法炸了，N^3果然还是太大
	// 考虑宽搜降到N^2
	queue<pos> que;
	
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= m; j++) {
			w[i][j] = 1e15;
			if(s[i][j] == '+') {
				que.push(pos(i, j));
				w[i][j] = 0;
			}
			if(s[i][j] == 'V') {
				stx = i, sty = j;
			} else if(s[i][j] == 'J') {
				edx = i, edy = j;
			}
		}
	}
	
	while(!que.empty()) {
		ll x = que.front().x;
		ll y = que.front().y;
		que.pop();
		for(ll i = 0; i < 4; i++) {
			ll xx = x+dx[i];
			ll yy = y+dy[i];
			if(xx > 0 && yy > 0 && xx <= n && yy <= m) {
				if(w[xx][yy] > w[x][y]+1) {
					w[xx][yy] = w[x][y]+1;
					que.push(pos(xx, yy));
				}
			}
		}
	}
	
	
	priority_queue<pair<ll, pos> > q;
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
