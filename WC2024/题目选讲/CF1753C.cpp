#include <cstdio>
#define ll long long
#define P 998244353
#define N 200010
ll T, n, a[N], x, y, ans;
ll qpow(ll n, ll m) {
    if(m == 0) return 1;
    if(m % 2 == 1) return n * qpow(n, m-1) % P;
    ll tmp = qpow(n, m/2);
    return tmp * tmp % P;
}
int main() {
    scanf("%lld", &T);
    while(T--) {
        scanf("%lld", &n);
        bool flag = true;
        ans = 0;
        x = y = 0;
        for(ll i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            if(a[i] == 0) y++;
        }
        for(ll i = 1; i <= y; i++) {
            if(a[i] == 1) x++;
        }
        for(ll i = 1; i <= x; i++) {
            (ans += n*(n-1)/2%P*qpow(i*i%P, P-2)) %= P;
        }
        printf("%lld\n", ans);
    }
}