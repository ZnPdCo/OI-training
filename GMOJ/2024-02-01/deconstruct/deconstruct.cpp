#include <cstdio>
#include <cstring>
#define P 1000000007
#define N 2000010
int n;
long long ans;

int cnt;
int head[N];
int nxt[N], to[N];
int inv[N];

inline void addEdge(int u, int v) {
	cnt++;
	to[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
}

int siz[N], fa;

void dfs(int u, int dep) {
	siz[u] = 1;
	for(int i = head[u]; i; i = nxt[i]) {
		int v = to[i];
		dfs(v, dep+1);
		siz[u] += siz[v];
	}
	if(dep) {
		(ans += (long long)(siz[u]) * (long long)(inv[dep]) % P) %= P;
	}
}


inline char get() { static char buf[100000], *p1 = buf, *p2 = buf; return p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,100000,stdin),p1 == p2) ? EOF : *p1 ++; }
inline int read() {
	int x = 0;
	char c = '.';
	while(c < '0' || c > '9') c = get();
	while(c >= '0' && c <= '9') {
		x = (x<<1) + (x << 3) + (c ^ '0');
		c = get();
	}
	return x;
}

int main() {
	freopen("deconstruct.in", "r", stdin);
	freopen("deconstruct.out", "w", stdout);
	n = read();
	for(int i = 2; i <= n; i++) {
		fa = read();
		addEdge(fa, i);
	}
	
	inv[1] = 1;
	for(int  i = 2; i <= n; i++) {
		inv[i] = (((long long)(-P)/(long long)i+P)%P+P)%P * inv[P%i] % P;
	}
	dfs(1, 0);
	printf("%lld", ans);
}
