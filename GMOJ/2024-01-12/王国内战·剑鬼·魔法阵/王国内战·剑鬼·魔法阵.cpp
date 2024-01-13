/**
 * @file 王国内战·剑鬼·魔法阵.cpp 
 * @tag: #GMOJ#结论#图论
 * @author: ZnPdCo
 * @date: 2024-01-13
 * @problem: https://gmoj.net/senior/#main/show/6958
 **/
#include <cstdio>
#include <algorithm>
#define ll long long
#define N 100010
using namespace std;
ll n, ans;
ll t[N];
ll val[N];

ll head[N];
ll nxt[2*N];
ll cost[2*N];
ll to[2*N], cnt = 1;
bool sta = 0;
void addEdge(ll u, ll v, ll w) {
	++cnt;
	to[cnt] = v;
	cost[cnt] = w;
	nxt[cnt] = head[u];
	head[u] = cnt;
}


ll dfn[N], ti;

ll co[N], tot;

struct node {
	ll l, r;	// l较小，r较大
	// 先手要选择li，则li+rj<=lj+ri，即使得li-ri尽量小
	// 后手要选择ri，则ri+lj>=rj+li，即使得li-ri尽量小
} even[N];		// 存储所有偶数环的l-r
ll num;

ll dfs(ll u, ll lst=0) {
	dfn[u] = ti;
	for(ll i = head[u]; i; i = nxt[i]) {
		ll v = to[i];
		if((i ^ 1) == lst) continue;		// 不能走同一条边
		if(!dfn[v]) {
			ll res = dfs(v, i);
			if(res) {
				co[++tot] = cost[i]; 
				ans -= cost[i];
				if(res == u) {
					ti++;
					return 0;
				}
				return res;
			}
		} else if(dfn[v] == ti) {
			co[++tot] = cost[i]; 
			ans -= cost[i];
			if(v == u) {
				ti++;
				return 0;
			}
			return v;
		}
	}
	return 0;
}
bool cmp(node x, node y) {
	return x.l-x.r<y.l-y.r;
}
int main() {
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
	scanf("%lld", &n);
	for(ll i = 1; i <= n; i++) {
		scanf("%lld", &t[i]);
	}
	for(ll i = 1; i <= n; i++) {
		scanf("%lld", &val[i]);
		addEdge(i, t[i], val[i]);
		addEdge(t[i], i, val[i]);
		ans += val[i];
	}
	for(ll i = 1; i <= n; i++) {
		if(!dfn[i]) {
			ti++;
			tot = 0;
			dfs(i);
			if(!tot) continue;
			sort(co+1, co+1+tot);
			if(tot % 2 == 1) {					// 奇数情况不选择中位数
				for(ll j = 1; j <= tot; j++) if(j != tot / 2 + 1) {
					ans += co[j];
				}
			} else {							// 偶数情况选择l-r最小
				for(ll j = 1; j <= tot; j++) if(j != tot / 2 && j != tot / 2 + 1) {
					ans += co[j];
				}
				even[++num].l = co[tot/2];
				even[num].r = co[tot/2+1];
			}
		}
	}
	sort(even+1, even+1+num, cmp);
	sta = 0;
	for(ll i = 1; i <= num; i++) {
		if(!sta) {
			ans += even[i].l;
		} else {
			ans += even[i].r;
		}
		sta = !sta;
	}
	printf("%lld", ans);
}
