/**
 * @file 小X调顺序.cpp 
 * @tag: #GMOJ#逆序对
 * @author: ZnPdCo
 * @date: 2023-12-23 18:57:22
 * @problem: https://gmoj.net/senior/#main/show/4658
 **/
#include <cstdio>
#include <algorithm>
#define ll long long
#define N 100010
using namespace std;
ll n, k;
ll a[N], b[N], ans;
void solve(ll l, ll r) {
	if(l == r) return;
	
	ll mid = (l + r) >> 1;
	solve(l, mid);
	solve(mid + 1, r);
	
	ll pos1 = l, pos2 = mid+1;
	for(ll i = l; i <= r; i++) {
		if(pos1 > mid) {
			b[i] = a[pos2++];
		} else if(pos2 > r) {
			b[i] = a[pos1++];
		} else if(a[pos1] > a[pos2]) {
			b[i] = a[pos1++];
			ans += r - pos2 + 1;
		} else {
			b[i] = a[pos2++];
		}
	}
	
	for(ll i = l; i <= r; i++) {
		a[i] = b[i];
	}
}
int main() {
	scanf("%lld %lld", &n, &k);
	for(ll i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	solve(1, n);
	printf("%lld", max(ans - k, 0ll));
}
