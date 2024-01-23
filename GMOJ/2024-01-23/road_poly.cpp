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

    void clear() {
        memset(head, 0, sizeof head);
        cnt = 0;
    }
    void add_edge(ll u, ll v, ll w) {
        cnt++;
        to[cnt] = v;
        cost[cnt] = w;
        nxt[cnt] = head[u];
        head[u] = cnt;
    }
}

namespace Poly {
    using namespace Graph;
    
    bool vis[N];
    ll ans;

    void dfs(ll u, ll mx, ll mn) {
        if(u == ed) {
            ans = min(ans, mx - mn);
        }
        for(ll i = head[u]; i; i = nxt[i]) if(!vis[to[i]]) {
            ll v = to[i], w = cost[i];
            vis[v] = 1;
            dfs(v, max(mx, w), min(mn, w));
            vis[v] = 0;
        }
    }

    void solve() {
        memset(vis, 0, sizeof vis);
        ans = 1e15;
        dfs(st, 0, 1e10);
        if(ans == 1e15) printf("-1\n");
        else printf("%lld\n", ans);
    }
}



int main() {
    while(scanf("%lld %lld", &n, &m) != EOF) {
        Graph::clear();
        for(ll i = 1; i <= m; i++) {
            ll u, v, w;
            scanf("%lld %lld %lld", &u, &v, &w);
            Graph::add_edge(u, v, w);
            Graph::add_edge(v, u, w);
        }

        scanf("%lld %lld", &st, &ed);

        if(st == ed) {
            printf("0\n");
            continue;
        }

        Poly::solve();
    }
}