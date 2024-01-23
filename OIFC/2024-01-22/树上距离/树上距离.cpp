#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define N 110
#define P 1000000007
ll n;
ll a[N];
ll dis[N][N];
bool v[N];
ll T;
ll mn = 1e15;
void dfs(ll x) {
    if(x > n) {
        ll ans = 0;
        for(ll i = 1; i <= n; i++) {
            ans += dis[a[i]][a[i % n + 1]];
        }
        mn = min(mn, ans);
        return;
    }
    for(ll i = 1; i <= n; i++) if(!v[i]) {
        v[i] = 1;
        a[x] = i;
        dfs(x+1);
        v[i] = 0;
    }
}

ll head[N];
ll cost[2*N];
ll nxt[2*N];
ll to[2*N], cnt;
void addEdge(ll u, ll v, ll w) {
    cnt++;
    cost[cnt] = w;
    to[cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt;
}
void dfs1(ll u, ll fa, ll t) {
    for(ll i = head[u]; i; i = nxt[i]) {
        ll v = to[i];
        if(v == fa) continue;
        dis[t][v] = dis[t][u] + cost[i];
        dfs1(v, u, t);
    }
}

int main() {
    scanf("%lld", &T);
    while(T--) {
        memset(head, 0, sizeof head);
        memset(dis, 0, sizeof dis);
        cnt = 0;
        mn = 1e15;
        scanf("%lld", &n);
        for(ll i = 1; i < n; i++) {
            ll u, v, w;
            scanf("%lld %lld %lld", &u, &v, &w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        for(ll i = 1; i <= n; i++) {
            dfs1(i, 0, i);
        }
        dfs(1);
        printf("%lld\n", mn);
    }
}