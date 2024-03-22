#include <cstdio>
#include <cassert>
#include <cmath>
#define ll long long
#define N 1000010
ll n, a[N], s[N], g[N], ans = 1;
char c[N];
bool flag;
ll sig(ll x) {
    return x > 0 ? 1 : (x < 0 ? -1 : 0);
}
int main() {
    scanf("%lld %s", &n, c + 1);
    for(ll i = 1; i <= n; i ++) {
        if(c[i] == 'A') a[i] = 1;
        if(c[i] == 'B') a[i] = -1;
        s[i] = s[i - 1] + a[i];
    }
    for(ll i = 1; i <= n - 1; i++) {
        if(sig(s[i]) != sig(s[i + 1] - s[1])) {
            ans ++;
        }
    }
    printf("%lld", ans);
}