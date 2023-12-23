#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
#define N 1810
ll n, k;
struct node {
	ll a[N], len;
	node(ll l = 1) {memset(a, 0, sizeof(a));len = l;}
	friend node operator+(const node &x, const node &y) {
		node z(max(x.len, y.len));
		for(ll i = 1; i <= z.len; i++) {
			z.a[i] += x.a[i] + y.a[i];
			if(z.a[i] >= 10) {
				z.a[i+1] += z.a[i] / 10;
				z.a[i] %= 10;
				if(i+1 > z.len) z.len++;
			}
		}
		return z;
	} 
	void put() {
		bool flag = false;
		for(ll i = len; i >= 1; i--) {
			if(a[i] || flag) {
				flag = true;
				printf("%lld", a[i]);
			}
		}
	}
} f[2][10], ans;
int main() {
	scanf("%lld %lld", &n, &k);
	for(ll i = 0; i < k; i++) f[1][i].a[1] = 1;
	for(ll i = 2; i <= n; i++) {
		for(ll j = 0; j < k; j++) {
 			memset(f[i%2][j].a, 0, sizeof(f[i%2][j].a));
			f[i%2][j].len = 1;
		}
		for(ll j = 0; j < k; j++) {
			for(ll x = 0; x < k; x++) if(j != 0 || x != 0) {
				f[i%2][j] = f[i%2][j] + f[(i-1)%2][x];
			}
		}
	}
	for(ll i = 1; i < k; i++) ans = ans + f[n%2][i];
	ans.put();
}
