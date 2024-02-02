#include <ctime>
#include <random>
#include <cstdio>
using namespace std;
mt19937 rnd(time(0));
int cnt = 0;
int main() {
	int n = 100, m = 1000000, q = 1;
	for(int i = 1; i <= n; i++) {
		if(n-i+1 == cnt) {
			printf("]");
			cnt--;
			continue;
		}
		int r = rnd() % 7;
		if(r == 0) printf("W");
		if(r == 1) printf("W");
		if(r == 2) printf("W");
		if(r == 3) printf("W");
		if(r == 4) printf("*");
		if(r == 5) printf("?");
		if(r == 6) {
			if(!cnt || rnd() % 2 == 0) {
				if(n-i >= cnt+1) {
					cnt++;
					printf("[");
				} else printf("W");
			} else {
				printf("]");
				cnt--;
			}
		}
	}
	printf("\n%d\n", q);
	for(int i = 1; i <= m; i++) {
		int r = rnd() % 4;
		if(r == 0) printf("W");
		if(r == 1) printf("E");
		if(r == 2) printf("S");
		if(r == 3) printf("N");
	}
}
