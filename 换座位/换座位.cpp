#include <cstdio>
#include <ctime>
#include <cstring>
#include <random>
#include <algorithm>
using namespace std;
#define ll long long
const ll n = 8;
#define pwd "sx24"
ll firstSeat[n + 10];
ll nxtSeat[n + 10][n + 10];
ll isUse[n + 10][n + 10];
bool isSitWith[n + 10][n + 10];
bool isSitSeat[n + 10][n + 10];
mt19937 rnd(time(0));
int main() {
	while(true) {
		bool flag = 1;
		memset(firstSeat, 0, sizeof firstSeat);
		memset(nxtSeat, 0, sizeof nxtSeat);
		memset(isUse, 0, sizeof isUse);
		memset(isSitWith, 0, sizeof isSitWith);
		memset(isSitSeat, 0, sizeof isSitSeat);
		for(ll i = 1; i <= n; i++) {
			nxtSeat[1][i] = i;
			isSitWith[i - 1][i] = 1;
			isSitWith[i][i + 1] = 1;
			isSitSeat[i][i] = 1;
		}
		for(ll i = 2; i <= n; i++) {
			for(ll j = 1; j <= n; j++) {
				ll a[10];
				for(ll k = 1; k <= n; k++) {
					a[k] = k;
				}
				shuffle(a + 1, a + 1 + n, rnd);
				for(ll x = 1; x <= n; x++) {
					ll k = a[x];
					if(isSitSeat[j][k]) continue;
					if(j != 1 && isSitWith[k][nxtSeat[i][j - 1]]) continue;
					if(isUse[i][k]) continue;
					isSitSeat[j][k] = 1;
					isSitWith[k][nxtSeat[i][j - 1]] = 1;
					nxtSeat[i][j] = k;
					isUse[i][k] = 1;
					break;
				}
				if(nxtSeat[i][j] == 0) {
					flag = 0;
				}
			}
		}
		if(flag) break;
	}
	
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= n; j++) {
			printf("%lld ", nxtSeat[i][j]);
		}
		printf("\n");
	}
	
	for(ll i = 1; i <= n; i++) {
		firstSeat[i] = i;
	}
	shuffle(firstSeat + 1, firstSeat + 1 + n, rnd);
}
