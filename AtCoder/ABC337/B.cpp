/**
 * @file A.cpp 
 * @tag: #AtCoder#ABC#ABC336
 * @author: ZnPdCo
 * @date: 2023-12-23 13:55:50
 * @problem: https://atcoder.jp/contests/abc336/tasks/abc336_a
 **/
#include<bits/stdc++.h>
#define ll long long
#define N 110
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
char s[N];
void solve();
bool a, b, c, flag = true;
int main() {
	while(Case--) solve();
}
void solve() {
	scanf("%s", s+1);
	for(ll i = 1; s[i] != '\0'; i++) {
		if(s[i] == 'A') {
			if(b == 1 || c == 1) flag = 0;
			a = 1;
		} else if(s[i] == 'B') {
			if(c == 1) flag = 0;
			b = 1;
		} else {
			c = 1;
		}
	}
	if(flag) print("Yes");
	else print("No");
}
