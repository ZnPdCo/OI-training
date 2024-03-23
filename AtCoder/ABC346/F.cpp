#include<bits/stdc++.h>
#define ll long long
#define N 200010
#define P 998244353
using namespace std;
void print() {}
template<typename T, typename... Ts>
void print(const T& x, const Ts&... y) {
	cout << x << ' ';
	print(y...);
}
void input() {}
template<typename T, typename... Ts>
void input(T& x, Ts&... y) {
	cin >> x;
	input(y...);
}
ll n, m, k, Case=1;
ll sum[N][26];
char s[N], t[N];
void solve();
int main() {
	while(Case--) solve();
}
bool check(ll x) {
	ll a = 0, b = n;	// s走到第a轮的第b个字符
	for(ll i = 1; i <= m; i++) {
		// 往后走x个t[i]
		ll tot = sum[n][t[i]-'a'];
		if(tot == 0) return false;
		
		ll xx = x;
		if(x % tot == 0) {	// 如果刚好结束
			a += x / tot - 1;	// 需要少一轮
			xx = tot;
		} else {
			a += x / tot;
			xx = x % tot;
		}
		
		// 再往后走
		ll l = b, r = b+n, ans;
		while(l <= r) {
			ll mid = (l + r) >> 1;
			if(sum[mid][t[i]-'a'] - sum[b][t[i]-'a'] >= xx) {
				ans = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		b = ans;
		a += b/n;
		b %= n;
	}
	if(b == 0) a--, b = n;
	return a <= k;
}
void solve() {
	input(k);
	scanf("%s %s", s+1, t+1);
	n = strlen(s+1), m = strlen(t+1);
	for(ll i = 1; i <= n; i++) s[i+n] = s[i];
	for(ll i = 1; i <= 2*n; i++) {
		for(ll j = 0; j < 26; j++) sum[i][j] = sum[i-1][j];
		sum[i][s[i]-'a']++;
	}
	ll l = 0, r = (n * k + m - 1) / m, ans = 0;
	while(l <= r) {
		ll mid = (l + r) >> 1;
		if(check(mid)) {
			l = mid + 1;
			ans = mid;
		} else {
			r = mid - 1;
		}
	}
	print(ans);
}
