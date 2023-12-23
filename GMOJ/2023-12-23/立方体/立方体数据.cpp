#include <random>
#include <ctime>
#include <cstdio>
using namespace std;
mt19937 rnd(time(0));
int main() {
	int stx, sty,edx,edy;
	while(true) {
		stx = rnd() % 8, sty = rnd() % 8;
		edx = rnd() % 8, edy = rnd() % 8;
		if(stx!=edx || sty!=edy) break;
	}
	printf("%c%c %c%c %d %d %d %d %d %d", stx+'a', sty+'1', edx+'a', edy+'1', rnd()%20, rnd()%20, rnd()%20, rnd()%20, rnd()%20, rnd()%20);
}
