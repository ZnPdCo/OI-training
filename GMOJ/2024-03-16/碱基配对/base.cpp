#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long
#define N 800010
ll n, m, k;
char a[N], b[N];
ll siz = 1, L;
ll r[N], s[N];
bool ok[N];
ll ans;
struct complex {
    double x, y;
    complex(double xx = 0, double yy = 0) {x = xx, y = yy;}
	friend complex operator +(const complex &a, const complex &b) {return complex(a.x + b.x, a.y + b.y);}
	friend complex operator -(const complex &a, const complex &b) {return complex(a.x - b.x, a.y - b.y);}
	friend complex operator *(const complex &a, const complex &b) {return complex(a.x * b.x - a.y * b.y, a.x * b.y + b.x * a.y);}
} A[N], B[N];
double PI = acos(-1);
void FFT(complex *a, ll type) {
    for(ll i = 0; i < siz; i++) {
        if(i < r[i]) swap(a[i], a[r[i]]);
    }
    for(ll x = 2; x <= siz; x <<= 1) {
        complex wn(cos(2 * PI / x), type * sin(2 * PI / x));
        for(ll i = 0; i < siz; i += x) {
            complex w(1, 0);
            for(ll j = 0; j < (x >> 1); j++, w = w * wn) {
                complex A = a[i + j], B = a[i + (x >> 1) + j];
                a[i + j] = A + w * B;
                a[i + (x >> 1) + j] = A - w * B;
            }
        }
    }
}
void solve(char x) {
    for(ll i = 0; i < siz; i ++) {
        s[i] = 0;
        A[i] = complex(0, 0);
        B[i] = complex(0, 0);
    }
    for(ll i = 0; i < n; i ++) {
        if(a[i] == x) {
            s[max(i - k, 0ll)] ++;
            s[min(i + k + 1, n)] --;
        }
    }
    for(ll i = 0; i < n; i ++) {
        if(i > 0) s[i] += s[i - 1];
        A[i] = complex(!s[i], 0);
    }
    for(ll i = 0; i < m; i ++) {
        B[m - i - 1] = complex(b[i] == x, 0);
    }
    FFT(A, 1);
    FFT(B, 1);
    for(ll i = 0; i < siz; i ++) {
        A[i] = A[i] * B[i];
    }
    FFT(A, -1);
    for(ll i = 0; i <= n - m; i ++) {
        ll num = !(ll)(A[m + i - 1].x / siz + 0.5);
        ok[i] &= num;
    }
}
int main() {
	freopen("base.in", "r", stdin);
	freopen("base.out", "w", stdout);
    scanf("%lld %s %s", &k, a, b);
    n = strlen(a), m = strlen(b);
    while(siz < n + m) siz <<= 1, L ++;
    for(ll i = 0; i < siz; i++) {
        r[i] = (r[i >> 1] >> 1) | ((i & 1) << (L - 1));
    }
    for(ll i = 0; i <= n - m; i ++) {
        ok[i] = 1;
    }
    solve('Z');
    solve('P');
    solve('S');
    solve('B');
    for(ll i = 0; i <= n - m; i ++) {
        ans += ok[i];
    }
    printf("%lld", ans);
}