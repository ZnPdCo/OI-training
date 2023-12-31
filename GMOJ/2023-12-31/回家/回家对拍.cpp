#include <cstdlib>
int main() {
	while(true) {
		system("回家数据.exe > in.in");
		system("回家.exe < in.in > my.out");
		system("回家朴素.exe < in.in > baoli.out");
		if(system("fc my.out baoli.out")) {
			break;
		}
	}
}
