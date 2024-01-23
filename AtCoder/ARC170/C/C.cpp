#include <cstdio>
#define ll long long
#define N 5010
#define P 998244353
ll f[N][N], ans;
// 当前到第i个，使用了j种数

ll n, m, a[N];

int main() {
    scanf("%lld%lld", &n, &m);
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    if(a[1] == 1) {
        // 第一位只能为零
        f[1][1] = 1;
    } else {
        // 第一位不能为0
        f[1][1] = m % P;
    }

    for(ll i = 2; i <= n; i++) {
        for(ll j = 1; j <= m+1 && j <= i; j++) {
            if(a[i] == 1) {
                f[i][j] = f[i-1][j-1] % P;
            } else {
                // 选择出现过的
                (f[i][j] += f[i-1][j] * j) %= P;
                // 选择没出现过的
                (f[i][j] += f[i-1][j-1] * (m - j + 1)) %= P;
            }
            // printf("f[%lld][%lld]=%lld\n", i, j, f[i][j]);
        }
    }

    for(ll i = 1; i <= n; i++) {
        (ans += f[n][i]) %= P;
    }
    printf("%lld", ans);
}