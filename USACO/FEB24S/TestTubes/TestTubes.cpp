#include <cstdio>
#include <cstring>
#define ll long long
#define N 100010
ll t;
ll n, p;
char s1[N], s2[N], k1, k2, u[4];
ll ans[2*N][2], len;
void mov(ll x, ll y) {
	ans[++len][0] = x, ans[len][1] = y;
	u[x]--, u[y]++;
}
int main() {
	scanf("%lld", &t);
	while(t--) {
		k1 = k2 = 0;
		memset(u, 0, sizeof u);
		len = 0;
		scanf("%lld %lld %s %s", &n, &p, s2+1, s1+1);
		
		for(ll i = 1; i <= n; i++) {
			if(s1[i] != s1[i-1]) k1++;
			if(s2[i] != s2[i-1]) k2++;
		}
		printf("%lld\n", k1+k2-1);
	}
}
