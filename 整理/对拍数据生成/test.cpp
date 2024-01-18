#include <cstdio>
#include <random>
#include <algorithm>
#include <sys/timeb.h>
#include <set>
int main() {
	timeb tb;
	ftime(&tb);
	std::mt19937 rnd(tb.millitm);
	int n = 10, m = 15;
	int a[100];
	
	for(int i = 1; i <= n; i++) {
		a[i] = i;
	}
	std::shuffle(a+1, a+1+n, rnd);
	for(int i = 1; i <= m; i++) {
		int u, v;
		while(true) {
			u = rnd() % n + 1;
			v = rnd() % n + 1;
			if(u != v) break;
		}
		if(u > v) std::swap(u, v);
		printf("%d %d\n", a[u], a[v]);
	}
}
