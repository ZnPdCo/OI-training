#include <cstdio>
#define ll long long
ll n, m, ans;
ll a[100][100];
ll k1[100];
ll k2[100];
ll s1[100];
ll s2[100];
bool flag;
void dfs3(ll z) {
	if(z > n + m - 2) {
//		if(a[2][0] == 0 && k1[1]==0 && k1[2] == 1 && k1[3]==1 && k1[4]==0 &&
//			k2[1]==0 && k2[2]==0 && k2[3]==1 && k2[4]==1) {
//			printf("x");
//		}
		for(ll i = 1; i <= n+m-2; i++) {
			if(k1[i] > k2[i]) break;
			if(k1[i] < k2[i]) return;
		}
		ll x1=0, x2=0, y1=0, y2=0;
		s1[0] = a[0][0];
		s2[0] = a[0][0];
		for(ll i = 1; i <= n+m-2; i++) {
			if(k1[i] == 1) y1++;
			else x1++;
			if(k2[i] == 1) y2++;
			else x2++;
			if(x1 >= n) return;
			if(x2 >= n) return;
			if(y1 >= m) return;
			if(y2 >= m) return;
			s1[i] = a[x1][y1];
			s2[i] = a[x2][y2];
		}
		for(ll i = 0; i <= n+m-2; i++) {
			if(s1[i] < s2[i]) break;
			if(s1[i] > s2[i]) {
				if(a[0][0] == 1 && a[0][1] == 1 && a[0][2] == 1 && 
					a[1][0] == 1 && a[1][1] == 1 && a[1][2] == 0 && 
					a[2][0] == 1 && a[2][1] == 1 && a[2][2] == 0) {
//					printf("x");
				}
				flag = false;
				return;
			}
		}
		return;
	}
	k2[z] = 1;	// r
	dfs3(z+1);
	k2[z] = 0;	// d
	dfs3(z+1);
}
void dfs2(ll z) {
	if(z > n + m - 2) {
		dfs3(1);
		return;
	}
	k1[z] = 1;	// r
	dfs2(z+1);
	k1[z] = 0;	// d
	dfs2(z+1);
}
void dfs(ll z) {
	if(z >= n * m) {
		flag = true;
		dfs2(1);
		ans += flag;
		return;
	}
	a[z / m][z % m] = 1;
	dfs(z+1);
	a[z / m][z % m] = 0;
	dfs(z+1);
}
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	dfs(0);
	printf("%lld", ans);
}
