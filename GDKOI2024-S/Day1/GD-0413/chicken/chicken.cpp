#include <cstdio>
#include <algorithm>
#define ll long long
#define N 3010
#define P 998243
using namespace std;
ll n, m, p;
ll a[N];
ll v[N];
ll f[N], res, ans;
ll hah[P];
void dfs2(ll x, ll sum) {
	res = max(res, sum);
	for(ll i = 1; i <= n; i++) {
		if(v[i-1] || v[i] || v[i+1]) continue;
		v[i] = 1;
		dfs2(x+1, sum + a[i]);
		v[i] = 0;
	}
}
void dfs(ll x) {
	if(x > n) {
		ll ha=0;
		for(ll i = 1; i <= n; i++) {
			res = 0;
			ll cnt = a[i];
			a[i] = 0;
			dfs2(i, 0);
			a[i] = cnt;
			(ha=ha*137+res) %= P;
		}
		if(!hah[ha]) hah[ha]=1, ans++;
		return;
	}
	for(ll i = 0; i <= m; i++) {
		a[x] = i;
		dfs(x+1);
	}
}
int main() {
	freopen("chicken.in", "r", stdin);
	freopen("chicken.out", "w", stdout);
	scanf("%lld %lld", &n, &m, &p);
	dfs(1);
	printf("%lld", ans);
}
