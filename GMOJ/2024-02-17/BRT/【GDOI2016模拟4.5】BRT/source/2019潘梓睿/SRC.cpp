#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll tot,f[2000005],son[2000005][2],l[2000005],r[2000005],n,G,R,a[100005],s[100005],q,t,ans,v;

ll find(ll k,ll x,ll y)
{
	if(k==0)return 1e9;
	ll mid=(l[k]+r[k])/2;ll sum=1e9;
	if(x<=l[k]&&y>=r[k])return f[k];
	if(x<=mid)sum=min(sum,find(son[k][0],x,y));
	if(y>=mid)sum=min(sum,find(son[k][1],x,y));
	return sum;
}
void join(ll k,ll x,ll y)
{
	if(l[k]==r[k])
	{
		f[k]=min(f[k],y);
		return;
	}
	ll mid=(l[k]+r[k])/2;
	if(x<=mid)
	{
		if(!son[k][0])
		{
			son[k][0]=++tot;
			l[tot]=l[k];r[tot]=mid;f[tot]=1e9;
		}
		join(son[k][0],x,y);
		f[k]=min(f[k],f[son[k][0]]);
	}else
	{
		if(!son[k][1])
		{
			son[k][1]=++tot;
			l[tot]=mid+1;r[tot]=r[k];f[tot]=1e9;
		}
		join(son[k][1],x,y);
		f[k]=min(f[k],f[son[k][1]]);
	}
}
int main()
{
	scanf("%lld%lld%lld",&n,&G,&R);
	for(int i=0;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)a[i]=a[i-1]+a[i];
	tot=1;f[1]=1e9;l[1]=0;r[1]=G+R-1;
	for(int i=n-1;i>=0;i--)
	{
		ll y=(a[i]+G+R-1)%(G+R),x=(a[i]+G)%(G+R);
		if(y>=x)v=find(1,x,y);
		else v=min(find((ll) 1,x,G+R-1),find((ll) 1,0,y));
		if(v==1e9)s[i]=a[n]-a[i];
		else s[i]=a[v]-a[i]+s[v]+(G+R)-(a[v]-a[i])%(G+R);
		join(1,a[i]%(G+R),i);
	}
	scanf("%lld",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%lld",&t);
		ll y=(G+R-t%(G+R)-1)%(G+R),x=(G+G+R-t%(G+R))%(G+R);
		if(y>=x)v=find(1,x,y);
		else v=min(find((ll)1,x,G+R-1),find((ll)1,0,y));
		if(v==1e9)ans=a[n]+t;
		else ans=(G+R)-(a[v]+t)%(G+R)+s[v]+a[v]+t;
		printf("%lld\n",ans);
	}
}