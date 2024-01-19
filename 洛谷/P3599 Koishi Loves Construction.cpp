#include <cstdio>
#include <cstring>
#define ll long long
ll x, t;
ll n;
ll s;

bool v[110];
ll a[110];

void dfs(ll x) {
	if(x > n) {
		ll s = 1;
		bool vis[110] = {0};
		for(ll i = 1; i <= n; i++) {
			(s *= a[i]) %= n;
			if(vis[s]) return;
			vis[s] = 1;
		}
		for(ll i = 1; i <= n; i++) {
			printf("%lld ", a[i]);
		}
		printf("\n");
		return;
	}
	for(ll i = 1; i <= n; i++) if(!v[i]) {
		v[i] = 1;
		a[x] = i;
		dfs(x+1);
		v[i] = 0;
	}
}

int main() {
	scanf("%lld %lld", &x, &t);
	while(t--) {
		scanf("%lld", &n);
		if(x == 1) {
			dfs(1);
		}
	}
}

/*
#include <cstdio>
#include <cstring>
#define ll long long
ll x, t;
ll n;
ll s;

int main() {
	scanf("%lld %lld", &x, &t);
	while(t--) {
		scanf("%lld", &n);
		if(x == 1) {
			if(n == 1) printf("2 1\n");
			else if(n % 2 == 1) printf("0\n");
			else {
				printf("2 %lld ", n);
				for(ll i = n - 1; i >= 3; i -= 2) {
					printf("%lld %lld ", i, n+1-i);
				}
				printf("1\n");
			}
		} else {
			if(n == 1) printf("2 1\n");
			else printf("0\n");
		}
	}
}

*/
