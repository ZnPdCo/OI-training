/**
 * @file 贪吃蛇.cpp 
 * @tag: #GMOJ#贪心
 * @author: ZnPdCo
 * @date: 2024-01-16 19:53:25
 * @problem: https://gmoj.net/senior/#main/show/6858
 **/
#include <cstdio>
#include <deque>
#define ll long long
#define N 1000010
using namespace std;
ll T;
ll n, k;
ll a[N];
struct node {
	ll len, id;
	node(ll x=0,ll y=0){len=x,id=y;}
	friend bool operator>(const node &x, const node &y) {
		if(x.len == y.len) return x.id > y.id;
		return x.len > y.len;
	}
};
int main() {
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
	scanf("%lld", &T);
	for(ll cas = 1; cas <= T; cas++) {
		if(cas == 1) {
			scanf("%lld", &n);
			for(ll i = 1; i <= n; i++) {
				scanf("%lld", &a[i]);
			}
		} else {
			scanf("%lld", &k);
			for(ll i = 1; i <= k; i++) {
				ll x, y;
				scanf("%lld %lld", &x, &y);
				a[x] = y;
			}
		}
		
		deque<node> q1, q2;
		
		for(ll i = 1; i <= n; i++) {
			q1.push_back(node(a[i], i));
		}
		
		// 阶段1
		while(true) {
			if(q1.size() + q2.size() == 2) {
				printf("1\n");
				break;
			}
			ll x, id, y;
			y = q1.front().len, q1.pop_front();
			if(q2.empty() || (!q1.empty() && q1.back() > q2.back())) {
				x = q1.back().len, id = q1.back().id, q1.pop_back();
			} else {
				x = q2.back().len, id = q2.back().id, q2.pop_back();
			}
			node now(x-y, id);
			if(now > q1.front()) {
				q2.push_front(now);
			} else {
				// 阶段2
				ll cnt = 1;
				ll ans = q1.size() + q2.size() + 2;
				while(true) {
					cnt ^= 1;
					
					if(q1.size() + q2.size() + 1 == 2) {
						ans -= cnt;
						break;
					}
					if(q2.empty() || (!q1.empty() && q1.back() > q2.back())) {
						x = q1.back().len, id = q1.back().id, q1.pop_back();
					} else {
						x = q2.back().len, id = q2.back().id, q2.pop_back();
					}
					
					now = node(x-now.len, id);
					if((q1.empty() || q1.front() > now) && (q2.empty() || q2.front() > now));
					else {
						ans -= cnt;
						break;
					}
				}
				printf("%lld\n", ans);
				break;
			}
		}
	}
}
