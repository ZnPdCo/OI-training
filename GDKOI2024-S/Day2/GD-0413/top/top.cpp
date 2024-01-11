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



// 为减小码量，使用树状数组来高桶

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
	// 我想到了！！！
	/*
	首先一个卡牌有e-ai表示在使用这张卡牌之前能被扣多少次 
	然后拿线段树来维护这个东西。
	如果存在小于0说明有一种方法可以被删到不可取，那么这后面的都不可能了
	因为这个位置是递增的，可以线性处理
	接着就是处理区间和大于0的区间
	这个可以用离散化+桶搞！ 
	*/ 
	n =read(),e=read();
	for(ll i = 1; i <= n; i++) a[i] = read();
	for(ll i = 1; i <= n; i++) b[i] = read();
	for(ll i = 1; i <= n; i++) c[i] = a[i] - b[i];
	for(ll i = 1; i <= n; i++) {
		s[i] = s[i-1];
		s[i] -= c[i];
		ss[i+1] = s[i];	// 离散化使用 
	}
	
	// 第一次用 
	sort(ss+1, ss+1+n+1);
	len = unique(ss+1, ss+1+n+1)-ss-1;
	for(ll i = 0; i <= n; i++) {
		ll l = 1, r = len;
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
			
			// 把这一位加入桶 
		}
		// 原本是求l到r内有多少个i使得 s[i]-s[l-1]>=0，也就是有多少个 s[i]>=s[l-1]
//		for(ll i = l; i < r; i++) {
//			if(s[i] - s[l-1] >= 0) {
//				ans++;
//				printf("%lld %lld\n", l, i); 
//			}
//		}
		if(r <= n) update1(to[r], -1);
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
