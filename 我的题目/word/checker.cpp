#include <cstdlib>
int main() {
	while(true) {
		
		system("data.exe > word.in");
		system("std.exe < word.in > word.out");
		system("poly.exe < word.in > word.ans");
		if(system("fc word.out word.ans")) break;
	}
}
