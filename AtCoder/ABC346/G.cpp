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
ll n, Case=1;
ll a[N], L[N], R[N];
ll e[N];
struct node {
	ll l, r, h, v;
} edge[2 * N];
ll cnt;
inline void add(ll l, ll r, ll h, ll v) {
	cnt ++;
	edge[cnt].l = l;
	edge[cnt].r = r;
	edge[cnt].h = h;
	edge[cnt].v = v;
}
void solve();
int main() {
	while(Case--) solve();
}

ll t[4*N][2], ans;
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
void update(ll nl, ll nr, ll k, ll l, ll r, ll pos) {
	if(nl <= l && r <= nr) {
		t[pos][0] += k;
		if(t[pos][0]) t[pos][1] = r - l + 1;
		else if(l == r) t[pos][1] = 0;
		else t[pos][1] = t[ls(pos)][1] + t[rs(pos)][1];
		return;
	}
	ll mid = (l + r) >> 1;
	if(nl <= mid)
		update(nl, nr, k, l, mid, ls(pos));
	if(mid < nr)
		update(nl, nr, k, mid + 1, r, rs(pos));
	if(t[pos][0]) t[pos][1] = r - l + 1;
	else if(l == r) t[pos][1] = 0;
	else t[pos][1] = t[ls(pos)][1] + t[rs(pos)][1];
}
void solve() {
	input(n);
	for(ll i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		R[i] = n;
	}
	for(ll i = 1; i <= n; i++) {
		L[i] = e[a[i]] + 1;
		R[e[a[i]]] = i - 1;
		e[a[i]] = i;
	}
	for(ll i = 1; i <= n; i++) {
		add(i, R[i], L[i], 1);
		add(i, R[i], i + 1, -1);
	}
	sort(edge + 1, edge + 1 + cnt, [&](const auto &x, const auto &y) {
		return x.h < y.h;
	});
	for(ll i = 1; i < cnt; i++) {
		update(edge[i].l, edge[i].r, edge[i].v, 1, n, 1);
		ans += t[1][1] * (edge[i + 1].h - edge[i].h);
	}
	print(ans);
}
