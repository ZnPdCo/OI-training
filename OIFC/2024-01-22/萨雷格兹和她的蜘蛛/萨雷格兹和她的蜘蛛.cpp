#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define N 1000010
using namespace std;

ll n, m;
ll a[N], e[N];
ll x[N], op[N];

ll rev;

namespace IO {
    ll read() {
        ll x = 0;
        char c = '.';
        while(c < '0' || c > '9') c = getchar();
        while(c >= '0' && c <= '9') {
            x = (x<<1) + (x<<3) + (c^'0');
            c = getchar();
        }
        return x;
    }
}

namespace Tree {
    ll head[N];
    ll nxt[2*N];
    ll to[2*N], cnt;
    void add_edge(ll u, ll v) {
        cnt++;
        to[cnt] = v;
        nxt[cnt] = head[u];
        head[u] = cnt;
    }


    ll dep[N];
    bool is_son[N];
    void dfs(ll u, ll fa) {
        dep[u] = dep[fa] + 1;
        is_son[u] = true;
        for(ll i = head[u]; i; i = nxt[i]) {
            ll v = to[i];
            if(v == fa) continue;
            is_son[u] = false;
            dfs(v, u);
        }
    }
}

namespace BIT {
    ll t[N];

    inline ll lowbit(ll x) {
        return x & (-x);
    }

    inline void update(ll x, ll k) {
        while(x <= n) {
            t[x] += k;
            x += lowbit(x);
        }
    }

    inline ll query(ll x) {
        ll res = 0;
        while(x) {
            res += t[x];
            x -= lowbit(x);
        }
        return res;
    }

    inline ll getone(ll x) {
        return query(x) - query(x-1);
    }

    inline ll getseq(ll x, ll y) {
        return query(y) - query(x-1);
    }

    inline void clear() {
        memset(t, 0, sizeof t);
    }

    inline void clear(ll x) {
        update(x, -getone(x));
    }
}

namespace s0 {
    bool k[N], v[N];
    bool check(ll mid) {
        memset(k, 0, sizeof k);
        memset(v, 0, sizeof v);

        for(ll i = 1; i <= n; i++) {
            if(a[i] <= mid) {
                k[i] = 1;
            } else {
                k[i] = 0;
            }
            v[Tree::dep[i]] |= k[i];
        }

        for(ll i = 1; i <= n; i++) if(Tree::is_son[i]) {
            if(k[i] == 1) return true;
        }

        BIT::clear();

        for(ll i = 1; i <= n; i++) BIT::update(i, v[i]);

        for(ll i = 1; i <= m; i++) {
            if(op[i] == 0) {
                ll res = BIT::getseq(x[i], n);
                BIT::clear(x[i]);
                if(res)
                    BIT::update(x[i], 1);
            } else {
                BIT::clear(x[i]);
            }
        }

        return BIT::getone(1);
    }

    void solve() {
        ll l = 1, r = n, ans;
        while(l <= r) {
            ll mid = (l + r) >> 1;
            if(check(e[mid])) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        printf("%lld", e[ans]);
    }
}

namespace s1 {
    bool k[N], v[N];
    bool check(ll mid) {
        memset(k, 0, sizeof k);
        memset(v, 0, sizeof v);

        for(ll i = 1; i <= n; i++) {
            if(a[i] >= mid) {
                k[i] = 1;
            } else {
                k[i] = 0;
            }
            v[Tree::dep[i]] |= k[i];
        }

        for(ll i = 1; i <= n; i++) if(Tree::is_son[i]) {
            if(k[i] == 1) return true;
        }

        BIT::clear();

        for(ll i = 1; i <= n; i++) BIT::update(i, v[i]);

        for(ll i = 1; i <= m; i++) {
            if(op[i] == 1) {
                ll res = BIT::getseq(x[i], n);
                BIT::clear(x[i]);
                if(res)
                    BIT::update(x[i], 1);
            } else {
                BIT::clear(x[i]);
            }
        }

        return BIT::getone(1);
    }

    void solve() {
        ll l = 1, r = n, ans;
        while(l <= r) {
            ll mid = (l + r) >> 1;
            if(check(e[mid])) {
                l = mid + 1;
                ans = mid;
            } else {
                r = mid - 1;
            }
        }
        printf("%lld", e[ans]);
    }
}

int main() {
    freopen("spider.in", "r", stdin);
    freopen("spider.out", "w", stdout);
    n = IO::read();
    m = IO::read();
    for(ll i = 1; i <= n; i++) e[i] = a[i] = IO::read();

    sort(e+1, e+1+n, [](const auto &x, const auto &y) {return x < y;});

    for(ll i = 2; i <= n; i++) {
        ll fa = IO::read();
        Tree::add_edge(i, fa);
        Tree::add_edge(fa, i);
    }

    Tree::dfs(1, 0);

    for(ll i = 1; i <= m; i++) x[i] = IO::read(), op[i] = IO::read();
    
    rev = -1;
    for(ll i = m; i >= 1; i--) if(x[i] == 1) {
        m = i;
        rev = op[i];
        break;
    }

    if(rev == -1) return printf("%lld", a[1]), 0;
    if(rev == 0) s0::solve();
    if(rev == 1) s1::solve();
}