#include<bits/stdc++.h>
#define ll long long
#define N 1010
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
ll a, b, d;
void solve();
int main() {
	while(Case--) solve();
}
void solve() {
	input(a, b, d);
	for(ll i = a; i <= b; i+=d) {
		print(i);
	}
}
