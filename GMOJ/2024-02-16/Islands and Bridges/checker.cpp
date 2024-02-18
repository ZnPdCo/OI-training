#include <cstdlib>
int main() {
	while(true) {
		system("data.exe > bridges.in");
		system("\"Islands and Bridges.exe\" < bridges.in > bridges.out");
		system("poly.exe < bridges.in > bridges.ans");
		if(system("fc bridges.out bridges.ans")) {
			break;
		}
	}
}
