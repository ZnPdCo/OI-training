#include <cstdio>
#include <cassert>
#include <cstring>
#define ll long long
#define N 110
ll n, m, k;
struct Matrix {
	ll n, m;
	ll v[N][N];
	Matrix() {
		memset(v, 0, sizeof v);
		n = m = 0;
	}
	friend Matrix operator* (const Matrix &x, const Matrix &y) {
		assert(x.m == y.n);
		Matrix z;
		z.n = x.n, z.m = y.m;
		for(ll i = 1; i <= x.n; i++) {
			for(ll j = 1; j <= y.m; j++) {
				for(ll k = 1; k <= x.m; k++) {
					z.v[i][j] += x.v[i][k] * y.v[k][j];
				}
			}
		}
		return z;
	}
} a, b;
int main() {
	scanf("%lld %lld %lld", &n, &m, &k);
	a.n = n, a.m = m;
	b.n = m, b.m = k;
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= m; j++) {
			scanf("%lld", &a.v[i][j]);
		}
	}
	for(ll i = 1; i <= m; i++) {
		for(ll j = 1; j <= k; j++) {
			scanf("%lld", &b.v[i][j]);
		}
	}
	
	a = a * b;
	for(ll i = 1; i <= a.n; i++) {
		for(ll j = 1; j <= a.m; j++) {
			printf("%lld ", a.v[i][j]);
		}
		printf("\n");
	}
}
