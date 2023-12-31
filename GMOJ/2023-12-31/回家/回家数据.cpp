#include <cstdio>
#include <random>
#include <ctime>
using namespace std;
int stx, sty, edx, edy, mox, moy;
int main() {
	timeb tb;
	ftime(&tb);
	mt19937 rnd(tb.millitm);
	int n = 101, m=100;
	while(true) {
		stx = rnd() % n+1;
		sty = rnd() % m+1;
		edx = rnd() % n+1;
		edy = rnd() % m+1;
		mox = rnd() % n+1;
		moy = rnd() % m+1;
		if(stx != edx || sty != edy) {
			if(stx != mox || sty != moy)
				if(edx != mox || edy != moy)
					break;
		}
	}
	printf("%d %d\n", n, m);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(stx == i && sty == j) putchar('V');
			else if(edx == i && edy == j) putchar('J');
			else if(mox == i && moy == j) putchar('+');
			else {
				int r = rnd() % 50;
				if(r == 0) putchar('+');
				else putchar('.');
			}
		}
		putchar('\n');
	}
}
