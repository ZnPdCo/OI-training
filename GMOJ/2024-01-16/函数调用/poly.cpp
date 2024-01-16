#include <cstdio>
#include <queue>
#define ll long long
#define N 100010
#define M 1000010
#define P 998244353
using namespace std;
ll n, m, q;
ll a[N];

ll f[N];

struct node {
	ll t, p, v;
} k[N];

ll head[N];
ll nxt[2*M], to[2*M], cnt;
void addEdge(ll u, ll v) {
	cnt++;
	to[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
}

void dfs(ll u) {
	if(k[u].t == 1) {
		(a[k[u].p] += k[u].v) %= P;
		return;
	} else if(k[u].t == 2) {
		for(ll i = 1; i <= n; i++) {
			(a[i] *= k[u].v) %= P;
		}
		return;
	}
	for(ll i = head[u]; i; i = nxt[i]) {
		ll v = to[i];
		dfs(v);
	}
}

int main() {
	scanf("%lld", &n);
	for(ll i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	scanf("%lld", &m);
	for(ll i = 1; i <= m; i++) {
		scanf("%lld", &k[i].t);
		if(k[i].t == 1) {
			scanf("%lld %lld", &k[i].p, &k[i].v);
		} else if(k[i].t == 2) {
			scanf("%lld", &k[i].v);
		} else {
			ll c;
			scanf("%lld", &c);
			for(ll j = 1; j <= c; j++) {
				scanf("%lld", &f[j]);
				if(f[j] == -1) return 0&printf("0");
			}
			for(ll j = c; j >= 1; j--) {
				addEdge(i, f[j]);
			}
		}
	}
	ll q;
	scanf("%lld", &q);
	k[0].t = 3;
	for(ll j = 1; j <= q; j++) {
		scanf("%lld", &f[j]);
	}
	for(ll j = q; j >= 1; j--) {
		addEdge(0, f[j]);
	}
	
	dfs(0);
	
	for(ll i = 1; i <= n; i++) {
		printf("%lld ", a[i]);
	}
}
