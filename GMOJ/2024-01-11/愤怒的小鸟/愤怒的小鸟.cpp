/**
 * @file 愤怒的小鸟.cpp 
 * @tag: #GMOJ#dp#状压dp#数学
 * @author: ZnPdCo
 * @date: 2024-01-11 20:57:17
 * @problem: https://gmoj.net/senior/#main/show/4908
 **/
#include <cstdio>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;
#define N 20
ll T, n, m;
double x[N], y[N];
ll line[10*N], cnt;
ll f[1<<N];
int main() {
	freopen("angrybirds.in", "r", stdin);
	freopen("angrybirds.out", "w", stdout);
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld %lld", &n, &m);
		for(ll i = 1; i <= n; i++) {
			scanf("%lf %lf", &x[i], &y[i]);
		}
		cnt = 0;
		for(ll i = 1; i <= n; i++) {
			for(ll j = i+1; j <= n; j++) if(x[i] != x[j] || y[i] != y[j]) {
/*
下面这个公式我数学不好，把推导放在这方便以后来看
$$
\because\begin{cases}
y_i=ax_i^2+bx_i \\
y_j=ax_j^2+bx_j
\end{cases} \\
\therefore\begin{cases}
\frac{y_i}{x_i}=ax_i+b \\
\frac{y_j}{x_j}=ax_j+b
\end{cases} \\
\therefore a(x_i-x_j)=\frac{y_i}{x_i}-\frac{y_j}{x_j} \\
\therefore a=(\frac{y_i}{x_i}-\frac{y_j}{x_j})\div(x_i-x_j) \\
\therefore b=\frac{y_i}{x_i}-ax_i
$$
*/
				double a = (y[i]/x[i]-y[j]/x[j])/(x[i]-x[j]);
				double b = y[i]/x[i]-a*x[i];
				if(a >= 0) continue;
				line[++cnt] = 0;
				for(ll k = 1; k <= n; k++) {
					if(abs(a*x[k]*x[k]+b*x[k]-y[k]) <= 1e-9) {
						line[cnt] |= (1<<(k-1));
					}
				}
			}
			
			
			line[++cnt] = 0;
			for(ll j = i+1; j <= n; j++) if(x[i] == x[j] && y[i] == y[j]) {
				line[cnt] |= (1<<(j-1));
			}
		}
		for(ll s = 1; s < (1<<n); s++) f[s] = 1e15;
		for(ll s = 0; s < (1<<n); s++) {
			for(ll i = 1; i <= cnt; i++) {
				f[s|line[i]] = min(f[s|line[i]], f[s] + 1);
			}
			for(ll i = 1; i <= n; i++) {
				f[s|(1<<(i-1))] = min(f[s|(1<<(i-1))], f[s] + 1);
			}
		}
		printf("%lld\n", f[(1<<n)-1]);
	}
}
