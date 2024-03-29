#include <bits/stdc++.h>
using namespace std;
#define N 110
#define S 3000
#define P 998244353
#define ll long long
ll n, cnt;
ll num[N];	// 出了的个数
ll son[S][5];
ll C[5][5];
ll f[2][N * 4][S];
ll fac[N * 4], inv;
ll ans;
struct node {
	ll f[3][3][2];
	ll num;	// 7对子个数
	node() {
		memset(f, -1, sizeof f);
		num = 0;
	}
	friend bool operator <(const node &x, const node &y) {
		for(ll a = 0; a <= 2; a ++) {
			for(ll b = 0; b <= 2; b ++) {
				for(ll c = 0; c <= 1; c ++) {
					if(x.f[a][b][c] != y.f[a][b][c]) return x.f[a][b][c] < y.f[a][b][c];
				}
			}
		}
		return x.num < y.num;
	} 
};

map<node, ll> mp;

ll dfs(node lst) {
	if(mp.find(lst) != mp.end()) return mp[lst];
	mp[lst] = ++ cnt;
	ll ID = cnt;
	for(ll i = 0; i <= 4; i ++) { // 这次牌数
		node nxt;
		nxt.num = lst.num + (i >= 2);
		bool flag = (nxt.num == 7);
		for(ll a = 0; a <= 2 && a <= i && !flag; a ++) {	// 这一个为顺子结尾的个数
			for(ll b = 0; b <= 2 && a + b <= i && !flag; b ++) {	// 这一个为顺子中间的个数
				for(ll c = 0; c <= 2 && a + b + c <= i && !flag; c ++) {	// 这一个为顺子开头的个数
					if(lst.f[a][b][0] != -1)
						nxt.f[b][c][0] = min(max(nxt.f[b][c][0], lst.f[a][b][0] + a + (i - a - b - c) / 3), 4ll);
					if(lst.f[a][b][1] != -1)
						nxt.f[b][c][1] = min(max(nxt.f[b][c][1], lst.f[a][b][1] + a + (i - a - b - c) / 3), 4ll);
					if(a + b + c + 2 <= i && lst.f[a][b][0] != -1)
						nxt.f[b][c][1] = min(max(nxt.f[b][c][1], lst.f[a][b][0] + a + (i - a - b - c - 2) / 3), 4ll);
					if(nxt.f[b][c][1] == 4)
						flag = 1;
				}
			}
		}
		if(!flag) {
			son[ID][i] = dfs(nxt);
		}
	}
	return ID;
}
ll qpow(ll x, ll y) {
	if(y == 0) return 1;
	if(y % 2 == 1) return x * qpow(x, y - 1) % P;
	ll tmp = qpow(x, y / 2);
	return tmp * tmp % P;
}

void pre() {
	for(ll i = 0; i <= 4; i ++) {
		for(ll j = 0; j <= i; j ++) {
			if(!j) C[i][j] = 1;
			else C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
		}
	}
	fac[0] = 1;
	for(ll i = 1; i <= 4 * n - 13; i++) {
		fac[i] = fac[i - 1] * i % P;
	}
	inv = qpow(fac[4 * n - 13], P - 2);
	
	node sta;
	sta.f[0][0][0] = 0;	// 可以修改
	dfs(sta);
}
int main() {
	scanf("%lld", &n);
	for(ll i = 1; i <= 13; i ++) {
		ll x, y;
		scanf("%lld %lld", &x, &y);
		num[x] ++;
	}
	pre();
	f[0][0][1] = 1;
	for(ll i = 1; i <= n; i ++) {
		memset(f[i % 2], 0, sizeof f[i % 2]);
		for(ll j = 0; j <= (i - 1) * 4; j ++) {
			for(ll s = 1; s <= cnt; s ++) {
				if(f[(i - 1) % 2][j][s]) {
					for(ll c = 0; c <= 4 - num[i]; c ++) {
						(f[i % 2][j + c][son[s][num[i] + c]] += f[(i - 1) % 2][j][s] * C[4 - num[i]][c]) %= P;
					}
				}
			}
		}
	}
	for(ll i = 0; i <= 4 * n - 13; i ++) {
		for(ll s = 1; s <= cnt; s ++) {
			(ans += fac[i] * fac[4 * n - 13 - i] % P * f[n % 2][i][s] % P) %= P;
		}
	}
	ans = (ans * inv) % P;
	printf("%lld", ans);
}
