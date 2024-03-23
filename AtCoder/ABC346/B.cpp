#include<bits/stdc++.h>
#define ll long long
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
string s = "", ss;
void solve();
int main() {
	while(Case--) solve();
}
void solve() {
	ss = "wbwbwwbwbwbw";
	for(ll i = 1; i <= 1000; i++) {
		s += ss;
	}
	input(n, m);
	for(ll i = 0; i < ss.length(); i++) {
		ll num1=0, num2=0;
		for(ll j = i; j <= i + n + m - 1; j++) {
			if(s[j] == 'w') num1++;
			else num2++;
		}
		if(n == num1 && m == num2) {
			printf("Yes");
			return;
		}
	}
	print("No");
}
