/**
 * @file E.cpp
 * @tag: #AtCoder#ABC#ABC334
 * @author: ZnPdCo
 * @date: 2023-12-23 19:50:12
 * @problem: https://atcoder.jp/contests/abc334/tasks/abc334_e
 **/
#include <bits/stdc++.h>
#define ll long long
#define N 1100
#define P 998244353
#define debug() printf("debug");
#define newll(x) ll x = 0
#define newarr(x) ll x[N] = {0}
#define newvis(x) bool x[N] = {0}
#define outt printf
#define inn scanf
using namespace std;
ll n, m, Case=1, sum, num, red;
char a[N][N];
ll fa[N*N];
const ll dx[4] = {0, 1, 0, -1};
const ll dy[4] = {1, 0, -1, 0};
void solve();
int main() {
	while(Case--) solve();
}
ll zip(ll x, ll y, bool flag = false) {
	if(x <= 0 || x > n || y <= 0 || y > m) return -114;
	if(flag) if(a[x][y] == '.') return -114;
	return x * (m+10) + y;
}
ll find(ll x) {
	if(x == -114) return -114;
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void merge(ll x, ll y) {
	fa[find(x)] = find(y);
}
void bfs(ll x, ll y) {
	a[x][y] = '*';
	queue<pair<ll, ll> > q;
	q.push(make_pair(x, y));
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		for(ll i = 0; i < 4; i++) {
			ll xx = x + dx[i];
			ll yy = y + dy[i];
			if(xx > 0 && xx <= n && yy > 0 && yy <= m && a[xx][yy] == '#') {
				a[xx][yy] = '*';
				merge(zip(x, y), zip(xx, yy));
				q.push(make_pair(xx, yy));
			}
		}
		q.pop();
	}
}
ll qpow(ll x, ll y) {
	if(y == 0) return 1;
	if(y % 2 == 1) return x * qpow(x, y - 1) % P;
	ll tmp = qpow(x, y / 2);
	return tmp * tmp % P;
}
void solve() {
	inn("%lld %lld", &n, &m);
	for(ll i = 1; i <= n; i++) {
		inn("%s", a[i]+1);
	}
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= m; j++) {
			fa[zip(i, j)] = zip(i, j);
		}
	}
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= m; j++) {
			if(a[i][j] == '#') {
				bfs(i, j);
				num++;
			}
		}
	}
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= m; j++) {
			if(a[i][j] == '.') {
				ll k[5];
				k[0] = 0;
				k[1] = find(zip(i-1, j, 1));
				k[2] = find(zip(i+1, j, 1));
				k[3] = find(zip(i, j-1, 1));
				k[4] = find(zip(i, j+1, 1));
				sort(k+1,k+5);
				ll kind=0;
				for(ll x = 1; x <= 4; x++) {
					if(k[x] == -114) continue;
					if(k[x] != k[x-1]) kind++;
				}
				(sum += num - kind + 1) %= P;
				red++;
			}
		}
	}
	(sum *= qpow(red, P-2)) %= P;
	outt("%lld", sum);
}
