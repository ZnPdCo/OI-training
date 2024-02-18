#include <cstdlib>
int main() {
	while(true) {
		system("data.exe > 3.in");
		system("poly.exe < 3.in > 3.ans");
		system("Moorbles.exe < 3.in > 3.out");
		if(system("fc 3.out 3.ans")) {
			break;
		}
	}
}
