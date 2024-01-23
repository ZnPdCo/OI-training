#include <cstdio>
#include <cstring>
#include <deque>
#include <queue>
using namespace std;
using ll = long long;
const ll M = 2000010, N = 310, K = 2*N;
ll T;
ll n, m, k;
ll a[M];

ll in[K];		// 每种类型的卡牌存在哪儿
ll sp;			// 特殊栈
queue<ll> fre;	// 可用栈
deque<ll> d[N];

ll cnt, ans[2*M][3];


void opt1(ll s, ll x) {
	ans[++cnt][0] = 1;
	ans[cnt][1] = s;
	if(d[s].size() > 0 && d[s].back() == x) {
		d[s].pop_back();
		if(d[s].size() < 2 && s != sp) fre.push(s);
		in[x] = 0;
	} else {
		d[s].push_back(x);
		in[x] = s;
	}
}
void opt2(ll s1, ll s2) {
	ans[++cnt][0] = 2;
	ans[cnt][1] = s1;
	ans[cnt][2] = s2;

	in[d[s1].front()] = 0;
	d[s1].pop_front(), d[s2].pop_front();
	if(d[s1].size() < 2) fre.push(s1);
}


int main() {
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld %lld %lld", &n, &m, &k);
		cnt = 0;
		sp = n;
		memset(in, 0, sizeof in);
		while(!fre.empty()) fre.pop();
		for(ll i = 1; i < n; i++) fre.push(i), fre.push(i);

		for(ll i = 1; i <= m; i++) {
			scanf("%lld", &a[i]);
		}
		for(ll i = 1; i <= m; i++) {
			ll s = in[a[i]];
			if(s) {
				if(a[i] == d[s].back()) {
					opt1(s, a[i]);
				} else if(a[i] == d[s].front()) {
					opt1(sp, a[i]);
					opt2(s, sp);
				}
			} else if(!fre.empty()) {
				s = fre.front();
				fre.pop();
				opt1(s, a[i]);
			} else {
				ll u = 0, v = 0, x = 0;
				for(ll j = i + 1; j <= m; j++) {
					if(a[i] == a[j]) break;
					if(a[j] == d[in[a[j]]].front()) {
						u = a[j];
						x = in[u];
						v = d[x].back();
						break;
					}
				}
				if(u == 0) {
					opt1(sp, a[i]);
				} else {
					for(ll j = i + 1; j <= m; j++) {
						if(a[j] == u) {				// u 比 v 先出现
							opt1(x, a[i]);
							break;
						} else if(a[j] == v) {		// v 比 u 先出现
							opt1(sp, a[i]);
							fre.push(sp);			// 调了我一晚上
							sp = x;
							break;
						}
					}
				}
			}
		}
		printf("%lld\n", cnt);
		for(ll i = 1; i <= cnt; i++) {
			if(ans[i][0] == 1) printf("1 %lld\n", ans[i][1]);
			if(ans[i][0] == 2) printf("2 %lld %lld\n", ans[i][1],  ans[i][2]);
		}
	}
}