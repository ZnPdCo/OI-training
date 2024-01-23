#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;
const ll N = 110, M = N * (N + 1) / 2;

ll n, m;
ll st, ed;
ll e[M];

inline ll min(ll x, ll y) {
	return x < y ? x : y;
}


namespace Graph {
	ll head[N];
	ll cost[2*M], nxt[2*M], to[2*M], cnt;

	void add_edge(ll u, ll v, ll w) {
		cnt++;
		to[cnt] = v;
		cost[cnt] = w;
		nxt[cnt] = head[u];
		head[u] = cnt;
	}
}

struct Pair {
	ll x, y;

	friend bool operator>(const Pair &x, const Pair &y) {
		return x.x > y.x;
	}
};

namespace Heap {
	Pair h[M];
	ll top;

	void up(ll x) {
		while(x > 1 && h[x] > h[x/2]) {
			swap(h[x], h[x/2]);
			x /= 2;
		}
	}
	void down(ll x) {
		while (x * 2 <= top) {
			ll t = x * 2;
			if (t + 1 <= top && h[t + 1] > h[t]) t++;
			if (h[x] > h[t]) break;
			swap(h[x], h[t]);
			x = t;
		}
	}
	
	void push(Pair x) {
		h[++top] = x;
		up(top);
	}

	void pop() {
		swap(h[1], h[top]);
		top--;
		down(1);
	}
}

namespace Dij {
	using namespace Graph;

	ll dis[N];
	bool vis[N];
	ll solve(ll mx) {
		memset(vis, 0, sizeof vis);
		for(ll i = 1; i <= n; i++) dis[i] = -1e10;
		dis[st] = mx;

		Heap::push((Pair){0, st});

		while(Heap::top) {
			ll u = Heap::h[1].y;
			Heap::pop();
			if(vis[u]) continue;
			vis[u] = 1;
			for(ll i = head[u]; i; i = nxt[i]) {
				ll v = to[i], w = cost[i];
				if(w > mx) continue;
				if(!vis[v]) {
					if(dis[v] < min(dis[u], w)) {
						dis[v] = min(dis[u], w);
						Heap::push((Pair){dis[v], v});
					}
				}
			}
		}

		return dis[ed];
	}
}


int main() {
	scanf("%lld %lld", &n, &m);
	
	for(ll i = 1; i <= m; i++) {
		ll u, v, w;
		scanf("%lld %lld %lld", &u, &v, &w);
		e[i] = w;
		Graph::add_edge(u, v, w);
		Graph::add_edge(v, u, w);
	}

	scanf("%lld %lld", &st, &ed);

	stable_sort(e+1, e+1+m);
	ll len = unique(e+1, e+1+m) - e - 1;

	ll ans = 1e10;
	for(ll i = 1; i <= len; i++) {
		ll mn = Dij::solve(e[i]);
		ans = min(ans, e[i] - mn);
	}

	if(ans == 1e10) printf("-1\n");
	else printf("%lld\n", ans);
}