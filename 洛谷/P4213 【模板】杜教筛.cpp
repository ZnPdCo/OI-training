#include <cstdio>
#include <unordered_map>
#define ll long long
#define N 4000000
using namespace std;
unordered_map<ll, ll> sMu, sPhi;
ll mu[N+10], phi[N+10];
bool flag[N+10];
void init() {
	for(ll i = 1; i <= N; i++) {
		if(!flag[i]) {
			
		}
	}
}
// μ*I=ϵ
ll qMu(ll n) {
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
