#include <cstdio>
#include <cstdlib>
#include <windows.h>
#define ll long long
ll pos;
int main() {
	while(true){
		printf("%lld", ++pos);
		system("小X做实验数据.exe > in.in");
		printf("开始");
		system("小X做实验.exe < in.in > my.out");
		printf("结束");
		system("小X做实验暴力.exe < in.in > baoli.out");
		if(system("fc my.out baoli.out")) {
			MessageBox(0, "wrong answer", "wrong answer", 0);
			return 0;
		}
		if(pos == 10000) {
			MessageBox(0, "10000组AC", "10000组AC", 0);
		}
	}
}
