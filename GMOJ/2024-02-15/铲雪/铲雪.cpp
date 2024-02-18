#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define N 1000010
int n, m, q;

struct node {
	int mx, mn;
	node(int a=0,int b=0) {mx=a,mn=b;}
};

struct seg {
	node t[4*N];
	void update(int x, int k, int l, int r, int pos) {
		if(l == r) {
			t[pos].mx = k;
			t[pos].mn = k;
			return;
		}
		
		int mid = (l+r)>>1;
		if(x <= mid)
			update(x, k, l, mid, ls(pos));
		else
			update(x, k, mid+1, r, rs(pos));
		
		
		t[pos].mx = max(t[ls(pos)].mx, t[rs(pos)].mx);
		t[pos].mn = min(t[ls(pos)].mn, t[rs(pos)].mn);
	}
	node query(int nl, int nr, int l, int r, int pos) {
		if(nl <= l && r <= nr) {
			return t[pos];
		}
		
		int mid = (l+r)>>1;
		
		node res, res1(0, 1e9), res2(0, 1e9);
		
		if(nl <= mid) {
			res1 = query(nl, nr, l, mid, ls(pos));
		}
		if(mid < nr) {
			res2 = query(nl, nr, mid+1, r, rs(pos));
		}
		
		res.mx = max(res1.mx, res2.mx);
		res.mn = min(res1.mn, res2.mn);
		
		return res;
	}
	
	int binary1(int nl, int nr, int ti, int k, int l, int r, int pos) {
		if(nl > nr) return -1;
		if(ti - t[pos].mx > k) return -1;
		if(l == r) {
			return l;
		}
		
		int mid = (l+r)>>1;
		int res = -1;
		if(nl <= mid) 
			res = binary1(nl, nr, ti, k, l, mid, ls(pos));
		if(res == -1 && mid < nr) 
			res = binary1(nl, nr, ti, k, mid+1, r, rs(pos));
		
		return res;
	}
	
	int binary2(int nl, int nr, int ti, int k, int l, int r, int pos) {
		if(nl > nr) return -1;
		if(ti - t[pos].mx > k) return -1;
		
		if(l == r) {
			return l;
		}
		
		int mid = (l+r)>>1;
		
		int res = -1;
		if(mid < nr) 
			res = binary2(nl, nr, ti, k, mid+1, r, rs(pos));
		if(res == -1 && nl <= mid)
			res = binary2(nl, nr, ti, k, l, mid, ls(pos));
		
		return res;
	}
} col, row;

inline int abs(int x) {return x > 0 ? x : -x;}

int main() {
//	freopen("snow.in", "r", stdin);
//	freopen("snow.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 1; i <= q; i++) {
		int op;
		scanf("%d", &op);
		if(op == 1) {
			int x;
			scanf("%d", &x);
			row.update(x, i, 1, n, 1);
		} else if(op == 2) {
			int x;
			scanf("%d", &x);
			col.update(x, i, 1, m, 1);
		} else if(op == 3) {
			int x1, y1, x2, y2, k;
			
			scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &k);
			
			int s = abs(x1-x2)+abs(y1-y2);
			
			node res = row.query(min(x1, x2), max(x1, x2), 1, n, 1);
			if(i - res.mn <= k) {
				printf("%d\n", s);
				continue;
			}
			
			
			res = col.query(min(y1, y2), max(y1, y2), 1, m, 1);
			if(i - res.mn <= k) {
				printf("%d\n", s);
				continue;
			}
			
			node res1 = row.query(x1, x1, 1, n, 1);
			node res2 = col.query(y2, y2, 1, m, 1);
			if(i - res1.mx <= k && i - res2.mx <= k) {
				printf("%d\n", s);
				continue;
			}
			
			res1 = row.query(x2, x2, 1, n, 1);
			res2 = col.query(y1, y1, 1, m, 1);
			if(i - res1.mx <= k && i - res2.mx <= k) {
				printf("%d\n", s);
				continue;
			}
			
			res1 = row.query(x1, x1, 1, n, 1);
			res2 = row.query(x2, x2, 1, n, 1);
			node res3 = col.query(min(y1, y2), max(y1, y2), 1, m, 1);
			if(i - res1.mx <= k && i - res2.mx <= k && i - res3.mx <= k) {
				printf("%d\n", s);
				continue;
			}
			
			res1 = col.query(y1, y1, 1, m, 1);
			res2 = col.query(y2, y2, 1, m, 1);
			res3 = row.query(min(x1, x2), max(x1, x2), 1, n, 1);
			if(i - res1.mx <= k && i - res2.mx <= k && i - res3.mx <= k) {
				printf("%d\n", s);
				continue;
			}
			
			int ans = 1e9;
			
			res1 = row.query(x1, x1, 1, n, 1);
			res2 = row.query(x2, x2, 1, n, 1);
			int res4 = col.binary2(1, min(y1, y2)-1, i, k, 1, m, 1);
			if(i - res1.mx <= k && i - res2.mx <= k && res4 != -1) {
				ans = min(ans, s + 2 * (min(y1, y2) - res4));
			}
			
			res4 = col.binary1(max(y1, y2)+1, m, i, k, 1, m, 1);
			if(i - res1.mx <= k && i - res2.mx <= k && res4 != -1) {
				ans = min(ans, s + 2 * (res4 - max(y1, y2)));
			}
			
			res1 = col.query(y1, y1, 1, m, 1);
			res2 = col.query(y2, y2, 1, m, 1);
			res4 = row.binary2(1, min(x1, x2)-1, i, k, 1, n, 1);
			if(i - res1.mx <= k && i - res2.mx <= k && res4 != -1) {
				ans = min(ans, s + 2 * (min(x1, x2) - res4));
			}
			
			res4 = row.binary1(max(x1, x2)+1, n, i, k, 1, n, 1);
			if(i - res1.mx <= k && i - res2.mx <= k && res4 != -1) {
				ans = min(ans, s + 2 * (res4 - max(x1, x2)));
			}
			
			if(ans == 1e9) printf("-1\n");
			else printf("%d\n", ans);
		}
	}
}
