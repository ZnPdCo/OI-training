#include <cstdlib>
int main() {
	while(true) {
		system("xordata.exe > xor.in");
		system("xor.exe < xor.in > xor.out");
		system("xorstd.exe < xor.in > xor.ans");
		if(system("fc xor.out xor.ans")) return 0;
	}
}
