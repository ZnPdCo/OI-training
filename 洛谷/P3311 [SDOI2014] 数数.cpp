#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define N 2000
#define P 1000000007
char a[N], s[N];
ll n, m;
namespace ACAM {
	ll trie[N][10], cnt;
	bool tail[N];
	ll fail[N];
	void insert() {
		ll p = 0;
		for(ll i = 1; s[i] != '\0'; i++) {
			if(!trie[p][s[i]-'0']) {
				trie[p][s[i]-'0'] = ++cnt;
			}
			p = trie[p][s[i]-'0'];
		}
		tail[p] = 1;
	}
	void makeFail() {
		queue<ll> q;
		for(ll i = 0; i <= 9; i++) if(trie[0][i]) q.push(trie[0][i]);
		while(!q.empty()) {
			ll p = q.front();
			q.pop();
			tail[p] |= tail[fail[p]];
			for(ll i = 0; i <= 9; i++) {
				if(trie[p][i]) {
					fail[trie[p][i]] = trie[fail[p]][i];
					q.push(trie[p][i]);
				} else {
					trie[p][i] = trie[fail[p]][i];
				}
			}
		}
	}
}

namespace NumberDP {
	using namespace ACAM;
	ll dp[N][N][2][2];
	ll dfs(ll x, ll p, bool f, bool z) {
		if(x == n+1) return !z;
		if(dp[x][p][f][z]) return dp[x][p][f][z];
		if(z) p = 0;
		ll res = 0;
		ll to = f?(a[x]-'0'):9;
		for(ll i = 0; i <= to; i++) {
			if(!tail[trie[p][i]]) {
				(res += dfs(x+1, trie[p][i], f && (i == to), z && (i == 0))) %= P;
			}
		}
		return dp[x][p][f][z] = res;
	}
}
int main() {
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
	scanf("%s", a+1);
	n = strlen(a+1);
	scanf("%lld", &m);
	for(ll i = 1; i <= m; i++) {
		scanf("%s", s+1);
		ACAM::insert();
	}
	ACAM::makeFail();
	printf("%lld", NumberDP::dfs(1, 0, 1, 1));
}
