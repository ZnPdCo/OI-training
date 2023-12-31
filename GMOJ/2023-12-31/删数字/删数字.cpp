/**
 * @file 删数字.cpp 
 * @tag: #GMOJ#单调队列
 * @author: ZnPdCo
 * @date: 2023-12-31 14:34:45
 * @problem: https://gmoj.net/senior/#main/show/3154
 **/
#include <cstdio>
#define ll long long
#define N 1000010
ll a[N], b[N], n, k;
ll c[N];		// i与i-1的差值
ll ans=1e15;

// 我是sb，都排序了还求区间最大值
ll q[N], h=1, t;	// 维护区间最小差值



// woc这么卡常？？！
inline ll read() {
	ll x = 0;
	char c = '.';
	ll f = 1;
	while(c < '0' || c > '9') {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + (c ^ '0');
		c = getchar();
	}
	return x * f;
}

inline ll min(ll x, ll y) {
	return x < y ? x : y;
}

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
		} else if(a[pos1] < a[pos2]) {
			b[i] = a[pos1++];
		} else {
			b[i] = a[pos2++];
		}
	}
	
	for(ll i = l; i <= r; i++) {
		a[i] = b[i];
	}
}

// 卡这么死干什么

int main() {
	n = read(), k = read();
	for(ll i = 1; i <= n; i++) {
		a[i] = read();
	}
	solve(1, n);
	
	for(ll i = 2; i <= n; i++) {
		c[i] = a[i] - a[i-1];
	}
	for(ll i = 2; i < n-k; i++) {
		// 维护区间最小差值，一个上升单调队列
		while(h <= t && c[q[t]] >= c[i]) t--;
		q[++t] = i;
	}
	for(ll i = 1; i <= k+1; i++) {	// 左端点
		//  左端点 剩下的 自己
		ll j = i + n - k - 1;
		
		// 维护区间最小差值，一个上升单调队列
		while(h <= t && q[h] <= i) h++;		// 因为第i个插值是a(i)-a(i-1)，所以当头为i时也要去掉
		while(h <= t && c[q[t]] >= c[j]) t--;
		q[++t] = j;
		
		ans = min(ans, a[j] - a[i] + c[q[h]]);
	}
	printf("%lld", ans);
}
