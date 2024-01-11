/**
 * @file 蚯蚓.cpp 
 * @tag: #GMOJ#队列#数学
 * @author: ZnPdCo
 * @date: 2024-01-11 20:57:17
 * @problem: https://gmoj.net/senior/#main/show/4907
 **/
#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
#define N 8000010
ll n, m, q, u, v, t;

ll a1[N], h1=1, t1, a2[N], h2=1, t2, a3[N], h3=1, t3, tot;
bool cmp(ll x, ll y) {
	return x > y;
}
int main() {
	freopen("earthworm.in", "r", stdin);
	freopen("earthworm.out", "w", stdout);
	
	scanf("%lld %lld %lld %lld %lld %lld", &n, &m, &q, &u, &v, &t);
	for(ll i = 1; i <= n; i++) {
		scanf("%lld", &a1[++t1]);
	}
	sort(a1+1, a1+1+n, cmp);
	for(ll i = 1; i <= m; i++) {
		ll head1 = h1<=t1?a1[h1] + q*(i-1):-1;
		ll head2 = h2<=t2?a2[h2] + q*(i-1):-1;
		ll head3 = h3<=t3?a3[h3] + q*(i-1):-1;
		if(head1 >= head2 && head1 >= head3) {
			if(i % t == 0) printf("%lld ", head1);
			h1++;
			a2[++t2] = head1 * u / v - q*i;
			a3[++t3] = head1 - head1 * u / v - q*i;
		} else if(head2 >= head1 && head2 >= head3) {
			if(i % t == 0) printf("%lld ", head2);
			h2++;
			a2[++t2] = head2 * u / v - q*i;
			a3[++t3] = head2 - head2 * u / v - q*i;
		} else {
			if(i % t == 0) printf("%lld ", head3);
			h3++;
			a2[++t2] = head3 * u / v - q*i;
			a3[++t3] = head3 - head3 * u / v - q*i;
		}
	}
	printf("\n");
	for(ll i = 1; i <= n+m; i++) {
		ll head1 = h1<=t1?a1[h1] + q*m:-1;
		ll head2 = h2<=t2?a2[h2] + q*m:-1;
		ll head3 = h3<=t3?a3[h3] + q*m:-1;
		if(head1 >= head2 && head1 >= head3) {
			if(i % t == 0) printf("%lld ", head1);
			h1++;
		} else if(head2 >= head1 && head2 >= head3) {
			if(i % t == 0) printf("%lld ", head2);
			h2++;
		} else {
			if(i % t == 0) printf("%lld ", head3);
			h3++;
		}
	}
}
