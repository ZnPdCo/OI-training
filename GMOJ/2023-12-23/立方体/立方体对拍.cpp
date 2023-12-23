#include <cstdlib>
#define ll long long
int main() {
	while(true) {
		system("立方体数据.exe > in.in");
		system("立方体.exe < in.in > my.out");
		system("std.exe < in.in > std.out");	// std真tm的短
		if(system("fc my.out std.out")) {
			break;
		}
	}
}
