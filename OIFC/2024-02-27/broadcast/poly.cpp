#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define N 1000010
ll n, x[N], d[N];

ll read() {
	ll x = 0, f = 1;
	char c = '.';
	while(c < '0' || c > '9') {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + (c ^ '0');
		c = getchar();
	}
	return x * f;
}
ll ans1 = 1e9;
bool v[N], f[N];
void dfs1(ll u) {
	f[u] = 1;
	for(ll i = 1; i <= n; i++) {
		if(!f[i] && x[u] - d[u] <= x[i] && x[i] <= x[u] + d[u]) {
			dfs1(i);
		}
	}
}
void dfs(ll x, ll tot) {
	if(x > n) {
		memset(f, 0, sizeof f);
		for(ll i = 1; i <= n; i++) {
			if(v[i]) dfs1(i);
		}
		bool flag = 1;
		for(ll i = 1; i <= n; i++) {
			if(!f[i]) flag = 0;
		}
		if(flag) ans1 = min(ans1, tot);
		return;
	}
	v[x] = 1;
	dfs(x+1, tot + 1);
	v[x] = 0;
	dfs(x+1, tot);
} 
int main() {
//	freopen("2.in", "r", stdin);
//	freopen("4.out", "w", stdout);
	n = read();
	for(ll i = 1; i <= n; i++) {
		x[i] = read(), d[i] = read();
	}
	dfs(1, 0);
	printf("%lld", ans1);
}
