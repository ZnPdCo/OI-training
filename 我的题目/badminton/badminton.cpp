#include <cstdio>
#define ll long long
#define N 3000010
#define mod 998244353

int t, k;
ll p[7], q[7], a, b;
ll u[5], v[5];
ll inv[N];
ll fac[N], ifac[N];

void init() {
	inv[0] = inv[1] = fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
	
	for(int i = 2; i <= t; i++) {
		inv[i] = (mod-mod/i) * inv[mod%i] % mod,
		fac[i] = fac[i-1] * i % mod,
		ifac[i] = ifac[i-1] * inv[i] % mod;
	}
}
ll qpow(ll x, ll y) {
	if(y == 0) return 1;
	if(y % 2 == 1) return x * qpow(x, y - 1) % mod;
	ll tmp = qpow(x, y / 2);
	return tmp * tmp % mod;
}

ll calc() {
	ll P = 0, Q = 0;
	for(int i = 1; i <= 2; i++) {
		for(int j = 1; j <= 2; j++) {
			int o = (i-1) * 2 + j;
			ll x = p[o] * q[o] % mod;
			if(u[i] <= v[j]) {
				Q = ((qpow(x, u[i]+1) - x) % mod + mod) % mod;
				(Q *= qpow(x - 1,mod-2)) %= mod;
				(Q *= (mod+1-q[o]) * qpow(q[o],mod-2) % mod) %= mod;
			} else {
				Q = ((qpow(x, v[i]+1) - x) % mod + mod) % mod;
				(Q *= qpow(x - 1,mod-2)) %= mod;
				(Q *= (mod+1-q[o]) * qpow(q[o],mod-2) % mod) %= mod;
				(Q += qpow(x, v[j])) %= mod;
			}
			if(i == 1) (Q *= a) %= mod;
			else (Q *= (mod+1-a)) %= mod;
			if(j == 1) (Q *= b) %= mod;
			else (Q *= (mod+1-b)) %= mod;
			(P += Q) %= mod;
		}
	}
	return P;
}
ll ans;
inline ll C(int n, int m) {return fac[n] * ifac[m] % mod * ifac[n-m] % mod;}
int main(){
	scanf("%d %d", &t, &k);
	for(int i = 1; i <= 4; i++){
		scanf("%lld %lld", &p[i], &q[i]);
	}
	for(int i = 1; i <= 2; i++) {
		scanf("%lld", &u[i]);
	}
	for(int i = 1; i <= 2; i++) {
		scanf("%lld", &v[i]);
	}
	scanf("%lld %lld", &a, &b);
	
	init();
	ll P = calc();
	ans = C(t, k) * qpow(P, k) % mod * qpow((mod+1-P) % mod, t-k) % mod;
	printf("%lld",ans);
	return 0;
}
