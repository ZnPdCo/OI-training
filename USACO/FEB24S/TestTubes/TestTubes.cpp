#include <cstdio>
#include <cstring>
#define ll long long
#define N 100010
ll t;
ll n, p, k[4];
char s[4][N];
ll ans[2*N][3], cnt;
void mov(ll x, ll y) {
	ans[++cnt][1] = x;
	ans[cnt][2] = y;
	if(s[x][k[x]] == s[y][k[y]]) k[x]--;
	else s[y][++k[y]] = s[x][k[x]--];
}
int main() {
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld %lld %s %s", &n, &p, s[1]+1, s[2]+1);
		k[1] = k[2] = k[3] = cnt = 0;
		for(ll i = 1; i <= n; i++) {
			if(s[1][i] != s[1][i-1]) s[1][++k[1]] = s[1][i];
			if(s[2][i] != s[2][i-1]) s[2][++k[2]] = s[2][i];
		}
		while(k[1] != 1 || k[2] != 1 || k[3] != 0) {
			if(!k[1] && k[2] >= 2) {
				mov(2, 1);
			} else if(k[1] >= 2 && !k[2]) {
				mov(1, 2);
			} else if(!k[1] && k[2] == 1) {
				mov(3, 1);
			} else if(k[1] == 1 && !k[2]) {
				mov(3, 2);
			} else if(k[1] == 1 && k[2] == 1 && k[3] == 1) {
				if(s[1][k[1]] == s[3][k[3]]) {
					mov(3, 1);
				} else {
					mov(3, 2);
				}
			} else if(s[1][k[1]] == s[2][k[2]]) {
				if(k[1] > k[2]) {
					mov(1, 2);
				} else {
					mov(2, 1);
				}
			} else if(!k[3]) {
				if(k[1] > k[2]) {
					mov(1, 3);
				} else {
					mov(2, 3);
				}
			} else {
				if(s[1][k[1]] == s[3][k[3]]) {
					mov(1, 3);
				} else {
					mov(2, 3);
				}
			}
		}
		printf("%lld\n", cnt);
		if(p != 1) {
			for(ll i = 1; i <= cnt; i++) {
				printf("%lld %lld\n", ans[i][1], ans[i][2]);
			}
		}
	}
	return 0;
}
