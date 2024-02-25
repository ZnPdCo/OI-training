#include <cstdio>
#include <unordered_map>
#define ll long long
#define N 2000000
using namespace std;
unordered_map<ll, ll> sMu, sPhi;
ll mu[N+10], phi[N+10];
ll sumMu[N+10], sumPhi[N+10];
bool flag[N+10];
ll prime[N+10], cnt;
void init() {
	phi[1] = 1;
	mu[1] = 1;
	for(ll i = 2; i <= N; i++) {
		if(!flag[i]) {
			phi[i] = i-1;
			mu[i] = -1;
			prime[++cnt] = i;
		}
		for(ll j = 1; j <= cnt && i * prime[j] <= N; j++) {
			flag[i * prime[j]] = 1;
			if(i % prime[j] == 0) {
				phi[i * prime[j]] = phi[i] * prime[j];
				mu[i * prime[j]] = 0;
				break;
			}
			phi[i * prime[j]] = phi[i] * phi[prime[j]];
			mu[i * prime[j]] = mu[i] * mu[prime[j]];
		}
	}
	for(ll i = 1; i <= N; i++) {
		sumMu[i] = sumMu[i-1] + mu[i];
		sumPhi[i] = sumPhi[i-1] + phi[i];
	}
}
// μ*I=ϵ
ll qMu(ll n) {
	if(n <= N) return sumMu[n];
	if(sMu[n]) return sMu[n];
	ll res = 1;	// ϵ的前缀和
	for(ll l = 2, r = 0; l <= n; l = r + 1) {
		r = n / (n / l);
		res -= (r - l + 1) * qMu(n / l);
	}
	
	return sMu[n] = res;
}
// φ*I=id
ll qPhi(ll n) {
	if(n <= N) return sumPhi[n];
	if(sPhi[n]) return sPhi[n];
	ll res = n * (n + 1) / 2;	// id的前缀和
	for(ll l = 2, r = 0; l <= n; l = r + 1) {
		r = n / (n / l);
		res -= (r - l + 1) * qPhi(n / l);
	}
	return sPhi[n] = res;
}
int main() {
	init();
	ll T, n;
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld", &n);
		printf("%lld %lld\n", qPhi(n), qMu(n));
	}
}
