#include<bits/stdc++.h>
#define ll long long
#define N 200010
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
ll n, m, q, Case=1;
bool a[N], b[N];
ll ans[N];
ll lh, lw;
ll zero;
struct node {
	ll t, a, x;
} in[N];
void solve();
int main() {
	while(Case--) solve();
}
void solve() {
	input(n, m, q);
	lh = m, lw = n;
	zero = n * m;
	for(ll i = 1; i <= q; i++) {
		input(in[i].t, in[i].a, in[i].x);
	}
	for(ll i = q; i >= 1; i--) {
		if(in[i].t == 1) {
			if(a[in[i].a]) continue;
			a[in[i].a] = 1;
			ans[in[i].x] += lh;
			lw--;
		} else {
			if(b[in[i].a]) continue;
			b[in[i].a] = 1;
			ans[in[i].x] += lw;
			lh--;
		}
	}
	ll len = 0;
	for(ll i = 1; i <= 200000; i++) {
		if(ans[i]) len++;
		zero -= ans[i];
	}
	if(zero) len++;
	print(len);
	putchar('\n');
	if(zero) {
		print(0, zero);
		putchar('\n');
	}
	for(ll i = 1; i <= 200000; i++) {
		if(ans[i]) {
			print(i, ans[i]);
			putchar('\n');
		}
	}
}
