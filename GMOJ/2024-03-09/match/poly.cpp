#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
#define ll long long
#define N 110
#define M 32
#define K 8
#define P 1000000007
ll n, m, k, cnt, ans;
string a[N];
char s[M];
bool vis[26];
void dfs(string ss, ll x) {
	if(x > n) {
		for(ll i = 1; i <= k; i++) {
			if(ss.find(a[i]) == ss.npos) return;
		}
		ans++;
		return;
	}
	for(ll i = 1; i <= m; i++) {
		dfs(ss + s[i], x+1);
	}
}
int main() {
	scanf("%lld %lld", &n, &k);
	for(ll i = 1; i <= k; i++) {
		cin >> a[i];
	}
	scanf("%lld", &m);
	m = 0;
	scanf("%s", s+1);
	for(ll i = 1; s[i] != '\0'; i++) {
		if(!vis[s[i]-'a']) {
			vis[s[i]-'a'] = 1;
			s[++m] = s[i];
		}
	}
	dfs("", 1);
	printf("%lld", ans);
}
