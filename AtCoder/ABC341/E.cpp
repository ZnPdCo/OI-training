/**
 * @file A.cpp 
 * @tag: #AtCoder#ABC#ABC336
 * @author: ZnPdCo
 * @date: 2023-12-23 13:55:50
 * @problem: https://atcoder.jp/contests/abc336/tasks/abc336_a
 **/
#include<bits/stdc++.h>
#define ll long long
#define N 500010
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
ll n, m, Case=1;
char s[N];
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
struct node {
	ll lc, rc, flag, lazy;
} t[4*N];

void pushup(ll pos) {
	if(t[ls(pos)].flag && t[rs(pos)].flag && t[ls(pos)].rc != t[rs(pos)].lc) {
		t[pos].flag = 1;
	} else {
		t[pos].flag = 0;
	}
	t[pos].lc = t[ls(pos)].lc;
	t[pos].rc = t[rs(pos)].rc;
}
void pushdown(ll pos) {
	t[ls(pos)].lc ^= 1;
	t[ls(pos)].rc ^= 1;
	t[ls(pos)].lazy ^= t[pos].lazy;
	t[rs(pos)].lc ^= 1;
	t[rs(pos)].rc ^= 1;
	t[rs(pos)].lazy ^= t[pos].lazy;
	t[pos].lazy = 0;
}


void build(ll l, ll r, ll pos) {
	if(l == r) {
		t[pos].lc = t[pos].rc = s[l] - '0';
		t[pos].flag = 1;
		t[pos].lazy = 0;
		return;
	}
	
	ll mid = (l + r) >> 1;
	build(l, mid, ls(pos));
	build(mid+1, r, rs(pos));
	pushup(pos);
}


void update(ll nl, ll nr, ll l, ll r, ll pos) {
	if(nl <= l && r <= nr) {
		t[pos].lc ^= 1;
		t[pos].rc ^= 1;
		t[pos].lazy ^= 1;
		return;
	}
	
	if(t[pos].lazy) {
		pushdown(pos);
	}
	
	ll mid = (l + r) >> 1;
	if(nl <= mid)
		update(nl, nr, l, mid, ls(pos));
	if(mid < nr)
		update(nl, nr, mid+1, r, rs(pos));
	
	pushup(pos);
}

node query(ll nl, ll nr, ll l, ll r, ll pos) {
	if(nl <= l && r <= nr) {
		return t[pos];
	}
	
	if(t[pos].lazy) {
		pushdown(pos);
	}
	
	ll mid = (l + r) >> 1;
	node res1, res2, res;
	
	if(nl <= mid)
		res1 = query(nl, nr, l, mid, ls(pos));
	if(mid < nr)
		res2 = query(nl, nr, mid+1, r, rs(pos));
	
	if(nl <= mid && !(mid < nr)) return res1;
	if(!(nl <= mid) && mid < nr) return res2;
	else {
		if(res1.flag && res2.flag && res1.rc != res2.lc) {
			res.flag = 1;
		} else {
			res.flag = 0;
		}
		res.lc = res1.lc;
		res.rc = res2.rc;
		return res;
	}
}

void solve();
int main() {
	while(Case--) solve();
}
void solve() {
	input(n, m);
	scanf("%s", s+1);
	build(1, n, 1);
	for(ll i = 1; i <= m; i++) {
		ll op, l, r;
		scanf("%lld %lld %lld", &op, &l, &r);
		if(op == 1) {
			update(l, r, 1, n, 1);
		} else {
			if(query(l, r, 1, n, 1).flag) printf("Yes\n");
			else printf("No\n");
		}
	}
}
