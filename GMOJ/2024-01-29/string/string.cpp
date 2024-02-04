#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#define ll long long
#define N 600010
#define P1 1000000007
#define P2 998244353
using namespace std;

ll n, q;

string s[N];
ll siz[N];
ll base1[N], base2[N];
vector<ll> hash1[N], hash2[N];

ll ans[20][20];
ll v[20][20];

inline bool check(ll x, ll y, ll k) {
    if(k == 0) return true;
    ll numx1 = ((hash1[x][siz[x]] - hash1[x][siz[x]-k] * base1[k] % P1) % P1 + P1) % P1;
    ll numx2 = ((hash2[x][siz[x]] - hash2[x][siz[x]-k] * base2[k] % P2) % P2 + P2) % P2;
    ll numy1 = hash1[y][k], numy2 = hash2[y][k];
    if(numx1 == numy1 && numx2 == numy2) {
        return true;
    } else {
        return false;
    }
}

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> q;
    base1[0] = base2[0] = 1;
    for(ll i = 1; i <= 600000; i++) {
        base1[i] = base1[i-1] * 26 % P1;
        base2[i] = base2[i-1] * 26 % P2;
    }

    for(ll i = 1; i <= n; i++) {
        cin >> s[i];
        ll m = s[i].length();
        siz[i] = m;
        s[i] = " " + s[i];
        hash1[i].push_back(0);
        hash2[i].push_back(0);
        for(ll j = 1; j <= m; j++) {
            ll num1 = (hash1[i][j-1] * 26 + (s[i][j] - 'a')) % P1;
            ll num2 = (hash2[i][j-1] * 26 + (s[i][j] - 'a')) % P2;
            hash1[i].push_back(num1);
            hash2[i].push_back(num2);
        }
    }
    for(ll i = 1; i <= q; i++) {
        ll x, y;
        cin >> x >> y;
        if(x <= 10 && y <= 10 && v[x][y]) {
            cout << ans[x][y] << '\n';
            continue;
        }
        bool flag = true;
        ll m = siz[x] > siz[y] ? siz[y] : siz[x];
        for(ll j = m; j >= 0; j--) {
            if(check(x, y, j)) {
                flag = 0;
                cout << j << '\n';
                if(x <= 10 && y <= 10) {
                    v[x][y] = 1;
                    ans[x][y] = j;
                }
                break;
            }
        }
    }
}
/*
4 5
abcd
abca
bcda
cdab
4 3 1
*/
