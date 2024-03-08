#include<bits/stdc++.h>
using namespace std;

void read(__int128 &x){
	// read a __int128 variable
	char c; bool f = 0;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') { f = 1; c = getchar(); }
	x = c - '0';
	while ((c = getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
	if (f) x = -x;
}
void write(__int128 x){
	// print a __int128 variable
	if (x < 0) { putchar('-'); x = -x; }
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

typedef long long ll;
const int N = 1e5 + 5, K = 120 + 5;
int T, c, n, m, k, ch[N * K][2], cnt;
int b[N]; ll sumb[N * K];
__int128 a[N], mina[N * K], ans;
int nnode() {
	cnt++;
	ch[cnt][0] = ch[cnt][1] = 0;
	mina[cnt] = (__int128)1 << k;
	sumb[cnt] = 0;
	return cnt;
}
void solve(int o, int d, int t, __int128 x, __int128 y, __int128 z) {
	if (d == -1) {
		ans = max(ans, z);
		return;
	}
	__int128 bit = (__int128)1 << d, mask = bit - 1;
	if (!o) {
		ans = max(ans, y + (x | mask | bit));
		return;
	}
	int lc = ch[o][0], rc = ch[o][1];
	bool flag = false;
	if (sumb[lc] <= t && (x | mask) + min(y, mina[lc]) >= (z | bit))
		solve(rc, d - 1, t - sumb[lc], x, min(y, mina[lc]), z | bit), flag = true;
	if (sumb[rc] <= t && (x | mask | bit) + min(y, mina[rc]) >= (z | bit))
		solve(lc, d - 1, t - sumb[rc], x | bit, min(y, mina[rc]), z | bit), flag = true;
	if (flag) return;
	solve(lc, d - 1, t, x, y, z);
	solve(rc, d - 1, t, x | bit, y, z);
}
int main() {
	//freopen("xor.in", "r", stdin);
	//freopen("xor.out", "w", stdout);
	scanf("%d%d", &c, &T);
	while (T--) {
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= n; i++) read(a[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
		cnt = 0; nnode();
		__int128 MAX = (__int128)1 << k;
		mina[0] = MAX;
		for (int i = 1; i <= n; i++) {
			int u = 1;
			sumb[u] += b[i];
			mina[u] = min(mina[u], a[i]);
			for (int j = k - 1; ~j; j--) {
				int x = a[i] >> j & 1;
				if (!ch[u][x]) ch[u][x] = nnode();
				u = ch[u][x];
				mina[u] = min(mina[u], a[i]);
				sumb[u] += b[i];
			}
		}
		ans = 0;
		if (sumb[1] <= m)
			ans = mina[1] + MAX - 1;
		else
			solve(1, k - 1, m, 0, MAX, 0);
		write(ans); putchar('\n');
	}
	return 0;
}

