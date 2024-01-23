#include <cstdio>
#define ll long long
#define N 100010
#define P 1000000007
ll n, k;
ll a[N];
ll v[N];
ll mx, num;
void dfs(ll x) {
    if(x > n) {
        ll ans = 0;
        for(ll i = 1; i <= k; i++) {
            if(v[i] == -1) return;
            ans += v[i];
        }
        if(ans > mx) mx = ans, num=1;
        else if(ans == mx) num++;
        return;
    }
    for(ll i = 1; i <= k; i++) {
        ll tmp = v[i];
        if(v[i] == -1) v[i] = a[x];
        else v[i] &= a[x];
        dfs(x+1);
        v[i] = tmp;
    }
}
int main() {
    scanf("%lld %lld", &n, &k);
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        v[i] = -1;
    }
    dfs(1);
    printf("%lld %lld", mx, num);
}