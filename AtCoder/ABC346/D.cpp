#include<bits/stdc++.h>
#define ll long long
#define N 200010
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
ll a[N];
ll ans = 1e15;
ll sum1[N], sum2[N];
ll back1[N], back2[N];
char s[N];
void solve();
int main() {
	while(Case--) solve();
}
void solve() {
	input(n);
	scanf("%s", s+1);
	for(ll i = 1; i <= n; i++) {
		input(a[i]);
	}
	for(ll i = 1; i <= n; i++) {
		sum1[i] = sum1[i-1];
		sum2[i] = sum2[i-1];
		if(s[i] - '0' != i % 2) sum1[i]+=a[i]; 
		if(s[i] - '0' == i % 2) sum2[i]+=a[i]; 
	}
	for(ll i = n; i >= 1; i--) {
		back1[i] = back1[i+1];
		back2[i] = back2[i+1];
		if(s[i] - '0' != i % 2) back1[i]+=a[i]; 
		if(s[i] - '0' == i % 2) back2[i]+=a[i]; 
	}
	for(ll i = 1; i < n; i++) {
		// 把i和i+1变成0
		if(i % 2 == 0) ans = min(ans, (s[i] == '1' ? a[i] : 0) + (s[i+1] == '1' ? a[i+1] : 0) + sum1[i-1] + back2[i+2]);
		else ans = min(ans, (s[i] == '1' ? a[i] : 0) + (s[i+1] == '1' ? a[i+1] : 0) + sum2[i-1] + back1[i+2]);
		
		// 把i和i+1变成1
		if(i % 2 == 0) ans = min(ans, (s[i] == '0' ? a[i] : 0) + (s[i+1] == '0' ? a[i+1] : 0) + sum2[i-1] + back1[i+2]);
		else ans = min(ans, (s[i] == '0' ? a[i] : 0) + (s[i+1] == '0' ? a[i+1] : 0) + sum1[i-1] + back2[i+2]);
	}
	print(ans);
}
