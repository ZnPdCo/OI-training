#include <cstdio>
#include <cstring>
#define ll long long
#define N 110
#define M 1000010

bool f[2][N];

char t[N], s[M];
ll from[N], stk[N], top;
ll n, m, q;
int main() {
	freopen("walking.in", "r", stdin);
	freopen("walking.out", "w", stdout);
	scanf("%s", t+1);
	n = strlen(t+1);
	
	for(ll i = 1; i <= n; i++) {
		if(t[i] == '[') {
			stk[++top] = i;
		} else if(t[i] == ']') {
			from[i] = stk[top--];
		}
	}
	
	scanf("%lld", &q);
	while(q--) {
		scanf("%s", s+1);
		m = strlen(s+1);
		__builtin_memset(f, 0, sizeof f);
		for(ll i = 0; i <= m; i++) {
			ll now = i & 1, lst = now ^ 1;
			__builtin_memset(f[now], 0, sizeof f[now]);
			if(i == 0) f[0][0] = 1;
			for(ll j = 1; j <= n; j++) {
				if(t[j] == '[') {
					f[now][j] |= f[now][j-1];
				}
				if(t[j] == ']') {
					f[now][j] |= f[now][from[j]];
					f[now][j] |= f[now][j-1];
				}
				if(t[j] == '?' || s[i] == t[j]) {
					f[now][j] |= f[lst][j-1];
				}
				if(t[j] == '*') {
					f[now][j] |= f[now][j-1];
					f[now][j] |= f[lst][j];
				}
//				printf("f[%lld][%lld]=%d\n", i, j, f[now][j]);
			}
			if(i) printf("%d", f[now][n]);
		}
		printf("\n");
	}
}
