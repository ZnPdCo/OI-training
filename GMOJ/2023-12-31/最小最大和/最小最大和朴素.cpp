#include <cstdio>
#include <algorithm>
#define ll long long
#define N 100000
using namespace std;
ll n;
ll a[N], b[N];
bool cmp1(ll x, ll y) {
	return x < y;
}
bool cmp2(ll x, ll y) {
	return x > y;
}
int main() {
	scanf("%lld", &n);
	for(ll i = 1; i <= n; i++) {
		scanf("%lld %lld", &a[i], &b[i]);
		sort(a+1, a+1+i, cmp1);
		sort(b+1, b+1+i, cmp2);
		ll mx = 0;
		for(ll j = 1; j <= i; j++) {
			mx = max(mx, a[j]+b[j]);
		}
		printf("%lld\n", mx);
	}
}
