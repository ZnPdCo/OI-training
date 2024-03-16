#include<bits/stdc++.h>
#define ll long long
#define N 1000010
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
ll n, m, Case=1;
char s[N];
void solve();
int main() {
	while(Case--) solve();
}
ll cnt['z'+1];
void solve() {
	ll ans = 0;
	scanf("%s", s+1);
	n = strlen(s+1);
	for(ll i = 1; i <= n; i++) {
		cnt[s[i]]++;
		if(cnt[s[i]] > 1) ans = 2;
	}
	for(ll i = 'a'; i <= 'z'; i++) {
		ans += cnt[i] * (n - cnt[i]);
	}
	print(ans / 2);
}
