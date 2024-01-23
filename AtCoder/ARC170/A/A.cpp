#include <cstdio>
#include <deque>
using namespace std;
#define ll long long
#define N 200010
ll n, ans;
char s[N], t[N];
ll ba[N], top;
bool a, b;
bool vis[N];
int main() {
    scanf("%lld %s %s", &n, s+1, t+1);
    for(ll i = 1; i <= n; i++) {
        if(s[i] == 'B' && t[i] == 'A') {
            ba[++top] = i;
            ans++;
        }
        if(s[i] == 'A' && t[i] == 'B') {
            if(top) {
                vis[ba[top]] = 1;
                top--;
            } else if(a) {
                ans++;
            } else {
                return printf("-1"), 0;
            }
        }
        if(t[i] == 'A') {
            a = true;
        }
    }
    if(!top) return printf("%lld", ans), 0;
    for(ll i = n; i >= 1; i--) {
        if(s[i] == 'B' && t[i] == 'A' && !vis[i]) {
            if(!b) return printf("-1"), 0;
        }
        if(t[i] == 'B') {
            b = 1;
        }
    }
    return printf("%lld", ans), 0;
}