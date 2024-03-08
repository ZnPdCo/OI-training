#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define i28 __int128
#define son(x, y) trie[x].son[y]
#define cost(x) trie[x].cost
#define mn(x) trie[x].mn
#define get(x, y) ((x & ((i28)1 << y)) != 0)
#define inf 1e18
const ll N = 1e5 * 120 + 10;


void read(i28 &x){
	// read a __int128 variable
	char c; bool f = 0;
	while(((c = getchar()) < '0' || c > '9') && c != '-');
	if(c == '-'){f = 1; c = getchar();}
	x = c - '0';
	while((c = getchar()) >= '0' && c <= '9')x = x * 10 + c - '0';
	if(f) x = -x;
}
void write(i28 x){
	// print a __int128 variable
	if(x < 0){putchar('-'); x = -x;}
	if(x > 9)write(x / 10);
	putchar(x % 10 + '0');
}

ll c, T, n, m, k;

i28 a[N], mx;
ll b[N];

struct node {
	ll son[2], cost;
	i28 mn;
	void init() {
		cost = 0;
		son[0] = 0;
		son[1] = 0;
		mn = (i28)1 << k;
	}
} trie[N];
ll cnt;


void insert(i28 x, ll y) {
	ll p = 1;
	cost(p) += y;
	mn(p) = min(mn(p), x);
	for(ll i = k - 1; i >= 0; i--) {
		if(!son(p, get(x, i))) {
			son(p, get(x, i)) = ++cnt;
			trie[cnt].init();
		}
		p = son(p, get(x, i));
		cost(p) += y;
		mn(p) = min(mn(p), x);
	}
}

void dfs(ll p, ll use, ll i, i28 x, i28 minn, i28 tot) {
	i28 bit = ((i28)1 << i), mask = bit - 1;
	i28 x0 = x, x1 = x0 | bit;
	i28 mxx0 = x | mask, mxx1 = mxx0 | bit | mask;
	i28 tot0 = tot, tot1 = tot | bit;
	
	if(i < 0) {
		mx = max(mx, tot);
		return;
	}
	
	if(!p)
		return;
	
	bool flag = 1;
	
	// x取0
	if(cost(son(p, 0)) <= use) {
		if(mxx0 + min(mn(son(p, 0)), minn) < tot1) {
			if(min(mn(son(p, 0)), minn) < ((i28)1 << k))
				mx = max(mx, min(mn(son(p, 0)), minn) + mxx0);
		} else {
			dfs(son(p, 1), use - cost(son(p, 0)), i - 1, x0, min(mn(son(p, 0)), minn), tot1), flag = 0;
		}
	}
	
	
	// x取1
	if(cost(son(p, 1)) <= use) {
		if(mxx1 + min(mn(son(p, 1)), minn) < tot1) {
			if(min(mn(son(p, 1)), minn) < ((i28)1 << k))
				mx = max(mx, min(mn(son(p, 1)), minn) + mxx1);
		} else {
			dfs(son(p, 0), use - cost(son(p, 1)), i - 1, x1, min(mn(son(p, 1)), minn), tot1), flag = 0;
		}
	}
		
	if(flag) {
		if(mxx0 + minn < tot0) {
			if(minn < ((i28)1 << k))
				mx = max(mx, minn + mxx0);
		} else {
			dfs(son(p, 0), use, i - 1, x0, minn, tot0);
		}
		
		if(mxx1 + minn < tot0) {
			if(minn < ((i28)1 << k))
				mx = max(mx, minn + mxx1);
		} else {
			dfs(son(p, 1), use, i - 1, x1, minn, tot0);
		}
	}
}

int main(){
	scanf("%lld %lld", &c, &T);
	while(T--) {
		scanf("%lld %lld %lld", &n, &m, &k);
		mx = 0, cnt = 1;
		trie[0].init(), trie[1].init();
		ll sumb = 0;
		i28 mna = (i28)1 << k;
		for(ll i = 1; i <= n; i++)
			read(a[i]), mna = min(mna, a[i]);
		for(ll i = 1; i <= n; i++)
			scanf("%lld", &b[i]), sumb += b[i];
		if(sumb <= m)
			mx = ((i28)1 << k) - 1 + mna;
		for(ll i = 1; i <= n; i++)
			insert(a[i], b[i]);
		dfs(1, m, k - 1, 0, (i28)1 << k, 0);
		write(mx);
		putchar('\n');
	}
	return 0;
}

