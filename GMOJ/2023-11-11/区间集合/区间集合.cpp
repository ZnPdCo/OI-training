/**
 * @file 区间集合.cpp 
 * @tag: #GMOJ#并查集
 * @author: ZnPdCo
 * @date: 2023-12-23 19:01:01
 * @problem: https://gmoj.net/senior/#main/show/4661
 **/
#include <cstdio>
#define ll long long
#define N 1000010
ll a, b, p;
ll flag[N];
ll prime[N], cnt;
ll fa[N];
ll v[N];
void init() {
	for(ll i = 2; i <= 1000000; i++) {
		if(flag[i] == 0) {
			prime[++cnt] = i;
		}
		for(ll j = 1; j <= cnt && prime[j] * i <= 1000000; j++) {
			flag[prime[j] * i] = 1;
			if(prime[j] % i == 0) break;
		}
	}
}
ll find(ll x) {
	if(x ==fa[x]) return x;
	return fa[x] = find(fa[x]);
}
int main() {
	scanf("%lld %lld %lld", &a, &b, &p);
	init();
	for(ll i = a; i <= b; i++) fa[i - a] = i - a;
	for(ll i = 1; i <= cnt; i++) if(prime[i] >= p){
		ll st = 0;
		for(ll j = a / prime[i] * prime[i]; j <= b; j += prime[i]) {
			if(j < a) continue;
			if(!st) {
				st = j;
				continue;
			}
			fa[find(j - a)] = find(st - a);
		}
	}
	ll ans = 0;
	for(ll i = a; i <= b; i++) {
		if(!v[find(i-a)]) {
			v[fa[i-a]] = 1;
			ans++;
		}
//		printf("%lld ", fa[i-a] + a);
	}
	printf("%lld", ans);
}
