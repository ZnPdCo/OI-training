/**
 * @file 动物园.cpp 
 * @tag: #GMOJ#模拟
 * @author: ZnPdCo
 * @date: 2024-01-16 19:53:25
 * @problem: https://gmoj.net/senior/#main/show/6856
 **/
#include <cstdio>
#define ll long long
ll n, m, c, k;
unsigned __int128 sum, buy;
unsigned __int128 ans = 1;
void print(unsigned __int128 x) {
	if(x >= 10) print(x / 10);
	putchar(x % 10 + '0');
}
int main() {
	freopen("zoo.in", "r", stdin);
	freopen("zoo.out", "w", stdout);
	scanf("%lld %lld %lld %lld", &n, &m, &c, &k);
	for(ll i = 1; i <= n; i++) {
		ll a;
		scanf("%lld", &a);
		sum |= a;
	}
	for(ll i = 1; i <= m; i++) {
		ll p, q;
		scanf("%lld %lld", &p, &q);
		buy |= (1ull<<p);
	}
	for(ll i = 0; i < k; i++) {
		if((sum & (1ull<<i)) && (buy & (1ull<<i))) {		// 如果有这个动物且有购买需求，则0、1均可填
			ans *= 2ull;
		}
		if(!(buy & (1ull<<i))) {							// 如果无购买需求，则0、1均可填
			ans *= 2ull;
		}
	}
	ans -= n;
	print(ans);
}
