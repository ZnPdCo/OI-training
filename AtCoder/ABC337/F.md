我们破环成链，发现成为了一个区间问题，容易发现当左端点往右移动，合法的右端点一定是递增的。

所以我们可以做到 $O(n)$，分成多个 $k$ 为一组，右端点不断递增，当总盒子个数超过 $m$ 时，退出递增并输出答案，下次接着递增。

如何判断盒子个数？可以模 $k$，如果原本这个球在区间里的个数模 $k$ 等于 $0$，那么说明这是一个新盒子，盒子个数加一。如果删除后球在区间里的个数模 $k$ 等于 $0$，那么说明这个盒子空了，盒子个数减一。

```c++
/**
 * @file A.cpp 
 * @tag: #AtCoder#ABC#ABC336
 * @author: ZnPdCo
 * @date: 2023-12-23 13:55:50
 * @problem: https://atcoder.jp/contests/abc337/tasks/abc337_f
 **/
#include<bits/stdc++.h>
#include<vector>
#define ll long long
#define N 400010
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
ll n, m, k;
ll a[N];
ll type, ans;
ll cnt[N];
vector<ll> num[N];
ll top[N];
int main() {
	input(n, m, k);
	for(ll i = 1; i <= n; i++) {
		num[i].push_back(k);
	}
	for(ll i = 1; i <= n; i++) {
		input(a[i]);
		a[i+n] = a[i];
		if(num[a[i]].back() == k) num[a[i]].push_back(1);
		else {
			ll x = num[a[i]].back();
			num[a[i]].pop_back();
			num[a[i]].push_back(x+1);
		}
	}
	ll r = 1;
	for(ll l = 1; l <= n; l++) {
		while(r < 2*n) {
			if(cnt[a[r]] % k == 0) {
				type++;
				ans += num[a[r]][++top[a[r]]];
			}
			cnt[a[r]]++;
			if(type > m) break;
			r++;
		}
		if(r < 2*n) {
			cnt[a[r]]--;
			if(cnt[a[r]] % k == 0) {
				type--;
				ans -= num[a[r]][top[a[r]]--];
			}
		}
		
		
		
		print(ans);
		putchar('\n');
		
		
		cnt[a[l]]--;
		if(cnt[a[l]] % k == 0) {
			type--;
			ans -= num[a[l]][top[a[l]]--];
		}
	}
}
```

