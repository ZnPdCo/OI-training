#include <cstdio>
#include <cstring>
#define ll long long
#define N 210
ll t, n, m;
ll a[N][N];
//    ÐÐ      ÁÐ 
bool hang[N][N], lie[N][N];
void solve() {
	memset(hang, 0, sizeof hang);
	memset(lie, 0, sizeof lie);
	scanf("%lld %lld", &n, &m);
	for(ll i = 1; i <= n; i++) {
		for(ll j = i+1; j <= n; j++) {
			scanf("%lld", &a[i][j]);
			if(hang[i][a[i][j]] || lie[j][a[i][j]] || lie[i][a[i][j]]) return (void)(printf("No\n"));
			hang[i][a[i][j]] = 1;
			lie[j][a[i][j]] = 1;
		}
	}
	for(ll i = 1; i <= m; i++) {
		ll num = -1;
		for(ll k = 1; k <= m; k++) {
			if(!hang[i][k] && !lie[i][k] && !lie[m+1][k]) {
				num = k;
				break;
			}
		}
		if(num == -1) {
			return (void)(printf("No\n"));
		}
		hang[i][num] = 1;
		lie[m+1][num] = 1;
		a[i][m+1] = num;
	}
	printf("Yes\n");
	for(ll i = 1; i <= m; i++) {
		for(ll j = i+1; j <= m; j++) {
			printf("%lld ", a[i][j]);
		}
		printf("%lld", a[i][m+1]);
		if(i < m) printf("\n");
	}
	if(t) printf("\n");
}
int main() {
	freopen("capella.in", "r", stdin);
	freopen("capella.out", "w", stdout);
	scanf("%lld", &t);
	while(t--) {
		solve();
	}
}
