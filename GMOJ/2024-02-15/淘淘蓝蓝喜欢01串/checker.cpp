#include <cstdlib>
int main() {
	while(true) {
		system("data.exe > str.in");
		system("淘淘蓝蓝喜欢01串.exe < str.in > str.out");
		system("poly.exe < str.in > str.ans");
		if(system("fc str.out str.ans")) {
			break;
		}
	}
}
