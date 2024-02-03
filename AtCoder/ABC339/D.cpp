/**
 * @file A.cpp 
 * @tag: #AtCoder#ABC#ABC336
 * @author: ZnPdCo
 * @date: 2023-12-23 13:55:50
 * @problem: https://atcoder.jp/contests/abc336/tasks/abc336_a
 **/
#include<bits/stdc++.h>
#define ll long long
#define N 65
#define P 61451
using namespace std;
void print() {}
template<typename T, typename... Ts>
void print(const T& x, const Ts&... y) {
	cout << x << ' ';
	print(y...);
}
void input() {}
template<typename T, typename... Ts>
void input(T& x, Ts&... y) {
	cin >> x;
	input(y...);
}
ll n, m, Case=1;
void solve();
int main() {
	while(Case--) solve();
}
const ll dx[4] = {0,1,0,-1};
const ll dy[4] = {1,0,-1,0};
struct node {
	char s[N][N];
	int t[N][N];
	ll ti;
	
	int mov(ll x) {
		ti++;
		for(ll i = 1; i <= n; i++) {
			for(ll j = 1; j <= n; j++) {
				t[i][j] = 0;
			}
		}
		bool flag = true;
		for(ll i = 1; i <= n; i++) {
			for(ll j = 1; j <= n; j++) {
				if(s[i][j] == 'P') {
					s[i][j] = '.';
					if(i+dx[x] > 0 && j+dy[x] > 0 && i+dx[x]<=n && j+dy[x]<=n && s[i+dx[x]][j+dy[x]] != '#') {
						t[i+dx[x]][j+dy[x]]++;
						flag = false;
					} else {
						t[i][j]++;
					}
				}
			}
		}
		if(flag) return -1;
		for(ll i = 1; i <= n; i++) {
			for(ll j = 1; j <= n; j++) {
				if(t[i][j] == 1) {
					s[i][j] = 'P';
				} else if(t[i][j] > 1) {
					return 1;
				}
			}
		}
		return 0;
	}
	
	void show() {
		printf("%lld\n", ti);
		for(ll i = 1; i <= n; i++) {
			for(ll j = 1; j <= n; j++) {
				printf("%c", s[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	
	ll hashh() {
		ll res = 0;
		for(ll i = 1; i <= n; i++) {
			for(ll j = 1; j <= n; j++) {
				if(s[i][j] == '.') res = res * 3 + 0;
				if(s[i][j] == '#') res = res * 3 + 1;
				if(s[i][j] == 'P') res = res * 3 + 2;
				res %= P;
			}
		}
		return res;
	}
} a, b;
ll cnt;

queue<node> que;
ll vis[P+10];

void solve() {
	input(n);
	for(ll i = 1; i <= n; i++) {
		scanf("%s", a.s[i]+1);
	}
	que.push(a);
	
	while(!que.empty()) {
		a = que.front();
		que.pop();
		ll vv = a.hashh();
		if(vis[vv]) continue;
		vis[vv] = 1;
		
		for(ll i = 0; i < 4; i++) {
			b = a;
			int res = b.mov(i);
			if(res == -1) continue;
			if(res == 1) {
				printf("%lld", b.ti);
				return;
			}
			que.push(b);
		}
	}
	printf("-1");
}
