#include <cstdio>
#include <algorithm>
#include <cctype>
using namespace std;
#define ll long long
#define N 20
ll n;
ll b[(1<<N)+10], w[(1<<N)+10];
ll sum[(1<<N)+10][2];
ll f[(1<<N)+10];
inline char gc() {
	const int BUF = 1e6;
	static char ch[BUF], *l, *r;
	return (l == r && (r = (l = ch) + fread(ch, 1, BUF, stdin), l == r)) ? EOF : *l++;
}
template <typename T> inline void read(T &x) {
	x = 0; int f = 1; char c = gc();
	for (; !isdigit(c); c = gc()) if (c == '-') f = -f;
	for (; isdigit(c); c = gc()) x = (x << 1) + (x << 3) + (c ^ 48);
	x *= f;
}
inline ll min(ll x, ll y) {return x > y ? y : x;}
int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	read(n);
	for(ll i = 0; i < (1<<n); i++) {
		read(b[i]);
		sum[i][0] = b[i];
	}
	for(ll i = 0; i < (1<<n); i++) {
		read(w[i]);
		sum[i][1] = w[i];
	}
	for(ll i = 0; i < n; i++) {
		for(ll s = 0; s < (1<<n); s++) if(s & (1<<i)) {
			sum[s][0] += sum[s ^ (1<<i)][0];
			sum[s][1] += sum[s ^ (1<<i)][1];
		}
	}
	for(ll s = 0; s < (1<<n); s++) {
		f[s] = 1e15;
	}
	f[0] = min(b[0], w[0]);
	for(ll s = 0; s < (1<<n); s++) {
		for(ll i = 0; i < n; i++) if(s & (1<<i)) {
			f[s] = min(f[s], f[s ^ (1<<i)] + min(sum[s][1] - sum[s ^ (1<<i)][1], sum[s][0] - sum[s ^ (1<<i)][0]));
		}
	}
	printf("%lld", f[(1<<n)-1]);
}
