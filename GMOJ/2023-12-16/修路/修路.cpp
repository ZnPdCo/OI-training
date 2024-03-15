#include <cstdio>
#include <algorithm>
#define ll long long
#define N 1000010
using namespace std;
ll n, m, ans;
ll a[N];

struct node {
	ll u, v, w;
} b[N];

bool cmp(node x, node y) {
	return x.w < y.w;
}

ll fa[N];

ll find(ll x) {
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

inline void merge(ll x, ll y) {
	x = find(x);
	y = find(y);
	fa[x] = y;
}

int main() {
	scanf("%lld %lld", &n, &m);
	for(ll i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		fa[i] = i;
	}
	for(ll i = 1; i <= m; i++) {
		scanf("%lld %lld %lld", &b[i].u, &b[i].v, &b[i].w);
		b[i].w -= a[b[i].u];
		b[i].w -= a[b[i].v];
	}
	
	sort(b+1, b+1+m, cmp);
	
	for(ll i = 1; i <= m; i++) {
		if(find(b[i].v) != find(b[i].u)) {
			merge(b[i].v, b[i].u);
			ans += b[i].w;
		}
	}
	
	printf("%lld", ans);
	
	return 0;
}
