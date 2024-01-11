#include <cstdio>
#include <cstdlib>
#define ll long long
ll n;
ll a[100][100];
ll v[100][100];
ll step[100], cnt;
void dfs(ll x) {
	if(x > n*n) {
		for(ll i = 0; i < n; i++) {
			for(ll j = 0; j < n; j++) {
			if(a[i][j] != v[i][j]) return;
			}
		}
		printf("%lld\n", cnt);
		for(ll i = 1; i <= cnt; i++) {
			printf("%lld %lld\n", step[i]/n, step[i]%n); 
		}
		exit(0);
		return;
	}
	ll i = x/n, j=x%n;
	v[i][j] = !v[i][j];
	v[i==0?n-1:i-1][j] = !v[i==0?n-1:i-1][j];
	v[i==n-1?0:i+1][j] = !v[i==n-1?0:i+1][j];
	v[i][j==0?n-1:j-1] = !v[i][j==0?n-1:j-1];
	v[i][j==n-1?0:j+1] = !v[i][j==n-1?0:j+1];
	step[++cnt] =x;
	dfs(x+1);
	v[i][j] = !v[i][j];
	v[i==0?n-1:i-1][j] = !v[i==0?n-1:i-1][j];
	v[i==n-1?0:i+1][j] = !v[i==n-1?0:i+1][j];
	v[i][j==0?n-1:j-1] = !v[i][j==0?n-1:j-1];
	v[i][j==n-1?0:j+1] = !v[i][j==n-1?0:j+1];
	cnt--;
	dfs(x+1);
}
int main() {
	freopen("set.in", "r", stdin);
	freopen("set.out", "w", stdout);
	scanf("%lld", &n);
	if(n > 2) {
		printf("-1");
		return 0;
	}
	n = 1<<n;
	for(ll i = 0; i < n; i++) {
		for(ll j = 0; j < n; j++) {
			scanf("%lld", &a[i][j]);
		}
	} 
	dfs(0);
	printf("-1");
}
