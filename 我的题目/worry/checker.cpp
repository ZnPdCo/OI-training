#include <cstdlib>
int main() {
	while(true) {
		system("data.exe > worry.in");
		system("std.exe < worry.in > worry.ans");
		system("poly.exe < worry.in > worry.out");
		if(system("fc worry.out worry.ans")) {
			return 0;
		}
	}
}
