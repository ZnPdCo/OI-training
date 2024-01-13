#include <cstdio>
#include <ctime>
#include <random>
int main() {
	timeb tb;
	ftime(&tb);
	std::mt19937 rnd(tb.millitm);
	int n = 5, m = 6, q = 2; 
	printf("%d %d %d\n", n, m, q);
	for(int i = 1; i <= q; i++) {
		int x = rnd() % n+1, y = rnd() % m + 1;
		printf("%d %d\n", x, y);
	}
}
