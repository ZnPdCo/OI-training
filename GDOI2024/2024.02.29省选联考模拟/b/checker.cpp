#include <cstdio>
#include <cstdlib>
int main() {
	while(true) {
		system("data.exe > b.in");
		system("std.exe < b.in > b.ans");
		system("b.exe < b.in > b.out");
		if(system("fc b.out b.ans")) {
			return 0;
		}
	}
}
