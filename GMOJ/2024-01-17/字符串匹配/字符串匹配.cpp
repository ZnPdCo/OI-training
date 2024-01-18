/**
 * @file 字符串匹配.cpp 
 * @tag: #GMOJ#exkmp#字符串#树状数组
 * @author: ZnPdCo
 * @date: 2024-01-18 20:43:55
 * @problem: https://gmoj.net/senior/#main/show/6923
 **/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
#define N ((1<<20)+10)
ll t, n;
char s[N];
ll z[N];

ll bef[30], aft[30];
ll suf, pre, all;

ll ans;

void Z() {
	z[1] = n;
	while(z[2] + 2 <= n && s[z[2]+1] == s[z[2]+2]) z[2]++;
	
	ll p0 = 2, p1 = 2 + z[2] - 1;
	for(ll k = 3; k <= n; k++) {
		if(k + z[k-p0+1] - 1 < p1) z[k] = z[k-p0+1];
		else {
			z[k] = max(0ll, p1-k);
			while(z[k] + k <= n && s[z[k]+1] == s[z[k]+k]) z[k]++;
			p0 = k;
			p1 = k + z[k] - 1;
		}
	}
}


ll a[N];
inline ll lowbit(ll x) {
	return x & (-x);
}
inline void update(ll x, ll y) {
	while(x <= 30) {
		a[x] += y;
		x += lowbit(x);
	}
}
inline ll query(ll x) {
	ll res = 0;
	while(x) {
		res += a[x];
		x -= lowbit(x);
	}
	return res;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%lld", &t);
	while(t--) {
		memset(z, 0, sizeof z);
		memset(a, 0, sizeof a);
		memset(s, 0, sizeof s);
		memset(bef, 0, sizeof bef);
		memset(aft, 0, sizeof aft);
		all = suf = pre = ans = 0;
		
		scanf("%s", s+1);
		n = strlen(s+1);
		Z();
		
		for(ll i = 1; i <= n; i++) {
			if(i + z[i] - 1 == n) z[i]--;	// 留出c的位置
		}
		
		for(ll i = 1; i <= n; i++) {
			if(aft[s[i]-'a'] % 2 == 1) all--;
			else all++;
			aft[s[i]-'a']++; 
		}
		
		suf = all;
		
		for(ll i = 1; i <= n; i++) {
			if(aft[s[i]-'a'] % 2 == 1) suf--;
			else suf++;
			aft[s[i]-'a']--;
			
			if(bef[s[i]-'a'] % 2 == 1) pre--;
			else pre++;
			bef[s[i]-'a']++;
			
			if(i != 1 && i != n) {
				ll t = z[i+1] / i + 1;
				ll tj = t - t / 2;
				ll to = t / 2;
				ll t1 = query(suf + 1);
				ll t2 = query(all + 1);
				ans += tj * t1 + to * t2;
			}
			update(pre+1, 1);
		}
		
		printf("%lld\n", ans);
	}
}
