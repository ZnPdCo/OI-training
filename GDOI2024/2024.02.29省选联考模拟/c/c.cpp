#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
#define N 1010
ll t, l, r, k;
ll n, q;
ll f[N][N];
char s[N];
ll sum[N];
int main() {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld %lld %s", &n, &q, s+1);
		scanf("%lld %lld %lld", &l, &r, &k);
		for(ll i = l; i <= r; i++) {
			for(ll j = 0; j <= k; j++) {
				f[i][j] = 0;
			}
		}
		sum[l-1] = 0;
		for(ll i = l; i <= r; i++) {
			sum[i] = sum[i-1] + (s[i] == '1');
		}
		f[l-1][0] = 0;
		for(ll i = l; i <= r; i++) {
			for(ll j = 1; j <= min(i - l + 1, k); j++) {
				for(ll x = l + j - 2; x < i; x++) {
					f[i][j] = max(f[i][j], f[x][j-1] + ((sum[i] - sum[x]) > (i-x - sum[i] + sum[x])));
				}
//				printf("f[%lld][%lld]=%lld\n", i, j, f[i][j]);
			}
		}
		printf("%lld\n", f[r][k]);
	}
}
