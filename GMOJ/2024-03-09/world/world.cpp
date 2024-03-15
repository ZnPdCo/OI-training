#include <cstdio>
#include <chrono>
#include <random>
using namespace std;
using namespace chrono;
#define ll long long
#define N 1010
ll t, n, m;
char a[N][N], b[N][N];
int main() {
	freopen("world.in", "r", stdin);
	freopen("world.out", "w", stdout);
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld %lld", &n, &m);
		for(ll i = 1; i <= n; i++) {
			scanf("%s", a[i]+1);
		}
		for(ll i = 1; i <= n; i++) {
			scanf("%s", b[i]+1);
			for(ll j = 1; j <= m; j++) {
				if(a[i][j] == b[i][j]) a[i][j] = 0;
				else a[i][j] = 1;
			}
		}
		bool flag = 1;
		for(ll i = 1; i <= n - 3; i++) {
			for(ll j = 1; j <= m - 3; j++) {
				if(a[i][j+1] ^ a[i][j+2] ^ a[i+1][j] ^ a[i+1][j+3] ^ a[i+2][j] ^ a[i+2][j+3] ^ a[i+3][j+1] ^ a[i+3][j+2]) {
					printf("No\n");
					flag = 0;
					break;
				}
			}
			if(!flag) break;
		}
		if(flag) printf("Yes\n");
	}
}
