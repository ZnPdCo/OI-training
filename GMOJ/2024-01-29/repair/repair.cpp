#include <cstdio>
#include <algorithm>
#define P 1000000007
#define ll long long
using namespace std;
#define N 18
ll n, k;
ll a[N+1], e[2*N+1], num[2*N+1], unzip[2*N+1];
ll f[1<<N][2*N+1];
ll v[1<<N][2*N+1];
int main() {
    freopen("repair.in", "r", stdin);
	freopen("repair.out", "w", stdout);
    scanf("%lld %lld", &n, &k);
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        e[i] = a[i];
        e[i+n] = a[i]+1;
    }

    sort(e+1, e+1+2*n, [&](const auto &x, const auto &y){return x<y;});
    ll len = unique(e+1, e+1+2*n) - e - 1;
    for(ll i = 1; i <= n; i++) {
        num[i] = lower_bound(e+1, e+1+len, a[i]) - e;
        ll cnt = lower_bound(e+1, e+1+len, a[i]+1) - e;
        unzip[num[i]] = a[i];
        unzip[cnt] = a[i]+1;

        v[1<<(i-1)][num[i]] = 1;
    }

    for(ll s = 1; s < (1ll << n); s++) {
        for(ll i = 1; i <= len; i++) {
            for(ll j = 1; j <= n; j++) {
                if(s & (1<<(j-1))) continue;

                ll A = 0;
                if(i == num[j]) A = i+1;
                else A = max(i, num[j]); 
                
                (v[s | (1<<(j-1))][A] += v[s][i]) %= P;
                (f[s | (1<<(j-1))][A] += f[s][i] + v[s][i] * (k * unzip[A] % P + ((1ll<<(__builtin_popcountll(s))-1)-1)) % P) %= P;
            }
        }
    }

    for(ll i = len; i >= 1; i--) {
        if(v[(1<<n)-1][i]) {
            printf("%lld %lld\n", unzip[i], f[(1<<n)-1][i]);
            break;
        }
    }

    // for(ll s = 1; s < (1<<n); s++) {
    //     for(ll i = 1; i <= len; i++) {
    //         printf("f[%lld][%lld]=%lld\n", s, i, f[s][i]);
    //     }
    // }
}