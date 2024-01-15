#include <cstdio>
#include <cstring>
#include <ctime>
#define ll long long
#define N 1010
#define M 1200000
using namespace std;
ll T;
ll n, m;

ll cnt;
ll head[N];
ll cost[M];
ll nxt[M];
ll to[M];
void addEdge(ll u, ll v, ll w) {
	++cnt;
	to[cnt] = v;
	cost[cnt] = w;
	nxt[cnt] = head[u]; 
	head[u] = cnt;
}
int main() {
//	freopen("matching.in", "r", stdin);
//	freopen("matching.out", "w", stdout);
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld %lld", &n, &m);
		memset(head, 0, sizeof head);
		cnt = 1;
		for(ll i = 1; i <= m; i++) {
			ll u, v, w;
			scanf("%lld %lld %lld", &u, &v, &w);
			addEdge(u, v, w);
			addEdge(v, u, w);
		}
		
	}
}
