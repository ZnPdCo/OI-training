#include<bits/stdc++.h>
#define ll long long
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
void solve();
int main() {
	while(Case--) solve();
}
void solve() {
	input(n);
	if(n > 0) print((n+9)/10);
	else print(n/10);
}
