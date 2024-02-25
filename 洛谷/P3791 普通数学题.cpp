#include <cstdio>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define ll long long
#define P 998244353
ll n, m, x, ans;
unordered_map<ll, ll> sD;
ll qD(ll n) {
	if(sD[n]) return sD[n];
	ll res = 0;
	for(ll l = 1, r = 0; l <= n; l = r + 1) {
		r = n / (n / l);
		(res += (r - l + 1) * (n / l) % P) %= P;
	}
	return sD[n] = res;
}
ll clac(ll a, ll b, ll alen, ll blen) {
	if(alen > blen) swap(a, b), swap(alen, blen);
	ll L = ((a ^ b ^ x) >> blen) << blen;
	ll R = L + (1ll << blen) - 1;
	return ((qD(R) - qD(L - 1)) % P + P) % P * ((1ll << alen) % P) % P;
}
int main() {
	scanf("%lld %lld %lld", &n, &m, &x);
	n++, m++;
	for(ll i = 50; i >= 0; i--) if(n & (1ll<<i)) {
		for(ll j = 50; j >= 0; j--) if(m & (1ll<<j)) {
			(ans += clac(n ^ (1ll<<i), m ^ (1ll<<j), i, j)) %= P; 
		}
	}
	printf("%lld", ans);
}
