/**
 * @file 最小最大和.cpp 
 * @tag: #GMOJ#贪心
 * @author: ZnPdCo
 * @date: 2023-12-31 14:27:51
 * @problem: https://gmoj.net/senior/#main/show/1443
 **/
#include <cstdio>
#define ll long long
#define N 100000
ll n;
ll x, y;
ll a[110], b[110];
inline ll max(ll k, ll u) {
	return k > u ? k : u;
}
int main() {
	scanf("%lld", &n);
	for(ll i = 1; i <= n; i++) {
		scanf("%lld %lld", &x, &y);
		a[x]++, b[100-y+1]++;
		ll mx = 0;
		ll as=0, bs=0;
		ll ap=1, bp=1;
		while(ap <= 100 || bp <= 100) {
			if(a[ap] && b[bp]) mx = max(mx, ap+100-bp+1);
			if(as+a[ap] < bs+b[bp]) {
				as += a[ap++];
			} else if(as+a[ap] > bs+b[bp]) {
				bs += b[bp++];
			} else {
				as += a[ap++];
				bs += b[bp++];
			}
		}
		printf("%lld\n", mx);
	}
}
