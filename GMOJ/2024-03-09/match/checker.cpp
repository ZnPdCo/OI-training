#include <cstdlib>
int main() {
	while(true) {
		system("data.exe > match.in");
		system("match.exe < match.in > match.out");
		system("poly.exe < match.in > match.ans");
		if(system("fc match.out match.ans")) {
			break;
		}
	}
}
