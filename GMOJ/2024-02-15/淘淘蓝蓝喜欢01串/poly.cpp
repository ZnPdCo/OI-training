#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
#define N 20
ll T, n, a[N], ans;
char s[N];
bool flag[N];
ll c[N];
void dfs(ll x) {
	bool bz = true;
	for(ll i = 1; i <= n; i++) {
		if(!flag[i]) bz = false; 
	}
	if(bz) {
		ans = max(ans, x - 1);
		return;
	}
	
	for(ll i = 1; i <= n; i++) {
		if(!flag[i]) {
			ll f[N];
			for(ll j = 1; j <= n; j++) f[j] = flag[j];
			flag[i] = 1;
			ll co = -1;
			for(ll j = 1; j <= n; j++) {
				if(!flag[j]) {
					co = s[j];
					break;
				}
			}
			for(ll j = 1; j <= n; j++) {
				if(!flag[j]) {
					if(s[j] == co) flag[j] = 1;
					else break;
				}
			}
			c[x] = i;
			dfs(x+1);
			for(ll j = 1; j <= n; j++) flag[j] = f[j];
		}
	}
}
int main() {
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld", &n);
		scanf("%s", s+1);
		ans = 0;
		dfs(1);
		printf("%lld\n", ans);
	}
}
