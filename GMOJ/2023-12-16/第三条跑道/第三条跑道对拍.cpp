#include <cstdlib>
int main() {
	while(true) {
		system("第三条跑道数据.exe >in.in");
		system("第三条跑道.exe <in.in>my.out");
		system("第三条跑道暴力.exe <in.in>baoli.out");
		if(system("fc my.out baoli.out")) {
			break;
		}
	}
}
