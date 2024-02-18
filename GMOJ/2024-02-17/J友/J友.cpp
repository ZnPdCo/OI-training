#include <cstdio>
#define ll long long
#define N 1000010
ll n, p, x, y, m, ans;
// 0 右，1 下，2 左，3 上
ll cnt[4], sum[4];
ll fac[N], ifac[N];
inline ll abs(ll a) {return a > 0 ? a : -a;}
ll qpow(ll a, ll b) {
	if(b == 0) return 1;
	if(b % 2 == 1) return a * qpow(a, b-1) % p;
	ll tmp = qpow(a, b / 2);
	return tmp * tmp % p;
}
int main() {
	scanf("%lld %lld %lld %lld", &n, &p, &x, &y);
	if(p == 1) return printf("0"), 0;
	
	
	if(x >= 0) cnt[1] += x;
	else cnt[3] -= x;
	if(y >= 0) cnt[0] += y;
	else cnt[2] -= y;
	
	m = n - abs(x) - abs(y);
	if(m < 0) return printf("0"), 0;	// 到不了
	if(m & 1) return printf("0"), 0;	// 不是偶数，无法匹配
	
	fac[0] = 1;
	for(int i = 1; i <= n; i++) {
		(fac[i] = fac[i-1] * (i % p)) %= p;
	}
	ifac[n] = qpow(fac[n], p-2);
	for(int i = n-1; i >= 0; i--) {
		(ifac[i] = ifac[i+1] * ((i+1) % p)) %= p;
	}
	
	for(int i = 0; i <= m / 2; i++) {	// 有 i 组 0/2
		sum[0] = cnt[0] + i;
		sum[1] = cnt[1] + m/2-i;
		sum[2] = cnt[2] + i;
		sum[3] = cnt[3] + m/2-i;
		
		(ans += fac[n] * ifac[sum[0]] % p * ifac[sum[1]] % p * ifac[sum[2]] % p * ifac[sum[3]] % p) %= p;
//		printf("n!/%lld!/%lld!/%lld!/%lld!\n", sum[0], sum[1], sum[2], sum[3]);
	}
	
	printf("%lld", ans);
}
