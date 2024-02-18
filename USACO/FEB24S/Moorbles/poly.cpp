#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
#define M 300010
ll mxe[M], mxo[M], mne[M], mno[M];
ll t, n, m, k, a;
ll f[M], ans[M], mn[M];
bool flag;
int main() {
	scanf("%lld", &t);
	while(t--) {
		memset(f, 0, sizeof f);
		flag = true;
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
		for(ll s = 0; s < (1<<m); s++) {
			ll tmp = n;
			for(ll i = 1; i <= m; i++) {
				if(s & (1<<(m-i))) {
					if(mxo[i] == 0) {	// 全是偶数
						tmp -= mxe[i];
					} else if(mxe[i] == 0) {// 全是奇数
						tmp += mno[i];
					} else {
						tmp -= mxe[i];
					}
				} else {
					if(mxo[i] == 0) {	// 全是偶数
						tmp += mne[i];
					} else if(mxe[i] == 0) {// 全是奇数
						tmp -= mxo[i];
					} else {
						tmp -= mxo[i];
					}
				}
				if(tmp <= 0) break;
			}
			if(tmp > 0) {
				flag = false;
				for(ll i = 1; i < m; i++) {
					if(s & (1<<(m-i))) printf("Odd ");
					else printf("Even ");
				}
				if(s & 1) printf("Odd");
				else printf("Even");
				printf("\n");
				break;
			}
		}
		if(flag) printf("-1\n");
	}
}
