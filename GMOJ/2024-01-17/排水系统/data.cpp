#include <cstdio>
int main() {
	
	freopen("water.in", "w", stdout);
	int n = 10, m = 1;
	printf("%d %d\n", n, m);
	for(int i = 1; i <= n-5; i++) {
		printf("5 %d %d %d %d %d\n", i+1, n-3, n-2, n-1, n);
	} 
	printf("0\n0\n0\n0\n0\n");
}
