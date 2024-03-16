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
int solve();
int main() {
	while(Case--) solve();
}
int solve() {
	scanf("%s", s+1);
	for(ll i = 2; i < strlen(s+1); i++) {
		
		if(s[i] != '=') return printf("No"), 0;
	}
	if(s[1] != '<') return printf("No"), 0;
	if(s[strlen(s+1)] != '>') return printf("No"), 0;
	printf("Yes");
	return 0;
}
