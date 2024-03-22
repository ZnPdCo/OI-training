#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long
#define N 8000010
struct complex {
	double x, y;
	complex(double xx = 0, double yy = 0):x(xx), y(yy){};
	friend complex operator +(const complex &a, const complex &b) {return complex(a.x + b.x, a.y + b.y);}
	friend complex operator -(const complex &a, const complex &b) {return complex(a.x - b.x, a.y - b.y);}
	friend complex operator *(const complex &a, const complex &b) {return complex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);}
} A[N], B[N];
ll n, m;
char s[N], t[N];
ll siz = 1, l;
ll r[N], ans = 1e15;
ll ss[N], ts;
double PI = acos(-1);
void FFT(complex *a, ll type) {
	for(ll i = 0; i < siz; i ++) {
		if(i < r[i]) swap(a[i], a[r[i]]);
	}
	for(ll x = 2; x <= siz; x <<= 1) {
		complex wn(cos(2 * PI / x), type * sin(2 * PI / x));
		for(ll i = 0; i < siz; i += x) {
			complex w(1, 0);
			for(ll j = 0; j < (x >> 1); j ++, w = w * wn) {
				complex A = a[i + j], B = a[i + (x >> 1) + j];
				a[i + j] = A + B * w;
				a[i + (x >> 1) + j] = A - B * w;
			}
		}
	}
}
int main() {
	scanf("%s %s", s, t);
	n = strlen(s), m = strlen(t);
	while(siz < n + m) siz <<= 1, l ++;
	for(ll i = 0; i < siz; i ++) {
		r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
	}
	for(ll i = 0; i < n; i ++) {
		A[i] = complex(s[n - 1 - i] - '0', 0);
		ss[i] = s[i] - '0';
		if(i > 0) ss[i] += ss[i - 1];
	}
	for(ll i = 0; i < m; i ++) {
		B[i] = complex(t[i] - '0', 0);
		ts += t[i] - '0';
	}
	FFT(A, 1);
	FFT(B, 1);
	for(ll i = 0; i < siz; i ++) {
		A[i] = A[i] * B[i];
	}
	FFT(A, -1);
	for(ll i = 0; i <= n - m; i ++) {
		ll num = A[n - 1 - i].x / siz + 0.5;
		ans = min(ans, ss[i + m - 1] - (i == 0 ? 0 : ss[i - 1]) + ts - 2 * num);
	}
	printf("%lld", ans);
}
