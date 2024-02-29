#include <bits/stdc++.h>
#include <testlib.h>
using namespace std;
#define ll long long
#define N 1000010
ll head[N], nxt[2*N], to[2*N], type[2*N], cnt;
ll dad[N];
bool vis[N];
ll n, m, a, b, rt;

void addEdge(ll u, ll v, ll ty) {
	cnt++;
	to[cnt] = v;
	type[cnt] = ty;
	nxt[cnt] = head[u];
	head[u] = cnt;
}
ll aa, bb;
void dfs(ll u, ll fa) {
	vis[u] = 1;
	for(ll i = head[u]; i; i = nxt[i]) {
		ll v = to[i], ty = type[i];
		if(v == fa) continue;
		if(ty == 0) {
			if(vis[v]) aa++;
			else bb++;
		} else {
			dfs(v, u);
		}
	}
	vis[u] = 0;
}
int main(int argc, char *argv[]) {
	registerTestlibCmd(argc, argv);
	
	ll t = inf.readLong();
	for(ll _ = 1; _ <= t; _++) {
		n = inf.readLong(), m = inf.readLong(), a = inf.readLong(), b = inf.readLong(), rt = inf.readLong();
		aa = bb = 0;
		for(ll i = 1; i <= n; i++) {
			head[i] = 0;
		}
		cnt = 0;
		for(ll i = 1; i <= n; i++) {
			dad[i] = ouf.readLong();
		}
		for(ll i = 1; i <= m; i++) {
			ll u = inf.readLong(), v = inf.readLong();
			if(dad[u] == v || dad[v] == u) {
				addEdge(u, v, 1);
				addEdge(v, u, 1);
			} else {
				addEdge(u, v, 0);
				addEdge(v, u, 0);
			}
		}
		dfs(rt, 0);
		bb -= aa;
		bb /= 2;
		if(a == aa && b == bb) {
		} else {
			quitf(_wa, "%lld wa expected:a=%lld b=%lld,but found:a=%lld,b=%lld|%lld %lld %lld %lld %lld\n", _,a,b,aa,bb,n,m,a,b,rt);
		}
	}
	quitf(_ok, "ac");
}
