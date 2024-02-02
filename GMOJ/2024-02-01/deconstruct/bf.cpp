#include <cstdio>
#include <cstring>
#define ll long long
#define P 1000000007
ll n, ans;

ll cnt;
ll head[100];
ll nxt[100], to[100];

ll no[100];
void addEdge(ll u, ll v) {
	cnt++;
	to[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
}

ll a[100], v[100], num;

void find(ll u) {
	if(no[u]) return;
	num++;
	for(ll i = head[u]; i; i = nxt[i]) {
		ll v = to[i];
		find(v);
	}
}

void dfs(ll x) {
	if(x >= n) {
		memset(no, 0, sizeof no);
		for(ll i = 1; i < n; i++) {
			num = 0;
			find(a[i]);
			ans += num;
			no[a[i]] = 1;
		}
		return;
	}
	for(ll i = 2; i <= n; i++) if(!v[i]) {
		v[i] = 1;
		a[x] = i;
		dfs(x+1);
		v[i] = 0;
	}
}

ll qpow(ll n, ll m) {
	if(m == 0) return 1;
	if(m % 2 == 1) return n * qpow(n, m - 1) % P;
	ll tmp = qpow(n, m/2);
	return tmp * tmp % P;
}

int main() {
	scanf("%lld", &n);
	
	bool isLink = 1;
	bool is1 = 1;
	
	for(ll i = 2; i <= n; i++) {
		ll fa;
		scanf("%lld", &fa);
		if(fa != i-1) isLink = 0;
		if(fa != 1) is1 = 0;
		addEdge(fa, i);
	}
	if(isLink) {
		for(ll i = 1; i < n; i++) {
			(ans += i * qpow(n-i, P-2) % P) %= P;	
		}
		printf("%lld", ans);
		return 0;
	} else if(is1) {
		printf("%lld", n-1);
		return 0;
	}
	dfs(1);
	ll fac = 1;
	for(ll i = 1; i < n; i++) fac *= i;
//	(ans *= qpow(fac, P-2)) %= P;
//	printf("%lld", ans);
	printf("%.2lf", ans * 1.0 / fac);
}
