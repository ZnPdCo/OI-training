#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
#define N 100010
ll n, m, q, u, v, t;

ll a[N], tot;

bool cmp(ll x, ll y) {
	return x > y;
}

int main() {
	scanf("%lld %lld %lld %lld %lld %lld", &n, &m, &q, &u, &v, &t);
	for(ll i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	
	for(ll i = 1; i <= m; i++) {
		ll pos = 0;
		for(ll j = 1; j < n+i; j++) {
			if(pos == 0 || a[j] > a[pos]) pos = j;
		}
		if(i % t == 0) printf("%lld ", a[pos]);
		ll a1 = a[pos] * u / v, a2 = a[pos] - a1;
		a[pos] = a1;
		a[n+i] = a2;
		for(ll j = 1; j < n+i; j++) {
			if(j != pos) a[j] += q;
		}
	}
	printf("\n");
	sort(a+1, a+1+n+m, cmp);
	for(ll i = 1; i <= n+m; i++) {
		if(i % t == 0) printf("%lld ", a[i]);
	}
}
