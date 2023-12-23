#include <cstdlib>
#include <ctime>
#include <cstdio>
#define ll long long
int main() {
	while(true) {
		system("计数数据.exe > in.in");
		ll st = clock();
		system("计数.exe < in.in > my.out");
		ll ed = clock();
		if(double(ed - st) / CLOCKS_PER_SEC > 1) {
			printf("TLE");
			break;
		}
		printf("time:%.2lf\n", double(ed - st) / CLOCKS_PER_SEC);
		system("计数朴素.exe < in.in > pusu.out");
			
		if(system("fc my.out pusu.out")) {
			break;
		}
	}
}
