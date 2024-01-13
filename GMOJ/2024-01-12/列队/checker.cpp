#include <cstdlib>
int main() {
	while(true) {
		system("dat.exe > in.in");
		system("列队.exe < in.in > my.out");
		system("std.exe < in.in > std.out");
		if(system("fc my.out std.out")) {
			break;
		}
	}
}
