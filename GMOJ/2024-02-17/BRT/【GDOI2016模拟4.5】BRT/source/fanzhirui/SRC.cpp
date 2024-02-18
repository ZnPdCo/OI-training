#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
const int up=100000*30,
			N=100000;
int son[up][2],f[up];
int G,g,n,root,tot;
ll s[N],next[N],val[N];
void tree_insert(int l,int r,int &root,int wz,int y)
{
	if (root==0) root=++tot;
	if (l==r)
	{
		f[root]=y;
		return;
	}
	int mid=(l+r)>>1;
	if (wz<=mid) tree_insert(l,mid,son[root][0],wz,y); else
	tree_insert(mid+1,r,son[root][1],wz,y);
	f[root]=min(f[son[root][0]],f[son[root][1]]);
}
int tree_get(int l,int r,int root,int x,int y)
{
	if (root==0) return f[0];
	if (l==x && r==y) return f[root];
	int mid=(l+r)>>1;
	if (y<=mid) return tree_get(l,mid,son[root][0],x,y); else
	if (x>mid) return tree_get(mid+1,r,son[root][1],x,y); else
	return min(tree_get(l,mid,son[root][0],x,mid),tree_get(mid+1,r,son[root][1],mid+1,y));
}
int get(ll l,ll r)
{
	l=(l%G+G)%G;
	r=(r%G+G)%G;
	if (l<=r) return tree_get(0,G-1,1,l,r); else
	return min(tree_get(0,G-1,1,0,r),tree_get(0,G-1,1,l,G-1));
}
ll to_lim(ll x)
{
	if (x%G<g) return x; else return (x/G+1)*G;
}
int main()
{
	scanf("%d%d%d",&n,&g,&G);
	G+=g;
	fo(i,1,n+1) scanf("%lld",&s[i]);
	fo(i,1,n+1) s[i]+=s[i-1];
	f[0]=n+1;
	tot=1;
	f[1]=n+1;
	int root=1;
	fd(i,n,1)
	{
		next[i]=get(s[i]%G+g,s[i]%G+G-1);
		val[i]=(next[i]==n+1?s[next[i]]-s[i]:to_lim(s[next[i]]-s[i]))+val[next[i]];
		tree_insert(0,G-1,root,s[i]%G,i);
	}
	int q;
	scanf("%d",&q);
	fo(i,1,q)
	{
		ll x;
		scanf("%lld",&x);
		int pre=get(-x%G+g,-x%G+G-1);
		if (g==0) printf("%lld\n",x+s[n+1]); else
		printf("%lld\n",(pre==n+1?x+s[pre]:to_lim(x+s[pre]))+val[pre]);
	}
}