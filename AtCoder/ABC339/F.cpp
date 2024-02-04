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
#define P1 6000023
#define P2 6000041
#define P3 6145159
#define P4 6145171
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
ll a[N][4];
ll res[4];
char s[N];
void solve();
int main() {
//	input(Case);
	while(Case--) solve();
}
void read() {
	res[0] = res[1] = res[2] = res[3] = 0;
	char c = '.';
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9') {
		res[0] = res[0] * 10 % P1 + (c ^ '0') % P1;
		res[1] = res[1] * 10 % P2 + (c ^ '0') % P2;
		res[2] = res[2] * 10 % P3 + (c ^ '0') % P3;
		res[3] = res[3] * 10 % P4 + (c ^ '0') % P4;
		c = getchar();
	}
}
int he1[P1+10], he2[P2+10], he3[P3+10], he4[P4+10];
ll ans;
void solve() {
	input(n);
	for(ll i = 1; i <= n; i++) {
		read();
		a[i][0] = res[0];
		a[i][1] = res[1];
		a[i][2] = res[2];
		a[i][3] = res[3];
		he1[res[0]]++;
		he2[res[1]]++;
		he3[res[2]]++;
		he4[res[3]]++;
	}
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= n; j++) {
			ll num1 = a[i][0] * a[j][0] % P1;
			ll num2 = a[i][1] * a[j][1] % P2;
			ll num3 = a[i][2] * a[j][2] % P3;
			ll num4 = a[i][3] * a[j][3] % P4;
			ans += min(he1[num1], min(he2[num2], min(he3[num3], he4[num4])));
		}
	}
	print(ans);
}
