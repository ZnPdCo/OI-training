#include <cstdio>
#include <cstring>
using namespace std;
#define N 200010
#define ll long long
ll T, n, m;
ll s[N];
bool v[N];
ll fa[N];
ll find(ll x) {
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
int main() {
    freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);
    scanf("%lld", &T);
    while(T--) {
        scanf("%lld %lld", &n, &m);
        for(ll i = 1; i <= m; i++) {
            scanf("%lld", &s[i]);
        }
        if(n <= 100000 && m <= 10) {
            memset(v, 0, sizeof v);
            for(ll i = 1; i <= n; i++) {
                fa[i] = i;
            }
            for(ll i = 1; i <= n; i++) {
                for(ll j = 1; j <= m; j++) {
                    if(i + s[j] <= n) fa[find(i)] = find(i+s[j]);
                    if(i - s[j] >= 1) fa[find(i)] = find(i-s[j]);
                }
            }
            ll ans = 0;
            for(ll i = 1; i <= n; i++) {
                if(!v[find(i)]) {
                    v[find(i)] = 1;
                    ans++;
                }
            }
            printf("%lld\n", ans);
        } else if(m >= 1000) {
            printf("1\n");
        }
    }

}