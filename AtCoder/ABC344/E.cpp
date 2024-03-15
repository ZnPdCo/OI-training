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
ll n, m, Case=1;
ll cnt;
map<ll, ll> ma;
struct node {
	ll pre, nxt, val;
} a[N*2];
void solve();
int main() {
	while(Case--) solve();
}
void solve() {
	input(n);
	a[0].nxt = 1;
	for(ll i = 1; i <= n; i++) {
		ll x;
		input(x);
		a[++cnt].val = x;
		a[cnt].pre = i-1;
		a[cnt].nxt = i+1;
		ma[x] = cnt;
	}
	a[n].nxt = -1;
	ll q;
	input(q);
	for(ll i = 1; i <= q; i++) {
		ll op;
		input(op);
		if(op == 1) {
			ll x, y;
			input(x, y);
			ll p = ma[x];
			a[++cnt].val = y;
			a[cnt].nxt = a[p].nxt;
			a[cnt].pre = p;
			a[a[p].nxt].pre = cnt;
			a[p].nxt = cnt;
			ma[y] = cnt;
		}
		if(op == 2) {
			ll x;
			input(x);
			ll p = ma[x];
			a[a[p].pre].nxt = a[p].nxt;
			a[a[p].nxt].pre = a[p].pre;
		}
	}
	for(ll p = 0; p != -1; p=a[p].nxt) {
		if(p == 0) continue;
		print(a[p].val);
	}
}
