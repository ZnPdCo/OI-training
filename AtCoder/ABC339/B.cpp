/**
 * @file A.cpp 
 * @tag: #AtCoder#ABC#ABC336
 * @author: ZnPdCo
 * @date: 2023-12-23 13:55:50
 * @problem: https://atcoder.jp/contests/abc336/tasks/abc336_a
 **/
#include<bits/stdc++.h>
#define ll long long
#define N 1010
#define P 998244353
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
ll h, w, n, Case=1;
ll a[N][N];
const ll dx[4] = {-1, 0, 1, 0};
const ll dy[4] = {0, 1, 0, -1};
ll nowd, x, y;
void solve();
int main() {
	while(Case--) solve();
}
void solve() {
	input(h, w, n);
	for(ll i = 1; i <= n; i++) {
		if(a[x][y] == 0) {
			a[x][y] = 1;
			(nowd+=1) %= 4;
		} else {
			a[x][y] = 0;
			(nowd-=1) %= 4;
			nowd = (nowd+4)%4;
		}
		x += dx[nowd];
		y += dy[nowd];
		x = (x%h+h)%h;
		y = (y%w+w)%w;
	}
	for(ll i = 0; i < h; i++) {
		for(ll j = 0; j < w; j++) {
			printf("%c", a[i][j]?'#':'.');
		}
		printf("\n");
	}
}
