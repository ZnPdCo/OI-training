/**
 * @file B.cpp
 * @tag: #AtCoder#ABC#ABC334
 * @author: ZnPdCo
 * @date: 2023-12-23 19:50:12
 * @problem: https://atcoder.jp/contests/abc334/tasks/abc334_b
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
ll a, m, l, r, Case=1;
void solve();
int main() {
	while(Case--) solve();
}
void solve() {
	inn("%lld %lld %lld %lld", &a, &m, &l, &r);
	l -= a;
	r -= a;
	ll k = (l / m - 1) * m;
	outt("%lld", (r-k)/m-(l-k-1)/m);
}
