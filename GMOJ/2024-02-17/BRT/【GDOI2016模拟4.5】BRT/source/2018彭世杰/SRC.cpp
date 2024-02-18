#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

template < class T >
inline void read(T &x)
{
	char ch = getchar(); x = 0; int fg = 1;
	for(;ch < '0' || ch > '9';) fg = ch == '-' ? -1 : 1, ch = getchar();
	for(;ch >= '0' && ch <= '9';) x = x * 10 + (ch ^ '0'), ch = getchar(); x *= fg;
}

typedef long long ll;

const int N = 100010;

struct SGT{ ll tag,col; int ls,rs; } t[N * 100];
ll n,g,r,a[N],sum[N],f[N],m,x,ans,tot = 1;
int root = 1;

#define ls(p) t[p].ls
#define rs(p) t[p].rs

void pushdown(int p)
{
	if(!t[p].tag) return;
	if(!ls(p)) ls(p) = ++tot; if(!rs(p)) rs(p) = ++tot;
	t[ls(p)].tag = t[rs(p)].tag = t[ls(p)].col = t[rs(p)].col = t[p].tag;
	t[p].tag = 0;
}
void change(int &p,ll l,ll r,int x,ll tl,ll tr)
{
	if(!p) p = ++tot;
	if(l <= tl && tr <= r) { t[p].col = t[p].tag = x; return; }
	int mid = tl + tr >> 1; pushdown(p);
	if(mid >= l) change(ls(p),l,r,x,tl,mid);
	if(mid < r) change(rs(p),l,r,x,mid + 1,tr);
}
int query(int p,ll x,ll tl,ll tr)
{
	if(!p) return 0;
	if(tl == tr) return t[p].col;
	int mid = tl + tr >> 1; pushdown(p);
	return x <= mid ? query(ls(p),x,tl,mid) : query(rs(p),x,mid + 1,tr);
}

int main()
{
//	freopen("brt10.in","r",stdin);
//	freopen("T3.out","w",stdout);
	
	read(n), read(g), read(r);
	ll G = g + r; 
	for(int i = 1;i <= n + 1; ++ i)
		read(a[i]), sum[i] = sum[i - 1] + a[i];
	f[n] = a[n + 1];
	
	for(int i = n - 1;i >= 0; -- i)
	{
		ll res = sum[i + 1] % G;
		int p = (G - sum[i] % G) % G;
		if(res <= g) change(root,g - res,G - res - 1,i + 1,0,G - 1);
		else change(root,0,G - res - 1,i + 1,0,G - 1),
				change(root,G - res + g,G - 1,i + 1,0,G - 1);
		ll wait = query(root,p,0,G - 1);
		if(wait == 0) f[i] = sum[n + 1] - sum[i];
		else f[i] = sum[wait] - sum[i] + G - (sum[wait] - sum[i]) % G + f[wait];
	}
	
	read(m); for(ll x,p;m--;)
	{
		read(x), p = query(1,x % (G),0,G - 1);
		if(p == 0) ans = sum[n + 1] + x;
		else ans = x + sum[p] + G - (x + sum[p]) % G + f[p];
		printf("%lld\n",ans);
	}
	

	fclose(stdin); fclose(stdout);
	return 0;
}