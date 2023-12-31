#include <cstdio>
#include <random>
#include <ctime>
using namespace std;
int n;
int main() {
	timeb tb;
	ftime(&tb);
	mt19937 rnd(tb.millitm);
	int n = 10, k = rnd() % (n-2) +1;
	printf("%d %d\n", n, k);
	for(int i = 1; i <= n; i++) {
		printf("%d ", rnd());
	}
}
