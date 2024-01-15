#include <cstdio>
#define ll long long
ll n;
ll a[3000][3000];
ll a1[3000][3000];
ll v[3000][3000];
int main() {
	scanf("%lld", &n);
//	a[n/2][n/2]=1;
//	while(true) {
//		for(ll x = 0; x < n; x++) {
//			for(ll y = 0; y < n; y++) {
//				a1[x][y] = a[x][y];
//			}
//		}
//		for(ll x = 0; x < n; x++) {
//			for(ll y = 0; y < n; y++) {
//				if(a1[x][y]) {
//					v[x][y] = 1;
//					a[x][y] ^= 1;
//					a[((x-1)%n+n)%n][y] ^= 1;
//					a[((x+1)%n+n)%n][y] ^= 1;
//					a[x][((y-1)%n+n)%n] ^= 1;
//					a[x][((y+1)%n+n)%n] ^= 1;
//				}
//			}
//		}
//		for(ll i = 0; i < n; i++) {
//			for(ll j = 0; j < n; j++) {
//				if(a[i][j]) printf("■");
//				else printf("□");
//			}
//			printf("\n");
//		}
//		printf("------------\n");
//	}
	while(true) {
		ll x, y;
		scanf("%lld %lld", &x, &y);
		a[x][y] ^= 1;
		a[((x-1)%n+n)%n][y] ^= 1;
		a[((x+1)%n+n)%n][y] ^= 1;
		a[x][((y-1)%n+n)%n] ^= 1;
		a[x][((y+1)%n+n)%n] ^= 1;
		for(ll i = 0; i < n; i++) {
			for(ll j = 0; j < n; j++) {
				if(a[i][j]) printf("■");
				else printf("□");
			}
			printf("\n");
		}
	}
}
