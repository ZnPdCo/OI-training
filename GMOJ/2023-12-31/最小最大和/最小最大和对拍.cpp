#include <cstdlib>
int main() {
	while(true) {
		system("最小最大和数据.exe > in.in");
		system("最小最大和.exe < in.in > my.out");
		system("最小最大和朴素.exe < in.in > baoli.out");
		if(system("fc my.out baoli.out")) {
			break;
		}
	}
}
