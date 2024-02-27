#include <cstdio>
#include <algorithm>
#include <cctype>
using namespace std;
#define ll long long
#define N 5000010
ll n, m, s, mx, mn, ans[N], ANS;
ll l[N], r[N], sl[N], sr[N], cl[N], cr[N];
int main() {
//	freopen("pubaba.in", "r", stdin);
//	freopen("pubaba.out", "w", stdout);
	scanf("%lld %lld %lld", &n, &m, &s);
	
	for(ll i = 1; i <= m; i++) {
		scanf("%lld %lld", &l[i], &r[i]);
		mn += l[i], mx += r[i];
		sl[l[i]] += l[i];
		sr[r[i]] += r[i];
		cl[l[i]] ++;
		cr[r[i]] ++;
	}
	if(mn > s || mx < s) return printf("-1"), 0;
	for(ll i = 1; i <= n; i++) {
		sl[i] += sl[i-1];
		sr[i] += sr[i-1];
	}
	for(ll i = n; i >= 1; i--) {
		cl[i] += cl[i+1];
		cr[i] += cr[i+1];
	}
	ll pos = n;
	for(ll i = 1; i <= m; i++) {
		while(min(s - mn + sl[pos - 1] + pos * cl[pos], sr[pos - 1] + pos * cr[pos]) < pos * i)
			pos--;
		ans[n - pos + 1] = i;
	}
	for(ll i = 1; i <= n; i++) { 
		ans[i] = max(ans[i-1], ans[i]);
		ANS ^= ans[i] * i;
	}
	printf("%lld", ANS);
}
