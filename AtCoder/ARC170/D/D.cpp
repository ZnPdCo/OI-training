#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
#define N 200010
ll n;
ll a[N], b[N];
bool win;
bool cmp(ll x, ll y) {
    return x < y;
}
bool ck(ll x, ll y, ll z) {
    ll c[3] = {x, y, z};
    sort(c, c+3, cmp);
    x = c[0], y = c[1], z = c[2];
    if(x + y > z && y - x < z) return true;
    return false;
}
int main() {
    scanf("%lld", &n);
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a+1, a+1+n, cmp);
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &b[i]);
    }
    sort(b+1, b+1+n, cmp);
    for(ll x = 1; x <= n; x++) {
        if((x != n && ck(a[x], a[x+1], b[1])) || (x != 1 && ck(a[x-1], a[x], b[1])) || (x != n && ck(a[x], a[n], b[n])) || (x != 1 && ck(a[x], a[1], b[n]))) {
            win = 1;
            break;
        }
    }

    if(win) printf("Alice");
    else printf("Bob");
}