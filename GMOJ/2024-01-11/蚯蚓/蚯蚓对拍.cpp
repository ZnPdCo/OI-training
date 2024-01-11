#include <cstdlib>
int main() {
	while(true) {
		system("蚯蚓数据.exe > earthworm.in");
		system("蚯蚓暴力.exe < earthworm.in > baoli.out");
		system("蚯蚓.exe");
		if(system("fc baoli.out earthworm.out")) {
			break;
		}
	}
}
