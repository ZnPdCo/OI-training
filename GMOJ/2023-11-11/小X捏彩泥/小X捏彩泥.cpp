/**
 * @file 小X捏彩泥.cpp 
 * @tag: #GMOJ#dp
 * @author: ZnPdCo
 * @date: 2023-12-23 18:58:28
 * @problem: https://gmoj.net/senior/#main/show/4659
 **/
#include <cstdio>
#include <algorithm>
#define ll long long
#define N 10010
using namespace std;
ll n, ans;
ll v[N], a[N];
ll cntl[N], cntr[N], cnt, xl, xr;
ll f[N];
int main() {
	scanf("%lld", &n);
	for(ll i = 1; i <= n; i++) {
		scanf("%lld", &v[i]);
	}
	for(ll i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	ll l = 1, r = n;
	while(l <= r) {
		if(xl > xr) {
			xr += v[r];
			r--;
		} else {
			xl += v[l];
			l++;
		}
		if(xl == xr) {
			cntl[++cnt] = l - 1;
			cntr[cnt] = r + 1;
		}
	}
	cntr[0] = n+1;
	ll ans = 1e15;
	for(ll i = 1; i <= cnt; i++) {
		f[i] = 1e15;
		for(ll j = 0; j < i; j++) {
			f[i] = min(f[i], a[cntl[i] - cntl[j]] + f[j] + a[cntr[j] - cntr[i]]);
		}
		ans = min(ans, f[i] + a[(cntr[i]-1) - (cntl[i]+1) + 1]);
	}
	printf("%lld", min(ans, a[n]));
}
