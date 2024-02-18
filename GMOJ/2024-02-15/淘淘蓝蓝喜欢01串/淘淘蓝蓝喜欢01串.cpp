#include <cstdio>
#include <cstring>
#define ll long long
#define N 100010
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
using namespace std;
ll T, n, a[N], L, R, tmp, ans;
char s[N];

int main() {
	freopen("str.in", "r", stdin);
	freopen("str.out", "w", stdout);
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld %s", &n, s+1);
		
		L = 1, R = 0, tmp = 1, ans = 0;
		
		for(int i = 1; i <= n; i++) {
			if(s[i] == s[i-1]) a[R]++;
			else a[++R] = 1;
		}
		
		
		while(L <= R) {
			bool bz = true;
			
			while(tmp <= R) {
				if(a[tmp] > 1) {
					a[tmp]--;
					bz = false;
					break;
				}
				tmp++;
			}
			
			if(bz) L++;
			
			if(L <= R) L++;
			if(tmp < L) tmp = L;
			
			ans++;
		}
		printf("%lld\n", ans);
	}
}
