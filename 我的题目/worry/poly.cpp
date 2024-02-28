#include <cstdio>
#define ll long long
#define N 2000000
#define P 998244353
ll n, m, k, g, ans;
ll phi[N+10];
ll tau[N+10];
bool flag[N+10];
ll prime[N+10], cnt;
ll num[N+10];
void init() {
	phi[1] = 1;
	tau[1] = 1;
	for(ll i = 2; i <= N; i++) {
		if(!flag[i]) {
			phi[i] = i-1;
			tau[i] = 2;
			num[i] = 1;
			prime[++cnt] = i;
		}
		for(ll j = 1; j <= cnt && i * prime[j] <= N; j++) {
			flag[i * prime[j]] = 1;
			if(i % prime[j] == 0) {
				num[i * prime[j]] = num[i] + 1;
				tau[i * prime[j]] = tau[i] / num[i * prime[j]] * (num[i * prime[j]] + 1);
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
			num[i * prime[j]] = 1;
			tau[i * prime[j]] = tau[i] * 2;
			phi[i * prime[j]] = phi[i] * phi[prime[j]];
		}
	}
}
int main() {
	init();
	scanf("%lld%lld%lld%lld", &n, &m, &k, &g);
	for(ll i = 0; i < n; i++) {
		for(ll j = 0; j < m; j++) {
			(((ans += phi[i ^ j ^ k] - tau[(i ^ j) & ((1ll<<g)-1)]) %= P) += P) %= P;
//			printf("| $(%lld,%lld)$ ", i, j);
//			printf("| $%lld\\operatorname{xor}%lld\\operatorname{xor}%lld=%lld$，$\\varphi(%lld)=%lld$ ", i, j, k, i^j^k,i^j^k,phi[i ^ j ^ k]);
//			printf("| $(%lld\\operatorname{xor}%lld)\\operatorname{and}(2^{%lld}-1)=%lld$，$\\tau(%lld)=%lld$ |\n", i,j,g,(i ^ j) & ((1<<g)-1),(i ^ j) & ((1<<g)-1),tau[(i ^ j) & ((1<<g)-1)]);
		}
	}
	printf("%lld", ans);
}
