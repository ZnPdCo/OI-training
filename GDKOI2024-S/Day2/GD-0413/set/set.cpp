#include <cstdio>
#include <cstdlib>
#define ll long long
ll n;
ll a[100][100];
ll step[100], cnt;
int main() {
//	freopen("set.in", "r", stdin);
//	freopen("set.out", "w", stdout);
	scanf("%lld", &n);
	n = 1<<n;
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= n; j++) {
			scanf("%lld", &a[i][j]);
		}
	} 
	while(true) {
		for(ll i = 1; i <= n; i++) {
			for(ll j = 1; j <= n; j++) {
				if(a[i][j]) {
					a[i][j] = ~a[i][j];
					a[i==1?n:i-1][j] = ~a[i==1?n:i-1][j];
					a[i==n?1:i+1][j] = ~a[i==n?1:i+1][j];
					a[i][j==1?n:j-1] = ~a[i][j==1?n:j-1];
					a[i][j==n?1:j+1] = ~a[i][j==n?1:j+1];
					printf("%lld %lld\n", i-1, j-1);
				}
			}
		} 
	}
	printf("-1");
}
