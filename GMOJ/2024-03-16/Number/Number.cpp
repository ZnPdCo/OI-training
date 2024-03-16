#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e9
#define N 110
#define M 10
#define K 15
ll n, ans;
char s[N];

ll nxt[N*M][10], fail[N*M], tail[N*M], cnt;

ll f[N][N*M];


void insert() {
	ll p = 0;
	for(ll i = 1; s[i] != '\0'; i ++) {
		if(!nxt[p][s[i]-'0']) {
			nxt[p][s[i]-'0'] = ++ cnt;
			tail[cnt] = inf;
		}
		p = nxt[p][s[i]-'0'];
	}
	tail[p] = min(tail[p], (ll)strlen(s + 1));
}
void build() {
	queue<ll> que;
	for(ll i = 0; i <= 9; i++) if(nxt[0][i]) que.push(nxt[0][i]);
	while(!que.empty()) {
		ll p = que.front();
		que.pop();
		tail[p] = min(tail[p], tail[fail[p]]);
		for(ll i = 0; i <= 9; i++) {
			if(nxt[p][i]) {
				fail[nxt[p][i]] = nxt[fail[p]][i];
				que.push(nxt[p][i]);
			} else {
				nxt[p][i] = nxt[fail[p]][i];
			}
		}
	}
}
inline bool ok(ll st, ll ed) {
	if(1 <= st && ed <= 4) return true;
	if(4 <= st && 4 <= ed && ed <= 7) return true;
	if(5 <= st && 5 <= ed && ed <= 8) return true;
	if(7 <= st && 7 <= ed && ed <= 11) return true;
	return false;
}

int main() {
	tail[0] = 1e15;
	scanf("%lld", &n);
	for(ll i = 1; i <= n; i++) {
		scanf("%s", s+1);
		insert();
	}
	build();
	f[1][nxt[0][1]] = 1;
	if(tail[nxt[0][1]] == 1) return printf("0"), 0;
	for(ll i = 1; i < 11; i ++) {
		for(ll j = 0; j <= cnt; j ++) {
			if(!f[i][j]) continue;
			for(ll k = 0; k <= 9; k ++) {
				ll p = nxt[j][k];
				if(!ok(i + 1 - tail[p] + 1, i + 1)) {
					f[i + 1][p] += f[i][j];
				}
			}
		}
	}
	for(ll i = 0; i <= cnt; i ++) {
		ans += f[11][i];
	}
	printf("%lld", ans);
}
