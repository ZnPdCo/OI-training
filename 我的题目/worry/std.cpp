#include <cstdio>
#include <unordered_map>
#define ll long long
#define N 2000000
#define P 998244353
using namespace std;
ll n, m, k, g, ans;
unordered_map<ll, ll> sPhi, sD;
ll phi[N+10], sumPhi[N+10];
bool flag[N+10];
ll prime[N+10], cnt;
void init() {
	phi[1] = 1;
	for(ll i = 2; i <= N; i++) {
		if(!flag[i]) {
			phi[i] = i-1;
			prime[++cnt] = i;
		}
		for(ll j = 1; j <= cnt && i * prime[j] <= N; j++) {
			flag[i * prime[j]] = 1;
			if(i % prime[j] == 0) {
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
			phi[i * prime[j]] = phi[i] * phi[prime[j]];
		}
	}
	for(ll i = 1; i <= N; i++) {
		sumPhi[i] = sumPhi[i-1] + phi[i];
	}
}
ll qPhi(ll n) {
	if(n < 0) return 0;
	if(n <= N) return sumPhi[n];
	if(sPhi[n]) return sPhi[n];
	ll res = n * (n + 1) / 2;
	for(ll l = 2, r = 0; l <= n; l = r + 1) {
		r = n / (n / l);
		res -= (r - l + 1) * qPhi(n / l);
	}
	return sPhi[n] = res;
}
ll qD(ll n) {
	if(n < 0) return 0;
	if(g <= 32 && n >= (1ll << g)) {
		ll p = (1ll << g);
		return qD(n % p) + n / p * qD(p-1) % P;
	}
	if(sD[n]) return sD[n];
	ll res = 0;
	for(ll l = 1, r = 0; l <= n; l = r + 1) {
		r = n / (n / l);
		(res += (r - l + 1) * (n / l) % P) %= P;
	}
	return sD[n] = res;
}
int main() {
	init();
//	n = m = k = g = 1000000000;
	scanf("%lld %lld %lld %lld", &n, &m, &k, &g);
	
	for(ll i = 0; i <= 32; i++) if(n & (1ll<<i)) {
		for(ll j = 0; j <= 32; j++) if(m & (1ll<<j)) {
			ll mn = n ^ (1ll<<i), mx = m ^ (1ll<<j), mnlen = i, mxlen = j;
			mn = mn >> mxlen << mxlen;
			mx = mx >> mxlen << mxlen;
			if(mnlen > mxlen) swap(mn, mx), swap(mnlen, mxlen);
			ll L = ((mn ^ mx ^ k) >> mxlen) << mxlen;
			ll R = L + (1ll << mxlen) - 1;
			ll res1 = ((qPhi(R) - qPhi(L - 1)) % P + P) % P;
			ans += res1 * ((1ll << mnlen) % P) % P;
			
			
			L = ((mn ^ mx) >> mxlen) << mxlen;
			R = L + (1ll << mxlen) - 1;
			ll res2 = ((qD(R) - qD(L - 1)) % P + P) % P;
			ans -= res2 * ((1ll << mnlen) % P) % P;
			ans = (ans + P) % P;
		}
	}
	printf("%lld", ans);
}
