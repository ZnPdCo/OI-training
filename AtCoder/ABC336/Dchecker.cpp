#include <cstdlib>
int main() {
	while(true) {
		system("Ddata.exe > in.in");
		system("D.exe < in.in > my.out");
		system("Dstd.exe < in.in > out.out");
		if(system("fc my.out out.out")) {
			break;
		}
	}
}
