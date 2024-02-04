#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
#define N 2010
ll n, q, w, h, M, a, b, m;
struct node {
    ll h, x, y, id;
} s[N], e1[N], e2[N];
ll p1[N], p2[N];
ll lt[N][N], rt[N][N], ld[N][N], rd[N][N];
ll x, y;

ll high[N][N];

ll abs(ll x) {
    return x > 0 ? x : -x;
}

ll qpow(ll x, ll y) {
    if(y == 0) return 1;
    if(y % 2 == 1) return x * qpow(x, y - 1) % M;
    ll tmp = qpow(x, y / 2);
    return tmp * tmp % M;
}

int main() {
    freopen("satellite.in", "r", stdin);
	freopen("satellite.out", "w", stdout);
    scanf("%lld %lld %lld %lld %lld %lld %lld", &n, &q, &w, &h, &M, &a, &b);
    for(ll i = 1; i <= n; i++) {
        scanf("%lld %lld %lld", &s[i].h, &s[i].x, &s[i].y);
        s[i].id = i;
        e1[i] = e2[i] = s[i];
    }
    sort(e1+1, e1+1+n, [&](const node &x, const node &y) {return x.x < y.x;});
    sort(e2+1, e2+1+n, [&](const node &x, const node &y) {return x.y < y.y;});

    for(ll i = 2; i <= n; i++) {
        p1[i] = qpow(a, e1[i].x - e1[i-1].x);
        p2[i] = qpow(b, e2[i].y - e2[i-1].y);
    }

    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= n; j++) {
            if(e1[i].id == e2[j].id) {
                high[i][j] = e1[i].h % M;
                break;
            }
        }
    }

    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= n; j++) {
            lt[i][j] = lt[i-1][j] * p1[i] % M + 
                            lt[i][j-1] * p2[j] % M - 
                            lt[i-1][j-1] * p1[i] % M * p2[j] % M +
                            high[i][j];
            lt[i][j] = (lt[i][j]%M+M)%M;
        }
        for(ll j = n; j >= 1; j--) {
            rt[i][j] = rt[i-1][j] * p1[i] % M + 
                            rt[i][j+1] * p2[j+1] % M - 
                            rt[i-1][j+1] * p1[i] % M * p2[j+1] % M +
                            high[i][j];
            rt[i][j] = (rt[i][j]%M+M)%M;
        }
    }
    for(ll i = n; i >= 1; i--) {
        for(ll j = 1; j <= n; j++) {
            ld[i][j] = ld[i+1][j] * p1[i+1] % M + 
                            ld[i][j-1] * p2[j] % M - 
                            ld[i+1][j-1] * p1[i+1] % M * p2[j] % M +
                            high[i][j];
            ld[i][j] = (ld[i][j]%M+M)%M;
        }
        for(ll j = n; j >= 1; j--) {
            rd[i][j] = rd[i+1][j] * p1[i+1] % M + 
                            rd[i][j+1] * p2[j+1] % M - 
                            rd[i+1][j+1] * p1[i+1] % M * p2[j+1] % M +
                            high[i][j];
            rd[i][j] = (rd[i][j]%M+M)%M;
        }
    }
    for(ll i = 1; i <= q; i++) {
        scanf("%lld %lld", &x, &y);
        ll l = 1, r = n, cx = 0;
        while(l <= r) {
            ll mid = (l+r)>>1;
            if(e1[mid].x <= x) {
                cx = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        l = 1, r = n; ll cy = 0;
        while(l <= r) {
            ll mid = (l+r)>>1;
            if(e2[mid].y <= y) {
                cy = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        ll ans = lt[cx][cy] * qpow(a, x - e1[cx].x) % M * qpow(b, y - e2[cy].y) % M +
                 rt[cx][cy+1] * qpow(a, x - e1[cx].x) % M * qpow(b, e2[cy+1].y - y) % M +
                 ld[cx+1][cy] * qpow(a, e1[cx+1].x - x) % M * qpow(b, y - e2[cy].y) % M +
                 rd[cx+1][cy+1] * qpow(a, e1[cx+1].x - x) % M * qpow(b, e2[cy+1].y - y) % M;
        ans %= M;
        printf("%lld\n", ans);
    }
}