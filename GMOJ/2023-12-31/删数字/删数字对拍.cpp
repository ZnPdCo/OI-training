#include <cstdlib>
int main() {
	while(true) {
		system("删数字数据.exe > in.in");
		system("删数字.exe < in.in > my.out");
		system("删数字暴力.exe < in.in > baoli.out");
		if(system("fc my.out baoli.out")) {
			break;
		}
	}
}
