#include <cstdio>
#include <cstring>
#define ll long long
#define N 35
#define M 110
#define P 998244353
ll n, m, x, ans;
ll v[M];

ll dp[2][N][N][N][N];
//  到第p位,第p位选择i个，前面选择j个，前面进位k，总共有num个1


ll f[2][N][N][N];
//  到第p位,前面选择j个，进位k，前面有num个1

ll pown[M][N];

ll inv[N];
ll fac[N];

ll qpow(ll n, ll m) {
    if(m == 0) return 1;
    if(m % 2 == 1) return n * qpow(n, m-1) % P;
    ll tmp = qpow(n, m/2);
    return tmp * tmp % P;
}

inline ll C(ll n, ll m) {
    return fac[n] * inv[n-m] % P * inv[m] % P;
}

int main() {
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
    
    scanf("%lld %lld %lld", &n, &m, &x);
    for(ll i = 0; i <= m; i++) {
        scanf("%lld", &v[i]);
        pown[i][0] = 1;
        for(ll j = 1; j <= n; j++) {
            pown[i][j] = pown[i][j-1] * v[i] % P;
        }
    }

    fac[0] = 1;
    for(ll i = 1; i <= n; i++) {
        fac[i] = fac[i-1] * i % P;
    }
    inv[n] = qpow(fac[n], P-2);
    for(ll i = n-1; i >= 0; i--) {
        inv[i] = inv[i+1] * (i+1) % P;
    }
    f[0][0][0][0] = 1;
    for(ll p = 0; p <= m; p++) {
        memset(f[(p+1)%2], 0, sizeof f[(p+1)%2]);
        memset(dp[(p+1)%2], 0, sizeof dp[(p+1)%2]);
        for(ll i = 0; i <= n; i++) {
            for(ll j = 0; j <= n-i; j++) {
                for(ll k = 0; k <= n; k++) {
                    for(ll num = (i+k)%2; num <= x; num++) {
                        dp[p%2][i][j][k][num] = f[p%2][j][k][num-(i+k)%2] * pown[p][i] % P * C(n-j, i) % P;
                        (f[(p+1)%2][i+j][(i+k)/2][num] += dp[p%2][i][j][k][num]) %= P;
                        // printf("dp[%lld][%lld][%lld][%lld][%lld]=%lld\n", p, i, j, k, num, dp[p%2][i][j][k][num]);
                    }
                }
            }
        }
    }

    for(ll i = 0; i <= n; i++) {
        for(ll k = 0; k <= n; k++) {
            for(ll num = 0; num <= x; num++) {
                if(num + __builtin_popcount((i+k)/2) <= x) (ans += dp[m%2][i][n-i][k][num]) %= P;
            }
        }
    }
    printf("%lld", ans);
}