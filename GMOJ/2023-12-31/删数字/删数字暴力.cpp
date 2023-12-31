#include <cstdio>
#include <algorithm>
#define ll long long
#define N 1000010
using namespace std;
ll a[N], n, k;
ll v[N];
ll ans=1e15;
void dfs(ll x) {
	if(x > k) {
		ll mx=-1e15, mn=1e15;
		ll lst = -1e15, a2=1e15;
		for(ll i = 1; i <= n; i++) if(!v[i]) {
			mx = max(mx, a[i]);
			mn = min(mn, a[i]);
			if(lst != -1e15) a2 = min(a2, a[i] - lst);
			lst = a[i];
		}
		if(mx - mn + a2 < ans) {
			ans = mx-mn+a2;
		}
		return;
	}
	for(ll i = 1; i <= n; i++) if(!v[i]) {
		v[i] = 1;
		dfs(x+1);
		v[i] = 0;
	}
}
bool cmp(ll x, ll y) {
	return x < y;
}
int main() {
	scanf("%lld %lld", &n, &k);
	for(ll i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+1+n, cmp);
	dfs(1);
	printf("%lld", ans);
}
