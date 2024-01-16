#include <cstdlib>
int main() {
	while(1){
		system("data.exe > call.in");
		system("poly.exe < call.in > call.ans");
		system("函数调用.exe");
		if(system("fc call.out call.ans")) {
			break;
		}
	}
}
