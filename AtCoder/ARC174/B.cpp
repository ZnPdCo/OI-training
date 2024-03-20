#include<bits/stdc++.h>
#define ll long long
#define N 1010
#define P 998244353
using namespace std;
void print() {cout << endl;}
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
ll n, m, Case=1, sum;
ll a[N], p[N];
void solve();
int main() {
	input(Case);
	while(Case--) solve();
}
void solve() {
	for(ll i = 1; i <= 5; i++) {
		input(a[i]);
	}
	sum = -2 * a[1] + -1 * a[2] + 1 * a[4] + 2 * a[5];
	for(ll i = 1; i <= 5; i++) {
		input(p[i]);
	}
	if(sum >= 0) {
		print(0);
		return;
	} 
	sum *= -1;
	if(2 * p[4] <= p[5]) {
		print(sum * p[4]);
	} else {
		if(sum % 2 == 0) {
			print(sum / 2 * p[5]);
		} else {
			print((sum - 1) / 2 * p[5] + min(p[4], p[5]));
		}
	}
}
