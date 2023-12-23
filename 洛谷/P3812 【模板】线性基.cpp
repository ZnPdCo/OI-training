/**
 * @file P3812 【模板】线性基.cpp
 * @tag: #洛谷#线性基
 * @author: ZnPdCo
 * @date: 2023-12-23 18:53:14
 * @problem: https://www.luogu.com.cn/problem/P3812
 **/
#include<cstdio>
#define ll long long
#define N 60
ll n;
ll p[N];
int main() {
	scanf("%lld", &n);
	for(ll i = 1; i <= n; i++) {
		ll x;
		scanf("%lld", &x);
		for(ll j = 51; j >= 0; j--) {
			if(x & (1LL<<j)) {
				if(!p[j]) {
					p[j] = x;
					break;
				}
				else x ^= p[j];
			}
		}
	}
	ll ans = 0;
	for(ll j = 51; j >= 0; j--) {
		if((ans ^ p[j]) > ans) ans ^= p[j];
	}
	printf("%lld", ans);
}
