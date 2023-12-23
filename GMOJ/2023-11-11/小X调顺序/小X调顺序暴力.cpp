#include <cstdio>
#include <algorithm>
#define ll long long
#define N 100010
using namespace std;
ll n, k;
ll a[N];
ll ans;
int main() {
	scanf("%lld %lld", &n, &k);
	for(ll i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	for(ll i = 1; i <= k; i++) {
		for(ll i = 1; i < n; i++) {
			if(a[i] > a[i+1]) {
				swap(a[i], a[i+1]);
				break;
			}
		} 
	}
	for(ll i = 1; i <= n; i++) {
		for(ll j = i+1; j <= n; j++) {
			if(a[i] > a[j]) ans++;
		}
	}
	printf("%lld", ans);
}
