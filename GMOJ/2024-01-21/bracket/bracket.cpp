#include <cstdio>
#define ll long long
#define P 998244353
#define N 510
ll n, k;
ll pre[N];
char s[N];
ll f[N][N];
bool v[N][N];

inline bool check(char x, char y) {
	if(x == '(' && y == ')') return true;
	if(x == '?' && y == ')') return true;
	if(x == '(' && y == '?') return true;
	if(x == '?' && y == '?') return true;
	return false;
}

ll dfs(ll l, ll r) {
	if(l == r) return 0;

	if(v[l][r]) return f[l][r];

	// (S)
	if((r-1) - (l+1) + 1 <= k && pre[r-1] - pre[l] == 0 && check(s[l], s[r])) {
		(f[l][r] += 1) %= P;
	} 



	// AB、ASB
	for(ll x = l; x < r; x++) {
		for(ll y = x; y <= n && y <= x + k; y++) {
			if(pre[y] - pre[x] != 0) break;
			(f[l][r] += dfs(l, x) * dfs(y+1, r));
		}
	}
	
	if(check(s[l], s[r])) {
		// (A)
		(f[l][r] += dfs(l+1, r-1)) %= P;

		// (SA)
		for(ll x = l+1; x < r-1; x++) {
			if(pre[x] - pre[l] != 0) break;

			(f[l][r] += dfs(x+1, r-1)) %= P;
		}

		// (AS)
		for(ll x = r-1; x > l+1; x--) {
			if(pre[r-1] - pre[x-1] != 0) break;

			(f[l][r] += dfs(l+1, x-1)) %= P;
		}
	}
	v[l][r] = 1;

	printf("f[%lld][%lld]=%lld\n", l, r, f[l][r]);

	return f[l][r];
}

int main() {
	scanf("%lld %lld %s", &n, &k, s+1);

	// ()
	for(ll i = 1; i <= n; i++) {
		if(i < n && check(s[i], s[i+1])) v[i][i+1] = f[i][i+1] = 1;

		pre[i] = pre[i-1];
		if(s[i] == '(' || s[i] == ')') pre[i]++;
	}

	printf("%lld\n", dfs(1, n));
}