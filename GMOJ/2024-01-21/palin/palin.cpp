#include <cstdio>
#include <cstring>
#define ll long long
#define N 1000010
ll t, n;
ll a[N];
ll pos[N][2];
ll l1, r1, l2, r2;
bool flag;
char ans[N];

void fun(ll x) {
	if(x > n) {
		flag = true;
		return;
	}
	// 尽量先取左端点
	if(l1+1 <= r1 && a[l1] == a[r1]) {
		r1--;
		l1++;
		ans[x] = 'L';
		ans[2*n-x+1] = 'L';
	} else if(l1 <= r1 && l2 <= r2 && a[l1] == a[l2]) {
		l2++;
		l1++;
		ans[x] = 'L';
		ans[2*n-x+1] = 'R';
	} else if(l1 <= r1 && l2 <= r2 && a[r2] == a[r1]) {
		r1--;
		r2--;
		ans[x] = 'R';
		ans[2*n-x+1] = 'L';
	} else if(l2+1 <= r2 && a[r2] == a[l2]) {
		l2++;
		r2--;
		ans[x] = 'R';
		ans[2*n-x+1] = 'R';
	} else {
		flag = false;
		return;
	}

	fun(x+1);
}

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%lld", &t);
	while(t--) {
		memset(pos, 0, sizeof pos);
		scanf("%lld", &n);
		for(ll i = 1; i <= 2*n; i++) {
			scanf("%lld", &a[i]);
			if(pos[a[i]][0]) pos[a[i]][1] = i;
			else pos[a[i]][0] = i;
		}



		// 第一步走左端点
		l1 = 2, r1 = pos[a[1]][1]-1, l2 = pos[a[1]][1]+1, r2 = 2*n;
		ans[1] = 'L';
		fun(2);

		if(flag == false) {
			// 第一步走右端点
			l1 = 1, r1 = pos[a[2*n]][0]-1, l2 = pos[a[2*n]][0]+1, r2 = 2*n-1;
			ans[1] = 'R';
			fun(2);
			if(flag == false) {
				printf("-1\n");
				continue;
			}
		}
		ans[2*n] = 'L';
		ans[2*n+1] = '\0';
		printf("%s\n", ans+1);
	}
}
