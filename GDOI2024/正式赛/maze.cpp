#include <cstdio>
#include <algorithm>
#define ll long long
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define N 17
using namespace std;
ll T, n, k;
ll w[1<<N];
ll q[1<<N];
ll ans[N], cnt;

namespace bf {
	ll ans[(1<<4)+10], mx[(1<<4)+10];
	bool v[(1<<4)+10];
	ll c[(1<<4)+10];
	ll cnt;
	void dfs(ll u) {
		if((1<<n) <= u && u < (1<<(n+1))) {
			c[++cnt] = q[u-(1<<n)+1];
			if(cnt >= (1<<n)) {
				bool flag = 0;
				for(ll i = 1; i <= cnt; i++) {
					if(c[i] < ans[i]) {
						flag = 1;
						break;
					} else if(c[i] > ans[i]) {
						break;
					}
				}
				if(flag) {
					for(ll i = 1; i <= cnt; i++) {
						ans[i] = c[i];
					}
				}
			}
			return;
		}
		ll tmp = cnt;
		if(v[u]) {
			dfs(u*2);
			dfs(u*2+1);
		} else {
			dfs(u*2);
			dfs(u*2+1);
			ll cc[(1<<4)+10];
			for(ll i = 1; i <= cnt; i++) cc[i] = c[i];
			cnt = tmp;
			dfs(u*2+1);
			dfs(u*2);
			bool flag = 0;
			for(ll i = 1; i <= cnt; i++) {
				if(cc[i] < c[i]) {
					flag = 1;
					break;
				} else if(cc[i] > c[i]) {
					break;
				}
			}
			if(flag) {
				for(ll i = 1; i <= cnt; i++) {
					c[i] = cc[i];
				}
			}
		}
	}
	void solve() {
		mx[1] = -1e15;
		for(ll s = 0; s < (1<<((1<<n)-1)); s++) {
			ll sum = 0;
			for(ll i = 1; i < (1<<n); i++) {
				if(s & (1<<(i-1))) {
					sum += w[i];
					v[i] = 1;
				} else {
					v[i] = 0;
				}
			}
			if(sum <= k) {
				ans[1] = 1e15;
				cnt = 0;
				dfs(1);
				bool flag = 0;
				for(ll i = 1; i <= (1<<n); i++) {
					if(ans[i] > mx[i]) {
						flag = 1;
						break;
					} else if(ans[i] < mx[i]) {
						break;
					}
				}
				if(flag) {
					for(ll i = 1; i <= cnt; i++) {
						mx[i] = ans[i];
					}
				}
			}
		}
		for(ll i = 1; i <= (1<<n); i++) {
			printf("%lld ", mx[i]);
		}
		printf("\n");
	}
}

namespace A {
	ll tot;
	void dfs(ll pos) {
		if((1<<n) <= pos && pos < (1<<(n+1))) {
			ans[++cnt] = q[pos - (1<<n) + 1];
			return;
		}
		if(tot >= w[pos]) {
			tot -= w[pos];
			dfs(ls(pos));
			dfs(rs(pos));
		} else {
			dfs(rs(pos));
			dfs(ls(pos));
		}
	}
	void solve() {
		cnt = 0;
		tot = k;
		dfs(1);
		for(ll i = 1; i <= cnt; i++) {
			printf("%lld ", ans[i]);
		}
		printf("\n");
	}
}


int main() {
	freopen("maze.in", "r", stdin);
	freopen("maze.out", "w", stdout);
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld %lld", &n, &k);
		for(ll i = 1; i < (1<<n); i++) {
			scanf("%lld", &w[i]);
		}
		bool isA = true;
		for(ll i = 1; i <= (1<<n); i++) {
			scanf("%lld", &q[i]);
			if(q[i] != (1<<n)-i+1) isA = false;
		}
		if(isA) A::solve();
		else bf::solve();
	}
}
