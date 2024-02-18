#include <cstdio>
#include <random>
using namespace std;
int main() {
	timeb tb;
	ftime(&tb);
	
	mt19937 rnd(tb.millitm);
	
	int t = 5;
	printf("%d\n", t);
	for(int i = 1; i <= t; i++) {
		int n = 15;
		printf("%d\n", n);
		for(int j = 1; j <= n; j++) {
			printf("%d", rnd() % 2);
		}
		printf("\n");
	}
}
