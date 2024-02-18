/**
 * @file A.cpp 
 * @tag: #AtCoder#ABC#ABC336
 * @author: ZnPdCo
 * @date: 2023-12-23 13:55:50
 * @problem: https://atcoder.jp/contests/abc336/tasks/abc336_a
 **/
#include<bits/stdc++.h>
#define ll long long
#define N 800
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
ll h, w, n, m, ans, Case=1;
char a[N][N];
char c[N];
void solve();
int main() {
	while(Case--) solve();
}
void solve() {
	input(h, w, n);
	scanf("%s", c+1);
	for(ll i = 1; i <= h; i++) {
		scanf("%s", a[i]+1);
	}
	for(ll i = 1; i <= h; i++) {
		for(ll j = 1; j <= w; j++) {
			ll x = i, y = j;
			if(a[x][y] == '#') continue;
			bool flag = true;
			for(ll k = 1; k <= n; k++) {
				if(c[k] == 'L') y--;
				if(c[k] == 'R') y++;
				if(c[k] == 'U') x--;
				if(c[k] == 'D') x++;
				if(x < 1 || x > h || y < 1 || y > w || a[x][y] == '#') {
					flag = false;
					break;
				}
			}
			if(flag) ans++;
		}
	}
	print(ans);
}
