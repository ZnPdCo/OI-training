#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long
#define N 20
#define M 20000
#define P 1000000007
char s[N];
ll n, a, k, ans;

ll f[N][M][2];

map<ll, ll> zip;
ll unzip[M], cnt;

ll c[M];

struct node {
	ll x, y;
	node(ll xx=0,ll yy=0){x=xx,y=yy;}
	friend bool operator<(const node &x, const node &y) {
		return c[x.x] * c[x.y] < c[y.x] * c[y.y];
	} 
};

priority_queue<node> que;

int main() {
	scanf("%s %lld", s+1, &k);
	n = strlen(s+1);
	for(ll i = 1; i <= n; i++) {
		s[i] -= '0';
		a = a*10+s[i];
	}
	for(ll a1 = 1; ; a1 *= 2) {
		if(a1 > a) break;
		for(ll a2 = 1; ; a2 *= 3) {
			if(a1*a2 > a) break;
			for(ll a3 = 1; ; a3 *= 5) {
				if(a1*a2*a3 > a) break;
				for(ll a4 = 1; ; a4 *= 7) {
					if(a1*a2*a3*a4 > a) break;
					cnt++;
					unzip[cnt] = a1*a2*a3*a4;
					zip[a1*a2*a3*a4] = cnt;
				}
			}
		}
	}
		
	for(ll i = 1; i <= 9; i++) {
		if(i < s[1]) f[1][zip[i]][1]++;
		else if(i == s[1]) f[1][zip[i]][0]++;
	}
	
	for(ll i = 2; i <= n; i++) {
		for(ll j = 1; j <= cnt; j++) {
			for(ll k = 1; k <= 9; k++) {
				ll q = unzip[j];
				if(q % k != 0) continue;
				ll l = zip[q / k];
				if(k < s[i]) f[i][j][0] += f[i-1][l][1];
				else if(k == s[i]) f[i][j][1] += f[i-1][l][1];
				f[i][j][0] += f[i-1][l][0];
			}
		}
	}
	
	for(ll j = 1; j <= cnt; j++) {
		for(ll i = 1; i <= n; i++) {
			c[j] += f[i][j][0] + f[i][j][1];
		}
	}
	
	sort(c+1, c+1+cnt, [](const auto &x, const auto &y) {return x > y;});
	
	for(ll i = 1; i <= cnt; i++) {
		que.push(node(i, 1));
	}
	
	for(ll i = 1; i <= k; i++) {
		node u = que.top();
		que.pop();
		(ans += c[u.x] * c[u.y]) %= P;
		if(u.y < cnt) {
			que.push(node(u.x, u.y+1));
		}
	}
	
	printf("%lld", ans);
}
