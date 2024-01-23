/**
 * @file A.cpp 
 * @tag: #AtCoder#ABC#ABC336
 * @author: ZnPdCo
 * @date: 2023-12-23 13:55:50
 * @problem: https://atcoder.jp/contests/abc336/tasks/abc336_a
 **/
#include<bits/stdc++.h>
#define ll long long
#define N 200010
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
ll n, m, k, Case=1, ans = 1e15;
string s[N];
vector<ll> pre1[N];
vector<ll> nxt1[N];
vector<ll> pre2[N];
vector<ll> nxt2[N];
void solve();
int main() {
	while(Case--) solve();
}
void solve() {
	input(n, m, k);
	for(ll i = 1; i <= n; i++) {
		input(s[i]);
		s[i] = " " + s[i];
		pre1[i].push_back(0);
		nxt1[i].push_back(0);
		for(ll j = 1; j <= m; j++) {
			pre1[i].push_back(0);
			nxt1[i].push_back(0);
		}
	}
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= m; j++) {
			pre1[i][j] = pre1[i][j-1];
			if(s[i][j] == 'o') pre1[i][j] = pre1[i][j-1] + 1;
		}
		ll lst = 1e15;
		for(ll j = m; j >= 1; j--) {
			if(s[i][j] == 'x') lst = j;
			nxt1[i][j] = lst;
		}
	}
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= m-k+1; j++) {
			if(nxt1[i][j] - j + 1 > k) {
				ans = min(ans, k - (pre1[i][j+k-1] - pre1[i][j-1]));
			}
		}
	}
	
	
	
	for(ll i = 1; i <= m; i++) {
		pre2[i].push_back(0);
		nxt2[i].push_back(0);
		for(ll j = 1; j <= n; j++) {
			pre2[i].push_back(0);
			nxt2[i].push_back(0);
		}
	}
	for(ll i = 1; i <= m; i++) {
		for(ll j = 1; j <= n; j++) {
			pre2[i][j] = pre2[i][j-1];
			if(s[j][i] == 'o') pre2[i][j] = pre2[i][j-1] + 1;
		}
		ll lst = 1e15;
		for(ll j = n; j >= 1; j--) {
			if(s[j][i] == 'x') lst = j;
			nxt2[i][j] = lst;
		}
	}
	for(ll i = 1; i <= m; i++) {
		for(ll j = 1; j <= n-k+1; j++) {
			if(nxt2[i][j] - j + 1 > k) {
				ans = min(ans, k - (pre2[i][j+k-1] - pre2[i][j-1]));
			}
		}
	}
	
	if(ans == 1e15) print(-1);
	else print(ans);
}
