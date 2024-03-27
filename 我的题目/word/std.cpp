#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define N 110
#define M 5
#define P 998244353
#define inf 1e9
ll n, m, k, q, cnt;
ll a[M], e[M];
ll ans[N];
ll nxt[M];
ll f[2][300000];
ll son[300000][M];
ll val[300000];
map<vector<ll>, ll> mp;
struct node {
	ll x, fa, c;
	vector<ll> nw;
	node(ll x_, ll fa_, ll c_, vector<ll> nw_) {
		x = x_, fa = fa_, c = c_, nw = nw_; 
	}
};
queue<node> que;
ll tot;
ll pre() {
	vector<ll> nw;
	nw.push_back(0);
	for(ll i = 1; i < m; i ++) nw.push_back(inf);
	que.push(node(1, 0, 0, nw));
	while(!que.empty()) {
		ll x = que.front().x;
		ll fa = que.front().fa;
		ll c = que.front().c;
		vector<ll> nw = que.front().nw;
		que.pop();
		
		if(mp.find(nw) != mp.end()) son[fa][c] = mp[nw];
		else if(x > n) son[fa][c] = 0;
		else {
			mp[nw] = ++ tot;
			ll ID = tot;
			val[tot] = inf;
			for(ll i = 0; i < m; i++) val[tot] = min(val[tot], nw[i]);
			
			for(ll c = 0; c <= cnt; c ++) {
				vector<ll> temp;
				for(ll j = 0; j < m; j ++) temp.push_back(inf);
				for(ll j = 0; j < m; j ++) {
					ll u = j;
					while(u && c != a[u + 1]) u = nxt[u];
					if(c == a[u + 1]) u ++;
					if(u < m) temp[u] = min(temp[u], nw[j]);
					temp[j] = min(temp[j], nw[j] + 1);
				}
				que.push(node(x + 1, ID, c, temp));
			}
		}
	}
	return 1;
}
int main() {
	scanf("%lld %lld %lld", &n, &m, &k);
	
	for(ll i = 1; i <= m; i ++) {
		scanf("%lld", &a[i]);
		e[i] = a[i];
	}
	sort(e + 1, e + 1 + m);
	cnt = unique(e + 1, e + 1 + m) - e - 1;
	for(ll i = 1; i <= m; i++) {
		a[i] = lower_bound(e + 1, e + 1 + cnt, a[i]) - e;
	}
	
	for(ll i = 2, j = 0; i <= m; i ++) {
		while(j && a[i] != a[j + 1]) j = nxt[j];
		if(a[i] == a[j + 1]) j++;
		nxt[i] = j;
	}
	f[0][pre()] = 1;
	ll p = son[1][1];
	p = son[p][2];
	p = son[p][1];
	p = son[p][2];
	p = son[p][1];
	p = son[p][2];
	p = son[p][1];
	p = son[p][2];
	p = son[p][1];
	printf("%lld\n", val[p]);/*
	
	for(ll i = 1; i <= n; i ++) {
		memset(f[i % 2], 0, sizeof f[i % 2]);
		for(ll s = 1; s <= tot; s ++) {
			for(ll c = 0; c <= cnt; c ++) {
				if(c == 0) (f[i % 2][son[s][c]] += f[(i - 1) % 2][s] * (k - cnt) % P) %= P;
				else (f[i % 2][son[s][c]] += f[(i - 1) % 2][s]) %= P;
			}
		}
	}
	
	for(ll s = 1; s <= tot; s ++) {
		(ans[val[s]] += f[n % 2][s]) %= P;
	}
	
	for(ll i = 0; i <= n; i ++) {
		(ans[i] += ans[i - 1]) %= P;
	}
	
	scanf("%lld", &q);
	while(q --) {
		ll x;
		scanf("%lld", &x);
		printf("%lld\n", ans[x]);
	}*/
}
