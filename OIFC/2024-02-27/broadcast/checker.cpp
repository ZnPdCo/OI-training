#include <cstdlib>
int main() {
	while(true) {
		system("data3.exe > broadcast.in");
		system("broadcast.exe < broadcast.in > broadcast.out");
		system("std.exe < broadcast.in > broadcast.ans");
		if(system("fc broadcast.out broadcast.ans")) {
			return 0;
		}
	}
}
