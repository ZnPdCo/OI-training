/**
 * @file P4131 [WC2005] 友好的生物.cpp
 * @tag: #洛谷#状态压缩
 * @author: ZnPdCo
 * @date: 2023-12-23 18:54:42
 * @problem: https://www.luogu.com.cn/problem/P4131
 **/
#include <cstdio>
#include <algorithm>
#define N 100010
#define K 10
#define ll long long
using namespace std;
ll n, k, ans = -1e15, pos1, pos2;
ll c[N];
struct node {
	ll a[K], pos;
} d[N];
// 前i个状态 +dk 
struct node2 {
	ll val, pos;
} f[N][1<<5];
bool cmp(node x, node y) {
	return x.a[k] < y.a[k];
}
ll fun(ll x) {
	ll res = 0;
	for(ll i = 0; i < k-1; i++) {
		if((x & (1<<(i))) == 0) res |= (1<<i);
	}
	return res;
}
int main() {
	scanf("%lld %lld", &n, &k);
	for(ll i = 1; i <= k; i++) {
		scanf("%lld", &c[i]);
	}
	for(ll i = 1; i <= n; i++) {
		d[i].pos = i;
		for(ll j = 1; j <= k; j++) {
			scanf("%lld", &d[i].a[j]);
			d[i].a[j] *= c[j];
		}
	}
	for(ll s = 0; s < (1 << (k-1)); s++) {
		f[0][s].val = -1e15;
	}
	
	sort(d+1, d+1+n, cmp);
	
	
	for(ll i = 1; i <= n; i++) {
		for(ll s = 0; s < (1 << (k-1)); s++) {
			f[i][s] = f[i-1][s];
			ll sum = 0;
			for(ll j = 1; j < k; j++) {
				if(s & (1<<(j-1))) sum += d[i].a[j];
				else sum -= d[i].a[j];
			}
			if(sum + d[i].a[k] > f[i][s].val) {
				f[i][s].val = sum + d[i].a[k];
				f[i][s].pos = d[i].pos;
			}
			if(i != 1 && sum - d[i].a[k] + f[i-1][fun(s)].val > ans) {
				ans = sum - d[i].a[k] + f[i-1][fun(s)].val;
				pos1 = f[i-1][fun(s)].pos;
				pos2 = d[i].pos;
			}
		}
	}
	printf("%lld %lld\n%lld", pos1, pos2, ans);
} 
