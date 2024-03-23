/**
 * @file P4590 [TJOI2018] 游园会.cpp 
 * @tag: #洛谷#dp套dp
 * @author: ZnPdCo
 * @date: 2023-12-23 13:55:50
 * @problem: https://www.luogu.com.cn/problem/P4590
 **/

#include <bits/stdc++.h>
#define ll long long
#define N 1010
#define K 20
#define P 1000000007
using namespace std;
ll n, k;
char s[K];
ll a[K];
ll f[2][40000][3]; // f[i][s][j]表示匹配到第i位，内部LCS自动机状态为s，字符串的最后字符串分别为otherwise}、N、NO。 
ll nxt[3][3]; // 上几位是 otherwise、N、NO，这一位是 N、O、I，那么这一位的结尾是 otherwise、N、NO 的哪一个？ 
ll ans[K];



ll cache1[K]; // 临时传入值 
inline ll zip() {
	ll res = 0;
	for(ll i = 1; i <= k; i++) {
		res |= (cache1[i]-cache1[i-1]) << (i-1);
	}
	return res;
}

ll cache2[K]; // 临时传出值 
inline void unzip(ll a) {
	cache2[0] = 0;
	for(ll i = 1; i <= k; i++) {
		cache2[i] = cache2[i-1] + ((a >> (i-1)) & 1);
	}
} 



int main() {
	// 处理情况 
	nxt[0][0] = 1;
	nxt[0][1] = 0;
	nxt[0][2] = 0;
	nxt[1][0] = 1;
	nxt[1][1] = 2; // 上几位是 N，这一位是 N，那么这一位的结尾是 N。上、下同。
	nxt[1][2] = 0;
	nxt[2][0] = 1;
	nxt[2][1] = 0;
	nxt[2][2] = 3;
	
	
	scanf("%lld %lld", &n, &k);
	scanf("%s", s+1);
	for(ll i = 1; i <= k; i++) {
		if(s[i] == 'N') a[i] = 0;
		if(s[i] == 'O') a[i] = 1;
		if(s[i] == 'I') a[i] = 2;
	}
	f[0][0][0] = 1;
	for(ll i = 1; i <= n; i++) {
		memset(f[i%2], 0, sizeof(f[i%2]));
		for(ll s = 0; s < (1<<k); s++) { // $i-1$ 的 LCS 自动机状态 
			unzip(s);
			for(ll j = 0; j <= 2; j++) { // $i-1$ 的结尾是 otherwise、N、NO。 
				if(!f[(i-1)%2][s][j]) continue; // 卡常 
				for(ll c = 0; c <= 2; c++) { // 枚举第 $i$ 位字母 N、O、I。 
					if(j == 2 && c == 2) continue;		// NO 结尾不能加上 I
					// 刚好因为 cache 的分类，定义 cache1 是 i 的值，cache2 是 i-1 的值。 
					// cache1[x] 相当于 dp[i][x] 
					// cache2[x] 相当于 dp[i-1][x]
					// cache1[x-1]` 相当于 dp[i][x-1]
					// cache2[x-1]` 相当于 dp[i-1][x-1]
					for(ll x = 1; x <= k; x++) {
						cache1[x] = max(max(cache2[x], cache1[x-1]), cache2[x-1] + (c == a[x]));
					}
					(f[i%2][zip()][nxt[j][c]] += f[(i-1)%2][s][j]) %= P;
				}
			}
		}
	}
	
	for(ll s = 0; s < (1<<k); s++) {
		for(ll j = 0; j <= 2; j++) {
			(ans[__builtin_popcount(s)] += f[n%2][s][j]) %= P;
		}
	}
	for(ll i = 0; i <= k; i++) {
		printf("%lld\n", ans[i]);
	}
}
