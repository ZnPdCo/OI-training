#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
#define N 100010
ll t, n, m, fir, ans1, ans2;
struct node {
	ll a, b;
} a[N];
int main() {
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld %lld", &n, &m);
		for(ll i = 1; i <= n; i++) {
			scanf("%lld %lld", &a[i].a, &a[i].b);
		}
		sort(a+1, a+1+n, [](const auto &x, const auto &y) {return x.a < y.a;});
		fir = 0;
		ans1 = ans2 = 0;
		for(ll i = 1; i <= n; i++) {
			if(a[i].a > m) break;
			if(a[i].b) {
				fir = i;
				break;
			}
		}
		if(fir) {
			ans1 = a[fir].b + 1, ans2 = a[fir].a;
			for(ll i = fir+1; i <= n; i++) {
				ans1 += a[i].b;
			}
		}
		if(ans1 >= n) {
			printf("%lld %lld\n", n, ans2);
		} else {
			for(ll i = 1; i <= n; i++) if(i != fir) {
				if(ans2 + a[i].a > m || ans1 >= n) break;
				ans1++, ans2 += a[i].a;
			}
			printf("%lld %lld\n", ans1, ans2);
		}
	}
}
