/*
* File: P4590 [TJOI2018] ��԰��.cpp
* Author: ZnPdCo
* Date: 2023-12-22
* Problem: https://www.luogu.com.cn/problem/P4590
* Score: 100
*/

#include <bits/stdc++.h>
#define ll long long
#define N 1010
#define K 20
#define P 1000000007
using namespace std;
ll n, k;
char s[K];
ll a[K];
ll f[2][40000][3]; // $f_{i,s,j}$ ��ʾƥ�䵽�� $i$ λ���ڲ� LCS �Զ���״̬Ϊ $s$���ַ���������ַ����ֱ�Ϊ $\text{otherwise}$��$\texttt{N}$��$\texttt{NO}$�� 
ll nxt[3][3]; // �ϼ�λ�� $\text{otherwise}$��$\texttt{N}$��$\texttt{NO}$����һλ�� $\texttt{N}$��$\texttt{O}$��$\texttt{I}$����ô��һλ�Ľ�β�� $\text{otherwise}$��$\texttt{N}$��$\texttt{NO}$ ����һ���� 
ll ans[K];



ll cache1[K]; // ��ʱ����ֵ 
inline ll zip() {
	ll res = 0;
	for(ll i = 1; i <= k; i++) {
		res |= (cache1[i]-cache1[i-1]) << (i-1);
	}
	return res;
}

ll cache2[K]; // ��ʱ����ֵ 
inline void unzip(ll a) {
	cache2[0] = 0;
	for(ll i = 1; i <= k; i++) {
		cache2[i] = cache2[i-1] + ((a >> (i-1)) & 1);
	}
} 



int main() {
	// ������� 
	nxt[0][0] = 1;
	nxt[0][1] = 0;
	nxt[0][2] = 0;
	nxt[1][0] = 1;
	nxt[1][1] = 2; // �ϼ�λ�� $\texttt{N}$����һλ�� $\texttt{N}$����ô��һλ�Ľ�β�� $\texttt{N}$���ϡ���ͬ��
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
		for(ll s = 0; s < (1<<k); s++) { // $i-1$ �� LCS �Զ���״̬ 
			unzip(s);
			for(ll j = 0; j <= 2; j++) { // $i-1$ �Ľ�β�� $\text{otherwise}$��$\texttt{N}$��$\texttt{NO}$�� 
				if(!f[(i-1)%2][s][j]) continue; // ���� 
				for(ll c = 0; c <= 2; c++) { // ö�ٵ� $i$ λ��ĸ $\texttt{N}$��$\texttt{O}$��$\texttt{I}$�� 
					if(j == 2 && c == 2) continue;		// $\texttt{NO}$ ��β���ܼ��� $\texttt{I}$
					// �պ���Ϊ `cache` �ķ��࣬���� `cache1` �� $i$ ��ֵ��`cache2` �� $i-1$ ��ֵ�� 
					// `cache1[x]` �൱�� `dp[i][x]` 
					// `cache2[x]` �൱�� `dp[i-1][x]`
					// `cache1[x-1]` �൱�� `dp[i][x-1]`
					// `cache2[x-1]` �൱�� `dp[i-1][x-1]`
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
