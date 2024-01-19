#include <cstdio>
#define ll long long
ll n;
int main() {
	scanf("%lld", &n);
	if(n == 1) printf("-1");
	else printf("%lld %lld %lld", n, n+1, n*(n+1));
}
