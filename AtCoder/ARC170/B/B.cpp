#include <cstdio>
#define ll long long
#define N 100010
ll n, ans;
ll a[N];
ll t[20][20], tt[20];
int main() {
    scanf("%lld ", &n);
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    ll r = 1;
    for(ll l = 1; l <= n; l++) {
        bool ok;
        while(r <= n) {
            ok = false;
            for(ll i = 1; i <= 10; i++) {
                for(ll j = 1; j <= 10; j++) {
                    if(t[i][j] && a[r] - j == j - i) {
                        ok = true;
                    }
                }
            }
            
            if(ok == true) break;

            for(ll i = 1; i <= 10; i++) {
                t[i][a[r]] += tt[i];
            }
            tt[a[r]]++;

            r++;
        }

        if(ok) {
            ans += n - r + 1;
        }

        tt[a[l]]--;
        for(ll i = 1; i <= 10; i++) {
            t[a[l]][i] -= tt[i];
        }
    }

    printf("%lld", ans);
} 