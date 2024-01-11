#include <cstdio>
#define ll long long
ll T;
ll m,a,b,c,d, ans;
ll l, r;
void dfs(ll x, ll sum=0) {
	if(x > m) {
		if(sum % m == 0) ans++;
		return;
	}
	dfs(x+1, sum+x);
	dfs(x+1, sum);
}
ll gcd(ll x, ll y) {
	if(y == 0) return x;
	return gcd(y, x%y);
}
int main() {
	freopen("calculate.in", "r", stdin);
	freopen("calculate.out", "w", stdout);
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld %lld%lld%lld", &m, &a, &b, &c, &d);
		ans = 0;
		dfs(1);
		printf("%lld\n", ans);
	}
}
