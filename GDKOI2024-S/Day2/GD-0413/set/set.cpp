#include <cstdio>
#include <cstdlib>
#include <set>
#define N 3000
using namespace std;
int n, siz;
bool a[N][N], v[N][N];
int tot;
inline int calc(int x) {
	return (x % siz + siz) % siz;
}
inline int read() {
	int x = 0;
	char c = '.';
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + (c ^ '0');
		c = getchar();
	}
	return x;
}
void print(int x) {
	if(x > 9) print(x / 10);
	putchar(x % 10 + '0');
}
int main() {
	freopen("set.in", "r", stdin);
	freopen("set.out", "w", stdout);
	n = read();
	siz = 1<<n;
	for(int i = 0; i < siz; i++) {
		for(int j = 0; j < siz; j++) {
			a[i][j] = read();
		}
	}
	
	for(int w = siz/2; w >= 2; w /= 2) {
		for(int i = 0; i < siz; i++) {
			for(int j = 0; j < siz; j++) {
				v[i][j] = 0;
			}
		}
		for(int i = 0; i < siz; i++) {
			for(int j = 0; j < siz; j++) {
				if(a[i][j]) {
					v[i][j] ^= 1;
					v[calc(i+w/2)][j] ^= 1;
					v[calc(i-w/2)][j] ^= 1;
					v[i][calc(j+w/2)] ^= 1;
					v[i][calc(j-w/2)] ^= 1;
				}
			}
		}
		for(int i = 0; i < siz; i++) {
			for(int j = 0; j < siz; j++) {
				a[i][j] = v[i][j];
			}
		}
	}
	
	for(int i = 0; i < siz; i++) {
		for(int j = 0; j < siz; j++) {
			if(v[i][j]) {
				tot++;
			}
		}
	}
	print(tot);
	putchar('\n');
	for(int i = 0; i < siz; i++) {
		for(int j = 0; j < siz; j++) {
			if(v[i][j]) {
				print(i);
				putchar(' ');
				print(j);
				putchar('\n');
			}
		}
	}
}
