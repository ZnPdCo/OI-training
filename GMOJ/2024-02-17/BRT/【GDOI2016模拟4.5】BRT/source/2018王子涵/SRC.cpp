#include<cstdio>

#include<cstring>

#include<vector>

typedef long long ll;

using namespace std;

const int maxn = 1e5 + 10;

int n, m, num;

ll g, r, p;

ll w[maxn], f[maxn];

struct SegmentTree {int sum, ls, rs;} empty;

vector<SegmentTree> tree;

int query(int k, ll l, ll r, ll x, ll y) {
	if (x <= l && r <= y) return tree[k].sum;
	int res = n + 1;
	ll mid = (l + r) >> 1;
	if (x <= mid && tree[k].ls) res = min(res, query(tree[k].ls, l, mid, x, y));
	if (y > mid && tree[k].rs) res = min(res, query(tree[k].rs, mid + 1, r, x, y));
	return res;
}

void change(int k, ll l, ll r, ll x, ll v) {
	if (l == r) {
		tree[k].sum = v;
		return;
	}
	if (!tree[k].ls) {
		tree[k].ls = ++num;
		tree.push_back(empty);
		tree[num].sum = n + 1;
	}
	if (!tree[k].rs) {
		tree[k].rs = ++num;
		tree.push_back(empty);
		tree[num].sum = n + 1;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) change(tree[k].ls, l, mid, x, v);
	else change(tree[k].rs, mid + 1, r, x, v);
	tree[k].sum = min(tree[tree[k].ls].sum, tree[tree[k].rs].sum);
}

int main() {
	scanf("%d%lld%lld", &n, &g, &r);
	p = g + r;
	tree.push_back(empty);
	tree[0].sum = n + 1;
	for (int i = 1; i <= n + 1; ++i) {
		scanf("%lld", &w[i]);
		w[i] += w[i - 1];
	}
	for (int i = n, j; i; --i) {
		ll t = (p - w[i] % p) % p;
		j = query(0, 0, p - 1, max(0ll, g - t), p - 1ll - t);
		if (g - t < 0) j = min(j, query(0, 0, p - 1, p + g - t, p - 1));
		if (j > n) f[i] = w[n + 1] - w[i];
		else f[i] = f[j] + w[j] - w[i] + (p - (w[j] - w[i]) % p);
		change(0, 0, p - 1, w[i] % p, i);
	}
	scanf("%d", &m);
	while (m--) {
		int y;
		ll x, t;
		scanf("%lld", &x);
		t = x % p;
		y = query(0, 0, p - 1, max(0ll, g - t), p - 1 - t);
		if (g - t < 0) y = min(y, query(0, 0, p - 1, p + g - t, p - 1));
		if (y > n) printf("%lld\n", w[n + 1] + x);
		else printf("%lld\n", w[y] + x + f[y] + (p - (t + w[y]) % p));
	}
	return 0;
}