#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
#define M 300010
ll mxe[M], mxo[M], mne[M], mno[M];
ll t, n, m, k, a;
ll f[M], ans[M], mx, g[M];
int main() {
	scanf("%lld", &t);
	while(t--) {
		memset(f, 0, sizeof f);
		memset(g, 0, sizeof g);
		memset(ans, 0, sizeof ans);
		mx = 0;
		scanf("%lld %lld %lld", &n, &m, &k);
		for(ll i = 1; i <= m; i++) {
			mxe[i] = mxo[i] = 0;
			mne[i] = mno[i] = 1e9;
			for(ll j = 1; j <= k; j++) {
				scanf("%lld", &a);
				if(a % 2 == 0) {
					mxe[i] = max(mxe[i], a);
					mne[i] = min(mne[i], a);
				} else {
					mxo[i] = max(mxo[i], a);
					mno[i] = min(mno[i], a);
				}
			}
		}
		for(ll i = m; i >= 1; i--) {
			f[i] = f[i+1];
			if(mxo[i] == 0) {	// 全是偶数
				f[i] += mne[i];	// 猜偶数一定会赢，保险起见加上最小的
			} else if(mxe[i] == 0) {// 全是奇数
				f[i] += mno[i];	// 猜奇数一定会赢，保险起见加上最小的
			} else if(mxo[i] < mxe[i]) {// 猜奇数有可能输的更大
				f[i] -= mxo[i];	// 猜偶数，保险起见减去最大的
			} else {			// 猜偶数有可能输的更大
				f[i] -= mxe[i];	// 猜奇数，保险起见减去最大的
			}
		}
		
		for(ll i = m; i >= 1; i--) {
			mx = max(mx, f[i]);
			g[i] = f[i] - mx;
		}
		
		for(ll i = 1; i <= m; i++) {
			if(mxo[i] == 0) {	// 全是偶数
				n += mne[i];	// 猜偶数一定会赢，保险起见加上最小的
				ans[i] = 0;
			} else if(mxe[i] == 0) {// 全是奇数
				if(n - mxo[i] + g[i+1] > 0) {	// 这次猜偶数还是能赢，字典序最小
					n -= mxo[i];
					ans[i] = 0;
				} else {
					n += mno[i];	// 猜奇数一定会赢，保险起见加上最小的
					ans[i] = 1;
				}
			} else if(mxo[i] < mxe[i]) {// 猜奇数有可能输的更大
				n -= mxo[i];	// 猜偶数，保险起见减去最大的
				ans[i] = 0;
			} else {			// 猜偶数有可能输的更大
				if(n - mxo[i] + g[i+1] > 0) {	// 这次猜偶数还是能赢，字典序最小
					n -= mxo[i];
					ans[i] = 0;
				} else {
					n -= mxe[i];	// 猜奇数，保险起见减去最大的
					ans[i] = 1;
				}
			}
			
			if(n <= 0) {
				printf("-1\n");
				break;
			}
		}
		
		if(n > 0) {
			for(ll i = 1; i < m; i++) {
				if(ans[i] == 0) printf("Even ");
				else printf("Odd ");
			}
			if(ans[m] == 0) printf("Even");
			else printf("Odd");
			printf("\n");
		}
	}
}
