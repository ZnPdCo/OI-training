#include <cstdio>
#include <cstring>
using ll = long long;
const ll N = 1010, P = 998244353;
ll T, _, n, m, c, f;
char s[N][N];

ll right[N][N], ans1, ans2;

ll sum1[N][N], sum2[N][N];
int main() {
    freopen("plant.in", "r", stdin);
    freopen("plant.out", "w", stdout);
    scanf("%lld %lld", &T, &_);
    while(T--) {
        memset(right, 0, sizeof right);
        memset(sum1, 0, sizeof sum1);
        memset(sum2, 0, sizeof sum2);
        ans1 = ans2 = 0;

        scanf("%lld %lld %lld %lld", &n, &m, &c, &f);
        for(ll i = 1; i <= n; i++) {
            scanf("%s", s[i]+1);
        }

        for(ll i = 1; i <= n; i++) {
            for(ll j = m; j >= 1; j--) {
                if(s[i][j] == '0') right[i][j] = right[i][j+1] + 1;
                else right[i][j] = 0;
            }
        }

        for(ll j = 1; j <= m; j++) {
            ll down = 0;    // 能往下延伸多少？
            for(ll i = n; i >= 1; i--) {
                if(s[i][j] == '1') {
                    sum1[i][j] = 0;
                    sum1[i+1][j] = 0;   // 阻断
                    sum2[i][j] = 0;
                    sum2[i+1][j] = 0;
                    down = 0;
                    continue;
                }
                (ans1 += right[i][j+1] * sum1[i+2][j]) %= P;
                (ans2 += right[i][j+1] * sum2[i+2][j]) %= P;

                (sum1[i][j] = sum1[i+1][j] + right[i][j+1]) %= P;
                (sum2[i][j] = sum2[i+1][j] + right[i][j+1] * down % P) %= P;

                down++;
            }
        }
        printf("%lld %lld\n", ans1 * c % P, ans2 * f % P);
    }
}

