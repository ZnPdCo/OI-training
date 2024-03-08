#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
#define N 100010 
#define inf 1e18
ll T;
ll n, k, X, Y, m;
struct node {
	ll x, y;
} a[N], s[N];
inline ll calc1(ll x, ll y) {
	if(x <= 0) return -1;			// 已满足 
	else if(y == 0) return inf;		// 永不满足
	else return x / y;				// 可满足 
}
inline ll calc2(ll x, ll y, ll l, ll r) {
	if(l < 0) l = 0;
	if(r < 0) r = -1;
	if(l > r) return inf;
	if(y > 0) {
		ll res;
		if(x <= 0) res = 0;
		else res = (x+y-1)/y;
		if(res > r) return inf;
		if(res < l) return l;
		return res;
	} else {
		if(l * y >= x) return l;
		return inf;
	}
}
int main() {
//	freopen("wind3.in", "r", stdin);
//	freopen("wind3.out", "w", stdout);
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld %lld %lld %lld", &n, &k, &X, &Y);
		m = inf;
		for(ll i = 1; i <= n; i++) {
			scanf("%lld %lld", &a[i].x, &a[i].y);
			s[i].x = s[i-1].x + a[i].x;
			s[i].y = s[i-1].y + a[i].y;
		}
		if(X == 0 && Y == 0) {
			printf("0\n");
			continue; 
		}
		for(ll i = 0; i < n; i++) {
			ll x = X - s[i].x, y = Y - s[i].y, xx = s[n].x, yy = s[n].y;
			if(xx < 0) xx *= -1, x *= -1;
			if(yy < 0) yy *= -1, y *= -1;
			ll pos1 = calc1(x, xx), pos2 = calc1(y, yy);
			if(pos1 > pos2) swap(pos1, pos2), swap(x, y), swap(xx, yy);	// x-xx 会先变为 0 
			
			ll res = min({calc2(x+y-i*k, xx+yy+n*k, 0, pos1), 
				calc2(-x+y-i*k, -xx+yy+n*k, pos1+1, pos2),
				calc2(-x-y-i*k, -xx-yy+n*k, pos2+1, inf)});
			
			if(res != inf) m = min(m, res * n + i);
		}
		if(m == inf) printf("-1\n");
		else printf("%lld\n", m);
	}
} 
