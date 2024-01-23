#include <sys/timeb.h>
#include <random>
#include <cstdio>
#define ll long long
int main() {
    timeb tb;
    ftime(&tb);
    std::mt19937 rnd(tb.millitm);
    ll t = 20;
    while(t--) {
        ll n = 25, m = 23;
        printf("%lld %lld\n", n, m);
        for(ll i = 1; i < n-1; i++) {
            printf("%lld %lld %lld\n", rnd() % i + 1, i+1, rnd() % 20+1);
        }
        // for(ll i = n; i <= m; i++) {
        //     printf("%lld %lld %lld\n", rnd() % n + 1, rnd() % n + 1, rnd() % 20+1);
        // }
        printf("%lld %lld\n", rnd() % n + 1, rnd() % n + 1);
    }
}