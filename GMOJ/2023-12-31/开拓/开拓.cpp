/**
 * @file 开拓.cpp 
 * @tag: #GMOJ#dp#反向dp
 * @author: ZnPdCo
 * @date: 2023-12-31 14:30:51
 * @problem: https://gmoj.net/senior/#main/show/5377
 **/
#include <cstdio>
#include <algorithm>
#define ll long long
#define N 100010
using namespace std;
ll n, k, c, w;
ll t[N];
double x[N];
double f[N];
int main() {
	freopen("exploit.in", "r", stdin);
	freopen("exploit.out", "w", stdout);
	scanf("%lld%lld%lld%lld", &n, &k, &c, &w);
	for(ll i = 1; i <= n; i++) {
		scanf("%lld%lf", &t[i], &x[i]);
	}
	for(ll i = n; i >= 1; i--) {
		if(t[i] == 1) {
			f[i] = max(f[i+1], f[i+1]*(1-0.01*k)+x[i]);
		} else {
			f[i] = max(f[i+1], f[i+1]*(1+0.01*c)-x[i]);
		}
	}
	printf("%.2lf", f[1] * w);
}
