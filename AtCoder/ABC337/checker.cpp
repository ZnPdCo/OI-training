#include <cstdlib>
int main() {
	while(true) {
		system("data.exe > F.in");
		system("F.exe < F.in > F.out");
		system("std.exe < F.in > F.ans");
		if(system("fc /w F.out F.ans")) {
			break;
		}
	}
}
