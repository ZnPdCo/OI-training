#include <cstdlib>
#include <ctime>
#include <cstdio>
int main() {
	while(true) {
		system("data.exe > hacker.in");
		printf("st\n");
		int st = clock();
		system("BRT.exe < hacker.in > hacker.out");
		int ed = clock();
//		if((ed-st)*1.0/CLOCKS_PER_SEC > 2.0) {
			system("zip BRT.zip hacker.in hacker.out");
			break;
//		}
		printf("%.2lf\n", (ed-st)*1.0/CLOCKS_PER_SEC);
	}
}
