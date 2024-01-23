#include <cstdio>
#define ll long long
#define N 110
ll n;
ll f[N], w[N], g[N];
int main() {
    scanf("%lld", &n);
    for(ll i = 2; i <= n; i++) {
        scanf("%lld", &f[i]);
    }
    for(ll i = 2; i <= n; i++) {
        scanf("%lld", &w[i]);
    }
    for(ll i = 2; i <= n; i++) {
        scanf("%lld", &g[i]);
    }
}