/**
 * @file 计数.cpp 
 * @tag: #GMOJ #dp
 * @author: ZnPdCo
 * @date: 2023-12-23 16:00:01
 * @problem: https://gmoj.net/senior/#main/show/4630
 **/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
#define N 1810
ll n, k;
struct node {
	ll a[N], len;
	node(ll l = 1) {memset(a, 0, sizeof(a));len = l;}
	friend node operator+(const node &x, const node &y) {
		node z(max(x.len, y.len));
		for(ll i = 1; i <= z.len; i++) {
			z.a[i] += x.a[i] + y.a[i];
			if(z.a[i] >= 10) {
				z.a[i+1] += z.a[i] / 10;
				z.a[i] %= 10;
				if(i+1 > z.len) z.len++;
			}
		}
		return z;
	} 
	friend node operator*(const node &x, const ll &y) {
		node z(x.len);
		for(ll i = 1; i <= z.len; i++) {
			z.a[i] += x.a[i] * y;
			if(z.a[i] >= 10) {
				z.a[i+1] += z.a[i] / 10;
				z.a[i] %= 10;
				if(i+1 > z.len) z.len++;
			}
		}
		return z;
	} 
	void put() {
		bool flag = false;
		for(ll i = len; i >= 1; i--) {
			if(a[i] || flag) {
				flag = true;
				printf("%lld", a[i]);
			}
		}
	}
} f[2][2], ans;
// f[i][0] 最高位为0，f[i][1] 最高位不为0
int main() {
	scanf("%lld %lld", &n, &k);
	f[1][0].a[1] = 1;
	f[1][1].a[1] = k-1;
	for(ll i = 2; i <= n; i++) {
		memset(f[i%2][0].a, 0, sizeof(f[i%2][0].a));
		f[i%2][0].len = 1;
		memset(f[i%2][1].a, 0, sizeof(f[i%2][1].a));
		f[i%2][1].len = 1;
		
		f[i%2][0] = f[(i-1)%2][1];
		f[i%2][1] = (f[(i-1)%2][0] + f[(i-1)%2][1]) * (k-1ll);
	}
	ans = f[n%2][1];
	ans.put();
}
