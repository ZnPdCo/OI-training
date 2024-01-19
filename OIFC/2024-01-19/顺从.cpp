#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define N 120000
using namespace std;
ll n, m, st, ed;
ll a[N];


struct Q {
	ll x, y, id, ans;
} q1[N], q2[N], q3[N];	// q1 x<y，q2 x>y, q3 x=y
ll cnt1, cnt2, cnt3;

struct node {
	ll val, mn, head, tail;
} t[N*4];

struct res {
	ll val, head, tail;
	res(ll a=0,ll b=0,ll c=0) {val=a,head=b,tail=c;}
};

res query(ll l, ll r, ll pos, ll k) {
	if(t[pos].mn >= k) return res(0, 0, 0);
	if(l == r) {
		if(t[pos].mn < k) {
			return res(0, t[pos].head, t[pos].tail);
		} else {
			return res(0, 0, 0);
		}
	}
	ll mid = (l + r) >> 1;
	if(t[ls(pos)].mn >= k) return query(mid + 1, r, rs(pos), k);
	else {
		auto R = query(l, mid, ls(pos), k);
		if(t[pos].val - t[ls(pos)].val) {
			return res(R.val + a[R.tail] * (t[rs(pos)].head - R.tail) + t[pos].val - t[ls(pos)].val - a[t[ls(pos)].tail] * (t[rs(pos)].head - t[ls(pos)].tail), R.head, t[rs(pos)].tail);
		}
		else return R;
	}
}


void push_up(ll l, ll r, ll pos) {
	ll mid = (l + r) >> 1;
	auto R = query(mid + 1, r, rs(pos), t[ls(pos)].mn);
	if(R.tail) {
		t[pos].val = t[ls(pos)].val + a[t[ls(pos)].tail] * (R.head - t[ls(pos)].tail) + R.val;
		t[pos].tail = R.tail;
	}
	else {
		t[pos].val = t[ls(pos)].val;
		t[pos].tail = t[ls(pos)].tail;
	}
	t[pos].mn = min(t[ls(pos)].mn, t[rs(pos)].mn);
}

void update(ll l, ll r, ll pos, ll x, ll k) {
	if(l == r) {
		t[pos].mn = k;
		return;
	}
	
	ll mid = (l + r) >> 1;
	if(x <= mid)
		update(l, mid, ls(pos), x, k);
	else
		update(mid + 1, r, rs(pos), x, k);
	push_up(l, r, pos);
}


void build(ll l, ll r, ll pos) {
	if(l == r) {
		t[pos].mn = a[l];
		t[pos].val = 0;
		t[pos].head = l;
		t[pos].tail = l;
		return;
	}
	
	ll mid = (l + r) >> 1;
	build(l, mid, ls(pos));
	build(mid + 1, r, rs(pos));
	push_up(l, r, pos);
}

int main() {
	scanf("%lld %lld", &n, &m);
	for(ll i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	
	build(1, n, 1);
	
	for(ll i = 1; i <= n; i++) {
		ll k;
		scanf("%lld", &k);
		update(1, n, 1, k, 0);
		printf("%lld\n", t[1].val);
		update(1, n, 1, k, a[k]);
		a[i] = 0;
		update(1, n, 1, i, 1e15);
	}
}

