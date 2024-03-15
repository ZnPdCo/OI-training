#include <cstdio>
#define ll long long
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define N 10010
#define M 600
#define P 100000007
ll n, q;
ll phi[M+10];
bool flag[M+10];
ll prime[200], cnt;
struct node {
	ll f[200];
	ll lazy[200];
	ll val;
} t[4*N];
ll a[N];
/*
  线段树维护积
  区间乘就是拆为多个质数，然后用lazy传下去
  怎么计算区间结果，就是这个区间是k的倍数乘以k，不是的乘以phi k。
 */
ll qpow(ll x, ll y) {
	if(y == 0) return 1;
	if(y % 2 == 1) return x * qpow(x, y-1) % P;
	ll tmp = qpow(x, y/2);
	return tmp*tmp % P;
}
void pushup(ll pos) {
	(t[pos].val = t[ls(pos)].val * t[rs(pos)].val) %= P;
	for(ll i = 1; i <= cnt; i++) {
		t[pos].f[i] = t[ls(pos)].f[i] + t[rs(pos)].f[i];
	}
}
void pushdown(ll l, ll r, ll pos) {
	ll mid = (l+r)>>1;
	for(ll i = 1; i <= cnt; i++) {
		for(ll j = 1; j <= t[pos].lazy[i]; j++) {
			(t[ls(pos)].val *= qpow(prime[i], t[ls(pos)].f[i]) * qpow(phi[prime[i]], mid-l+1-t[ls(pos)].f[i]) % P) %= P;
			(t[rs(pos)].val *= qpow(prime[i], t[rs(pos)].f[i]) * qpow(phi[prime[i]], r-mid-t[rs(pos)].f[i]) % P) %= P;
			t[ls(pos)].f[i] = mid-l+1;
			t[rs(pos)].f[i] = r-mid;
		}
	}
	for(ll i = 1; i <= cnt; i++) if(t[pos].lazy[i]){
		t[ls(pos)].lazy[i] += t[pos].lazy[i];
		t[rs(pos)].lazy[i] += t[pos].lazy[i];
		t[pos].lazy[i] = 0;
	}
}
void build(ll l, ll r, ll pos) {
	if(l == r) {
		t[pos].val = phi[a[l]];
		for(ll i = 1; i <= cnt; i++) {
			if(a[l] % prime[i] == 0) {
				t[pos].f[i]++;
			}
		}
		return;
	}
	ll mid = (l + r) >> 1;
	build(l, mid, ls(pos));
	build(mid+1, r, rs(pos));
	pushup(pos);
}
void update(ll nl, ll nr, ll l, ll r, ll pos, ll k) {
	if(nl <= l && r <= nr) {
		(t[pos].val *= qpow(prime[k], t[pos].f[k]) * qpow(phi[prime[k]], r-l+1-t[pos].f[k]) % P) %= P;
		t[pos].lazy[k]++;
		t[pos].f[k] = r-l+1;
		return;
	}
	pushdown(l, r, pos);
	ll mid = (l + r) >> 1;
	if(nl <= mid)
		update(nl, nr, l, mid, ls(pos), k);
	if(mid < nr)
		update(nl, nr, mid+1, r, rs(pos), k);
	pushup(pos);
}
ll query(ll nl, ll nr, ll l, ll r, ll pos) {
	if(nl <= l && r <= nr) {
		return t[pos].val;
	}
	pushdown(l, r, pos);
	ll res = 1;
	ll mid = (l + r) >> 1;
	if(nl <= mid)
		(res *= query(nl, nr, l, mid, ls(pos))) %= P;
	if(mid < nr)
		(res *= query(nl, nr, mid+1, r, rs(pos))) %= P;
	return res;
}
void init() {
	phi[1] = 1;
	for(ll i = 2; i <= M; i++) {
		if(flag[i] == 0) {
			phi[i] = i-1;
			prime[++cnt] = i; 
		}
		for(ll j = 1; j <= cnt && i*prime[j] <= M; j++) {
			flag[i*prime[j]] = 1;
			if(i % prime[j] == 0) {
				phi[i*prime[j]] = phi[i] * prime[j];
				break;
			}
			phi[i*prime[j]] = phi[i] * phi[prime[j]];
		}
	}
}
int main() {
	init();
	scanf("%lld", &n);
	for(ll i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	build(1, n, 1);
	scanf("%lld", &q);
	for(ll i = 1; i <= q; i++) {
		ll op, l, r, x;
		scanf("%lld %lld %lld", &op, &l, &r);
		if(op == 0) {
			scanf("%lld", &x);
			for(ll j = 1; j <= cnt && x != 1; j++) {
				while(x % prime[j] == 0) {
					update(l, r, 1, n, 1, j);
					x /= prime[j];
				}
			}
		} else {
			printf("%lld\n", query(l, r, 1, n, 1));
		}
	}
	return 0;
}
