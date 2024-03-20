#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
#define N 1010
ll h, w, n;
ll a[N], cnt;
bool v[N];
void dfs(ll x, ll y, ll z) {
	while(z <= n && (v[z] || x < a[z] || y < a[z])) {
		z++;
	}
	if(z > n) return;
	v[z] = 1;
	dfs(x - a[z], a[z], z + 1);
	dfs(a[z], y - a[z], z + 1);
	dfs(x - a[z], y - a[z], z + 1);
}
int main() {
	scanf("%lld %lld %lld", &h, &w, &n);
	for(ll i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		a[i] = 1ll << a[i];
	}
	sort(a + 1, a + 1 + n, [&](const auto &x, const auto &y) {
		return x > y;
	});
	dfs(h, w, 1);
	bool flag = 1;
	for(ll i = 1; i <= n; i++) {
		if(!v[i]) {
			flag = 0;
			break;
		}
	}
	if(flag) printf("Yes");
	else printf("No");
}
