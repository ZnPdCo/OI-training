#include <cstdio>
#include <algorithm>
#define ll long long
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define N 1000010
using namespace std;
ll n, e, ans, len;
ll a[N], b[N], c[N];		// ci��ʾ��i���ᱻ�۵����� 
ll s[N], ss[N], to[N];

ll t[4*N];	// ά��ÿ��λ�õ����ܿ۶��� 
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
		t[pos] += k;		// ά����Сֵ 
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



// Ϊ��С������ʹ����״��������Ͱ

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
	// ���뵽�ˣ�����
	/*
	����һ��������e-ai��ʾ��ʹ�����ſ���֮ǰ�ܱ��۶��ٴ� 
	Ȼ�����߶�����ά�����������
	�������С��0˵����һ�ַ������Ա�ɾ������ȡ����ô�����Ķ���������
	��Ϊ���λ���ǵ����ģ��������Դ���
	���ž��Ǵ�������ʹ���0������
	�����������ɢ��+Ͱ�㣡 
	*/ 
	n =read(),e=read();
	for(ll i = 1; i <= n; i++) a[i] = read();
	for(ll i = 1; i <= n; i++) b[i] = read();
	for(ll i = 1; i <= n; i++) c[i] = a[i] - b[i];
	for(ll i = 1; i <= n; i++) {
		s[i] = s[i-1];
		s[i] -= c[i];
		ss[i+1] = s[i];	// ��ɢ��ʹ�� 
	}
	
	// ��һ���� 
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
	bool flag = 0;		// ��ʾ�Ѿ������r�ˣ������ټ����� 
	ll cost = 0;
	for(ll l = 1; l <= n; l++) {
		for(; r <= n; r++, flag=0) {
			if(!flag) {
				if(c[r] > 0) update(l, r-1, 1, n, 1, -c[r]);	// ��Ϊ������r��ǰ�������Ҫ���һ��r 
				
				update(r, r, 1, n, 1, e - a[r] - cost);
				
				if(c[r] > 0) cost += c[r];		// ����һλ����cost 
				flag = true;
				update1(to[r], 1);
			}
			
			if(query(l, r, 1, n, 1) < 0) {					// �������һ�ַ�ʽ���꣬�Ǿ�û�� 
				break;
			}
//			printf("%lld %lld\n", l, r);
			
			// ����һλ����Ͱ 
		}
		// ԭ������l��r���ж��ٸ�iʹ�� s[i]-s[l-1]>=0��Ҳ�����ж��ٸ� s[i]>=s[l-1]
//		for(ll i = l; i < r; i++) {
//			if(s[i] - s[l-1] >= 0) {
//				ans++;
//				printf("%lld %lld\n", l, i); 
//			}
//		}
		if(r <= n) update1(to[r], -1);
		ans += query1(len) - query1(to[l-1]-1); 
		if(r <= n) update1(to[r], 1);
		
		// Ҫ�޳�������Ǹ�cost 
		if(c[l] > 0) cost -= c[l]; 
		if(c[l] > 0) update(l+1, r, 1, n, 1, c[l]); 
		
		
		// ����l�߳�Ͱ 
		update1(to[l], -1);
	}
	
	printf("%lld", ans);
}
