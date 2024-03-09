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
bool flag = 1;
string s;
void solve();
int main() {
	while(Case--) solve();
}
void solve() {
	while(true) {
		char c = getchar();
		if(c == '|') {
			flag ^= 1;
		} else if('a' <= c && c <= 'z') {
			if(flag) printf("%c", c);
		} else break;
	}
}
