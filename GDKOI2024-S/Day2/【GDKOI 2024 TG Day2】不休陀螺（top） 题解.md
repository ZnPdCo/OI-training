# 【GDKOI 2024 TG Day2】不休陀螺（top） 题解

考虑一个卡牌区间怎样才不是”陀螺无限“。

一个是费用在打到一半时费用就不够了。考虑构造一个卡牌序列使其尽量能够在打到一半时费用就不够，如何构造呢？

把 $a_i > b_i$ 的卡牌称作消耗型卡牌，其他叫做获得型卡牌。我们可以构造把消耗型卡牌全部放在前面，后面突然来个很大的 $a_i$ 就可以让你费用耗尽了。

但是我们不能贪心地选择，因为假如我们选择这个突然来的很大的 $a_i$ 也是一个很大的消耗型卡牌，如果把它作为”引火线“就会导致前面消耗的费用不够多，这个导火线也就导不了火。

其实我们可以储存 $E-a_i$ 表示在使用这张卡片前最多能够消耗的费用，假如一个区间其余的消耗型卡牌起作用使得 $E-a_i-\text{其他消耗型卡牌的消耗}<0$，那么这个区间就不是”陀螺无限“。这个可以拿线段树维护。

我们只需要枚举区间左端点，然后计算最大的右端点，这个区间内的所有卡牌区间就都是合法方案了，$O(n^2)$。 

我们会发现，左端点向右移动一位后，对区间内的影响是什么？

如果这个左端点是个消耗型卡牌，那么区间的消耗都会补回这个消耗，这个区间可能合法了，右端点可能可以往右移动；如果左端点是获得性卡牌，对区间没有任何影响。

这说明右端点是递增的，可以均摊 $O(n)$ 得到合法区间。

---

另外一个卡牌区间不是”陀螺无限“是这个区间的代价 $\sum b_i-\sum a_i<0$，这样就算打完一周后总费用也会减少，那么以此类推会越来越少。

这个比较简单，可以维护代价前缀和，也就是求 $s_i-s_{j-1}\ge0$ 区间个数，即 $s_i\ge s_{j-1}$，这个可以树状数组维护。

```c++
#include <cstdio>
#include <algorithm>
#define ll long long
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define N 1000010
using namespace std;
ll n, e, ans, len;
ll a[N], b[N], c[N];		// ci表示第i个会被扣掉多少 
ll s[N], ss[N], to[N];

ll t[4*N];	// 维护每个位置的数能扣多少 
ll lazy[4*N];

inline ll min(ll x, ll y) {
	return x > y ? y : x;
}
void pushup(ll pos) {
	t[pos] = min(t[ls(pos)], t[rs(pos)]);
}
void pushdown(ll pos) {
	t[ls(pos)] += lazy[pos];
	t[rs(pos)] += lazy[pos];
	lazy[ls(pos)] += lazy[pos];
	lazy[rs(pos)] += lazy[pos];
	lazy[pos] = 0;
}
void update(ll nl, ll nr, ll l, ll r, ll pos, ll k) {
	if(nl > nr) return;
	if(nl <= l && r <= nr) {
		t[pos] += k;		// 维护最小值 
		lazy[pos] += k;
		return;
	}
	if(lazy[pos]) {
		pushdown(pos);
	}
	
	ll mid = (l + r) >> 1;
	if(nl <= mid) {
		update(nl, nr, l, mid, ls(pos), k);
	}
	if(mid < nr) {
		update(nl, nr, mid+1, r, rs(pos), k);
	}
	
	pushup(pos);
}
ll query(ll nl, ll nr, ll l, ll r, ll pos) {
	if(nl <= l && r <= nr) {
		return t[pos];
	}
	if(lazy[pos]) {
		pushdown(pos);
	}
	
	ll mid = (l + r) >> 1;
	ll res = 1e15;
	if(nl <= mid) {
		res = min(res, query(nl, nr, l, mid, ls(pos)));
	}
	if(mid < nr) {
		res = min(res, query(nl, nr, mid+1, r, rs(pos)));
	}
	return res;
}

// 桶

ll tong[N];

inline ll lowbit(ll x) {
	return x & (-x);
} 

void update1(ll x, ll val) {
	while(x<=len) {
		tong[x] += val;
		x += lowbit(x);
	}
} 

ll query1(ll x) {
	ll res=0;
	while(x) {
		res += tong[x];
		x -= lowbit(x);
	}
	return res;
}

ll read() {
	ll x = 0;
	char c = '.';
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9') {
		x = (x<<1)+(x<<3)+(c^'0');
		c = getchar();
	}
	return x;
}

int main() {
	freopen("top.in", "r", stdin);
	freopen("top.out", "w", stdout);
    
	n =read(),e=read();
	for(ll i = 1; i <= n; i++) a[i] = read();
	for(ll i = 1; i <= n; i++) b[i] = read();
	for(ll i = 1; i <= n; i++) c[i] = a[i] - b[i];	// 反过来好处理
	for(ll i = 1; i <= n; i++) {
		s[i] = s[i-1];
		s[i] -= c[i];
		ss[i+1] = s[i];	// 离散化使用 
	}
	
	// 离散化
	sort(ss+1, ss+1+n+1);  // 把0也离散化
	len = unique(ss+1, ss+1+n+1)-ss-1;
	for(ll i = 0; i <= n; i++) {
		ll l = 1, r = len;		// 考场上不会用lower_bound
		while(l <= r) {
			ll mid = (l + r) >> 1;
			if(ss[mid] < s[i]) l = mid+1;
			if(ss[mid] > s[i]) r = mid-1;
			if(ss[mid] == s[i]) {
				to[i] = mid;
				break;
			}
		}
	}
	
	ll r = 1;
	bool flag = 0;		// 表示已经加入过r了，不用再加入了 
	ll cost = 0;
	for(ll l = 1; l <= n; l++) {
		for(; r <= n; r++, flag=0) {
			if(!flag) {
				if(c[r] > 0) update(l, r-1, 1, n, 1, -c[r]);	// 因为加入了r，前面的数都要多扣一个r 
				
				update(r, r, 1, n, 1, e - a[r] - cost);
				
				if(c[r] > 0) cost += c[r];		// 把这一位加入cost 
				flag = true;
				update1(to[r], 1);
			}
			
			if(query(l, r, 1, n, 1) < 0) {					// 如果存在一种方式扣完，那就没了 
				break;
			}
//			printf("%lld %lld\n", l, r);
		}
		// 原本是求l到r内有多少个i使得 s[i]-s[l-1]>=0，也就是有多少个 s[i]>=s[l-1]
//		for(ll i = l; i < r; i++) {
//			if(s[i] - s[l-1] >= 0) {
//				ans++;
//				printf("%lld %lld\n", l, i); 
//			}
//		}
		if(r <= n) update1(to[r], -1);	// 第r位被剔除，所以第r位是不合法的
		ans += query1(len) - query1(to[l-1]-1); 
		if(r <= n) update1(to[r], 1);
		
		// 要剔除最左边那个cost 
		if(c[l] > 0) cost -= c[l]; 
		if(c[l] > 0) update(l+1, r, 1, n, 1, c[l]); 
		
		// 把这l踢出桶 
		update1(to[l], -1);
	}
	
	printf("%lld", ans);
}
```