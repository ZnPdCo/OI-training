#include <cstdio>
#include <chrono>
#include <random>
using namespace std;
using namespace chrono;
#define ll long long
#define N 1010
ll t, n, m;
double ti, add;
char a[N][N], b[N][N];
int main() {
	freopen("world.in", "r", stdin);
	freopen("world.out", "w", stdout);
	scanf("%lld", &t);
	add = 1.8 / t;
	auto start = system_clock::now();
	mt19937 rnd(time(0));
	for(ll _ = 1; _ <= t; _++) {
		scanf("%lld %lld", &n, &m);
		for(ll i = 1; i <= n; i++) {
			scanf("%s", a[i]+1);
		}
		for(ll i = 1; i <= n; i++) {
			scanf("%s", b[i]+1);
			for(ll j = 1; j <= m; j++) {
				if(a[i][j] == b[i][j]) a[i][j] = 0;
				else a[i][j] = 1;
			}
		}
		ti += add;
		bool flag = 0;
		while(true) {
			auto end = system_clock::now();
			auto duration = duration_cast<microseconds>(end - start);
			if(double(duration.count()) * microseconds::period::num / microseconds::period::den > ti) {
				break;
			}
			
			ll op = rnd() % 4;
			if(op == 0) {
				ll j = rnd() % m + 1;
				for(ll i = 1; i <= n; i++) {
					a[i][j] ^= 1;
				}
			} else if(op == 1) {
				ll i = rnd() % n + 1;
				for(ll j = 1; j <= m; j++) {
					a[i][j] ^= 1;
				}
			} else if(op == 2) {
				ll i = rnd() % (n+m-1) - n + 1;
				for(ll j = 1; i <= n && j <= m; i++, j++) {
					if(i > 0) a[i][j] ^= 1;
				}
			} else if(op == 3) {
				ll i = rnd() % (n+m-1) + 1;
				for(ll j = 1; i >= 1 && j <= m; i--, j++) {
					if(i <= n) a[i][j] ^= 1;
				}
			}
			
			bool ok = true;
			for(ll i = 1; i <= n; i++) {
				for(ll j = 1; j <= m; j++) {
					if(a[i][j] != 0) ok = false;
				}
			}
			if(ok) {
				flag = 1;
				break;
			}
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
}
