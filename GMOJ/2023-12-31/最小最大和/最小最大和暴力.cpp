#include <cstdio>
#include <algorithm>
#define ll long long
#define N 100010
using namespace std;
ll n;
ll a[N], b[N], mn, c1[N], c2[N], v1[N], v2[N];
ll k;
void dfs2(ll x) {
	if(x > k) {
		ll mx = 0;
		for(ll i = 1; i <= k; i++) {
			mx = max(mx, a[c1[i]]+b[c2[i]]);
		}
		mn = min(mn, mx);
		return;
	}
	for(ll i = 1; i <= k; i++) if(!v2[i]) {
		v2[i] = 1;
		c2[x] = i;
		dfs2(x+1);
		v2[i] = 0;
	}
}
void dfs1(ll x) {
	if(x > k) {
		dfs2(1);
		return;
	}
	for(ll i = 1; i <= k; i++) if(!v1[i]) {
		v1[i] = 1;
		c1[x] = i;
		dfs1(x+1);
		v1[i] = 0;
	}
}
int main() {
	scanf("%lld", &n);
	for(ll i = 1; i <= n; i++) {
		scanf("%lld %lld", &a[i], &b[i]);
		mn = 1e15;
		k = i;
		dfs1(1);
		printf("%lld\n", mn);
	}
}
