#include <cstdio>
#include <queue>
using namespace std;
#define N 110
#define M 32
#define K 8
#define P 1000000007
int n, m, k, cnt, ans;
char s[M];
int can[M];
int f[2][1<<K][N*M];
int nxt[N*M][26];
int tail[N*M];
int fail[N*M];
bool vis[26];
void insert(int x) {
	int p = 0;
	for(int i = 1; s[i] != '\0'; i++) {
		if(!nxt[p][s[i]-'a']) {
			nxt[p][s[i]-'a'] = ++cnt;
		}
		p = nxt[p][s[i]-'a'];
	}
	tail[p] |= (1 << x);
}
void build() {
	queue<int> q;
	for(int i = 1; i <= m; i++) 
		if(nxt[0][can[i]]) q.push(nxt[0][can[i]]);
	while(!q.empty()) {
		int p = q.front();
		q.pop();
		tail[p] |= tail[fail[p]];
		for(int i = 1; i <= m; i++) {
			if(nxt[p][can[i]]) {
				fail[nxt[p][can[i]]] = nxt[fail[p]][can[i]];
				q.push(nxt[p][can[i]]);
			} else {
				nxt[p][can[i]] = nxt[fail[p]][can[i]];
			}
		}
	}
}
int main() {
	scanf("%d %d", &n, &k);
	for(int i = 0; i < k; i++) {
		scanf("%s", s+1);
		insert(i);
	}
	scanf("%d", &m);
	m = 0;
	scanf("%s", s+1);
	for(int i = 1; s[i] != '\0'; i++) {
		if(!vis[s[i]-'a']) {
			vis[s[i]-'a'] = 1;
			can[++m] = s[i]-'a';
		}
	}
	build();
	f[0][0][0] = 1;
	for(int i = 0; i < n; i++) {
		for(int s = 0; s < (1<<k); s++) {
			for(int p = 0; p <= cnt; p++) {
				f[(i+1) % 2][s][p] = 0;
			}
		}
		for(int s = 0; s < (1<<k); s++) {
			for(int p = 0; p <= cnt; p++) {
				if(!f[i%2][s][p]) continue;
				for(int j = 1; j <= m; j++) {
					int pp = nxt[p][can[j]];
					(f[(i+1) % 2][s | tail[pp]][pp] += f[i%2][s][p]) %= P;
				}
			}
		}
	}
	for(int i = 0; i <= cnt; i++) {
		(ans += f[n%2][(1<<k)-1][i]) %= P;
	}
	printf("%d", ans);
}
