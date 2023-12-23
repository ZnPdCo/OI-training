/**
 * @file A.cpp
 * @tag: #AtCoder#ABC#ABC334
 * @author: ZnPdCo
 * @date: 2023-12-23 19:50:12
 * @problem: https://atcoder.jp/contests/abc334/tasks/abc334_a
 **/
#include <bits/stdc++.h>
#define ll long long
#define debug() printf("debug");
#define newll(x) ll x = 0
#define newarr(x) ll x[N] = {0}
#define newvis(x) bool x[N] = {0}
#define outt printf
#define inn scanf
using namespace std;
ll n, m, Case=1;
void solve();
int main() {
	while(Case--) solve();
}
void solve() {
	inn("%lld %lld", &n, &m);
	if(n > m) printf("Bat");
	else printf("Glove");
}
