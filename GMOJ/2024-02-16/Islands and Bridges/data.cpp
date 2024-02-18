#include <cstdio>
#include <random>
using namespace std;
int main() {
	timeb tb;
	ftime(&tb);
	mt19937 rnd(tb.millitm);
	int q = 2;
	printf("%d\n", q);
	for(int i = 1; i <= q; i++) {
		int n = 8, m = 64;
		printf("%d %d\n", n, m);
		for(int j = 1; j <= n; j++) {
			printf("%d ", j);
		}
		printf("\n");
		for(int j = 2; j <= n; j++) {
			printf("%d %d\n", j, rnd() % (j-1) + 1);
		}
		for(int j = n; j <= m; j++) {
			int u, v;
			while(true) {
				u = rnd() % n + 1;
				v = rnd() % n + 1;
				if(u != v) break;
			}
			printf("%d %d\n", u, v);
		}
	}
}
