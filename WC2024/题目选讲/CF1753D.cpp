#include <cstdio>
#include <vector>
#include <string>
#include <queue>
using namespace std;
#define N 300010
#define ll long long
#define a(x,y) ((x)*m+(y))

ll n, m, p, q, ans = 1e15;
char s[N];
ll dis[N];
bool vis[N];

ll head[N];
ll nxt[N*10], to[N*10], cost[N*10], cnt;

priority_queue<pair<ll, ll> > que;

void addEdge(ll u, ll v, ll w) {
    cnt++;
    to[cnt] = v;
    cost[cnt] = w;
    nxt[cnt] = head[u];
    head[u] = cnt;
}


int main() {
    scanf("%lld%lld%lld%lld", &n, &m, &p, &q);
    for(ll i = 0; i < n; i++) {
        scanf("%s", s);
        for(ll j = 0; j < m; j++) {
            if(s[j] == '.') dis[a(i, j)] = 0;
            else dis[a(i, j)] = 1e15;

            if(s[j] == 'U') {
                if(i+1<n&&j-1>=0) addEdge(a(i+1, j-1), a(i, j), p);
                if(i+1<n&&j+1<m) addEdge(a(i+1, j+1), a(i, j), p);
                if(i+2<n) addEdge(a(i+2, j), a(i, j), q);
            } else if(s[j] == 'D') {
                if(i-1>=0&&j-1>=0) addEdge(a(i-1, j-1), a(i, j), p);
                if(i-1>=0&&j+1<m) addEdge(a(i-1, j+1), a(i, j), p);
                if(i-2>=0) addEdge(a(i-2, j), a(i, j), q);
            } else if(s[j] == 'L') {
                if(i-1>=0&&j+1<m) addEdge(a(i-1, j+1), a(i, j), p);
                if(i+1<n&&j+1<m) addEdge(a(i+1, j+1), a(i, j), p);
                if(j+2<m) addEdge(a(i, j+2), a(i, j), q);
            } else if(s[j] == 'R') {
                if(i-1>=0&&j-1>=0) addEdge(a(i-1, j-1), a(i, j), p);
                if(i+1<n&&j-1>=0) addEdge(a(i+1, j-1), a(i, j), p);
                if(j-2>=0) addEdge(a(i, j-2), a(i, j), q);
            }
        }
    }

    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            if(dis[a(i, j)] == 0) que.push(make_pair(0, a(i, j)));
        }
    }


    while(!que.empty()) {
        ll u = que.top().second;
        que.pop();
        if(vis[u]) continue;
        vis[u] = 1;

        for(ll i = head[u]; i; i = nxt[i]) {
            ll v = to[i], w = cost[i];
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                que.push(make_pair(-dis[v], v));
            }
        }
    }

    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            if(j+1 < m) ans = min(ans, dis[a(i, j)] + dis[a(i, j+1)]); 
            if(i+1 < n) ans = min(ans, dis[a(i, j)] + dis[a(i+1, j)]); 
            // printf("%lld ", dis[a(i, j)]);
        }
        // printf("\n");
    }
    if(ans == 1e15) printf("-1");
    else printf("%lld", ans);
}