#include <cstdio>
#include <cassert>
#include <cstring>
#define ll long long
#define N 110
#define P 1000000007
ll n, k;
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
					(z.v[i][j] += x.v[i][k] * y.v[k][j] % P) %= P;
				}
			}
		}
		return z;
	}
} a, z;
Matrix qpow(const Matrix &a, ll b) {
	if(b == 0) return z;
	if(b % 2 == 1) return a * qpow(a, b-1);
	Matrix tmp = qpow(a, b/2);
	return tmp * tmp;
}
int main() {
	scanf("%lld %lld", &n, &k);
	a.n = n, a.m = n;
	z.n = n, z.m = n;
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= n; j++) {
			scanf("%lld", &a.v[i][j]);
		}
		z.v[i][i] = 1;
	}
	
	a = qpow(a, k);
	for(ll i = 1; i <= a.n; i++) {
		for(ll j = 1; j <= a.m; j++) {
			printf("%lld ", a.v[i][j]);
		}
		printf("\n");
	}
}
