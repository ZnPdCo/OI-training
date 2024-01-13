#include <cstdlib>
int main() {
	while(true) {
		system("宝藏数据.exe > in.in");
		system("宝藏.exe < in.in > my.out");
		system("宝藏暴力.exe < in.in > baoli.out");
		if(system("fc my.out baoli.out")) break;
	}
}
