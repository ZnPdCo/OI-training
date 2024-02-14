#include <cstdio>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;
ll n, m, x, k;
ll u[40010], v[40010];
void addEdge(ll x, ll y) {
	u[++m] = x;
	v[m] = y;
}
int main() {
	scanf("%lld", &k);
	x = log2l(k);
	n = x*3+2;
	addEdge(1, 2);
	addEdge(1, 3);
	if(k & 1) {
		addEdge(1, 4);
	}
	for(int i = 1; i < x; i++) {
		addEdge(i*3-1, (i+1)*3-1);
		addEdge(i*3-1, (i+1)*3);
		addEdge(i*3, (i+1)*3-1);
		addEdge(i*3, (i+1)*3);
		addEdge(i*3+1, (i+1)*3+1);
		if(k & (1ll << i)) {
			addEdge(i*3-1, (i+1)*3+1);
			addEdge(i*3, (i+1)*3+1);
		}
	}
	addEdge(x*3-1, n);
	addEdge(x*3, n);
	addEdge(x*3+1, n);
	
	printf("%lld %lld\n", n, m);
	for(int i = 1; i <= m; i++) {
		printf("%lld %lld\n", u[i], v[i]);
	}
	return 0;
}
