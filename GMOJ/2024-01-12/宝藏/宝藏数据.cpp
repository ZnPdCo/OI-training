#include <cstdio>
#include <random>
#include <ctime>
using namespace std;
int fa[100];
int find(int x) {
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
int main() {
	timeb tb;
	ftime(&tb);
	mt19937 rnd(tb.millitm);
	int n = 8, m = 15;
	for(int i = 1; i <= n; i++) fa[i] = i;
	printf("%d %d\n", n, m);
	for(int i = 1; i < n; i++) {
		int u, v;
		while(true) {
			u = rnd() %n+1;
			v = rnd() %n+1;
			if(find(u) != find(v)) break; 
		}
		fa[find(u)] = find(v);
		printf("%d %d %d\n", u, v, rnd()%n+1);
	}
	for(int i = n; i <= m; i++) {
		int u, v;
		u = rnd() %n+1;
		v = rnd() %n+1;
		printf("%d %d %d\n", u, v, rnd()%n+1);
	}
}
