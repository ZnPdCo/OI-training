#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define N 2000
char a[N], s[N];
ll n, m;
namespace ACAM {
	ll trie[1000010][10], cnt;
	bool tail[1000010];
	ll fail[1000010];
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
	void dfs(ll n, ll )
}
int main() {
	scanf("%s", a+1);
	n = strlen(a+1);
	scanf("%lld", &m);
	for(ll i = 1; i <= m; i++) {
		scanf("%s", s+1);
		ACAM::insert();
	}
	ACAM::makeFail();
	
}
