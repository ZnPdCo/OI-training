/**
 * @file 排水系统.cpp 
 * @tag: #GMOJ#拓扑
 * @author: ZnPdCo
 * @date: 2024-01-18 20:43:55
 * @problem: https://gmoj.net/senior/#main/show/6922
 **/
#include <cstdio>
#include <queue>
#define ll long long
#define uint128 unsigned __int128
#define N 100010
using namespace std;
uint128 gcd(uint128 a, uint128 b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}
uint128 lcm(uint128 a, uint128 b) {
	return a / gcd(a, b) * b;
}
struct frac {
	uint128 mom, son;
	void fun() {
		uint128 g = gcd(mom, son);
		mom /= g;
		son /= g;
	}
	friend frac operator +(const frac &x, const frac &y) {
		frac z;
		z.mom = lcm(x.mom, y.mom);
		z.son = z.mom / x.mom * x.son + z.mom / y.mom * y.son;
		z.fun();
		return z;
	}
	friend frac operator /(const frac &x, const ll &y) {
		frac z;
		z.mom = x.mom * y;
		z.son = x.son;
		z.fun();
		return z;
	}
} a[N];
ll n, m;
ll num[N];

ll head[N];
ll nxt[10*N];
ll to[10*N], cnt;
ll rd[N];

void addEdge(ll u, ll v) {
	cnt++;
	to[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
	rd[v]++;
	
}
void print(uint128 x) {
	if(x >= 10) print(x / 10);
	putchar(x % 10 + '0');
}
int main() {
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for(ll i = 1; i <= n; i++) {
		a[i].mom = 1;
		scanf("%lld", &num[i]);
		for(ll j = 1; j <= num[i]; j++) {
			ll v;
			scanf("%lld", &v);
			addEdge(i, v);
		}
	}
	
	queue<ll> que;
	for(ll i = 1; i <= m; i++) {
		que.push(i);
		a[i].son = 1;
	}
	
	while(!que.empty()) {
		ll u = que.front();
		que.pop();
		for(ll i = head[u]; i; i = nxt[i]) {
			ll v = to[i];
			
			a[v] = a[v] + a[u] / num[u];
			
			rd[v]--;
			if(!rd[v]) {
				que.push(v);
			}
		}
	}
	
	for(ll i = 1; i <= n; i++) {
		if(num[i] == 0) {
			print(a[i].son);
			putchar(' ');
			print(a[i].mom);
			putchar('\n');
		}
	}
}
