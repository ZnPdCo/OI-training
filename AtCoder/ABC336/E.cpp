/**
 * @file E.cpp 
 * @tag: #AtCoder#ABC#ABC336
 * @author: ZnPdCo
 * @date: 2023-12-23 13:55:50
 * @problem: https://atcoder.jp/contests/abc336/tasks/abc336_e
 **/
#include<bits/stdc++.h>
#define ll long long
#define N 20
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
ll n, m, Case=1, ans;
char s[N];
ll f[N][N*10][N*10][2];
// 长度 数位和 模后值
void solve();
int main() {
	while(Case--) solve();
}
void dp(ll sum) {
	memset(f, 0, sizeof f);
	for(ll i = 0; i < 10; i++) {
		if(i < s[1]) {
			f[1][i][i % sum][0] = 1;
		} else if(i == s[1]) {
			f[1][i][i % sum][1] = 1;
		}
	}
	for(ll i = 2; i <= n; i++) {
		for(ll j = 0; j <= sum; j++) {
			for(ll k = 0; k < sum; k++) {
				if(!f[i-1][j][k][0]) continue;
				for(ll x = 0; x < 10; x++) {
					f[i][j+x][(k*10+x)%sum][0] += f[i-1][j][k][0];
				}
			}
			for(ll k = 0; k < sum; k++) {
				if(!f[i-1][j][k][1]) continue;
				for(ll x = 0; x < 10; x++) {
					if(x < s[i]) {
						f[i][j+x][(k*10+x)%sum][0] += f[i-1][j][k][1];
					} else if(x == s[i]) {
						f[i][j+x][(k*10+x)%sum][1] += f[i-1][j][k][1];
					}
				}
			}
		}
	}
	
	ans += f[n][sum][0][0] + f[n][sum][0][1];
}
void solve() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s+1);
	n = strlen(s+1);
	for(ll i = 1; i <= n; i++) s[i] -= '0';
	for(ll i = 1; i <= 9*n; i++) {
		dp(i);
	}
	print(ans);
}
