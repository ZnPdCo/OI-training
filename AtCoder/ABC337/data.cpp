#include <cstdio>
#include <sys/timeb.h>
#include <random>
int main() {
	timeb tb;
	ftime(&tb);
	std::mt19937 rnd(tb.millitm);
	int n = 10, m = 5, k = 3;
	printf("%d %d %d\n", n, m, k);
	for(int i = 1; i <= n; i++) {
		printf("%d ", rnd() % n + 1);
	}
}
