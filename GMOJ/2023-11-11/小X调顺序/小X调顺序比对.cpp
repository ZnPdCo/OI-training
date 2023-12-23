#include <cstdio>
#include <cstdlib>
#include <windows.h>
#define ll long long
ll pos;
int main() {
	while(true){
		printf("%lld", ++pos);
		system("小X调顺序数据.exe > in.in");
		system("小X调顺序.exe < in.in > my.out");
		system("小X调顺序暴力.exe < in.in > baoli.out");
		if(system("fc my.out baoli.out")) {
			MessageBox(0, "wrong answer", "wrong answer", 0);
			return 0;
		}
		if(pos == 10000) {
			MessageBox(0, "10000组AC", "10000组AC", 0);
		}
	}
}
