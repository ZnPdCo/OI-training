#include<bits/stdc++.h>
#define rg register int
#define N 100005
#define inf 1999999999
#define ll long long
using namespace std;
int n,q,l,r,mid;
ll f[N],ans,d[N],t,a,b,c,s,sd[N];
int main()
{
//freopen("c.txt","r",stdin);
//freopen("2.txt","w",stdout);
	cin>>n>>a>>b;c=a+b;n+=2;
	for(rg i=1;i<n;i++)scanf("%lld",&d[i]),sd[i]=d[i]+sd[i-1];
	sd[n]=(1<<29);sd[n]*=sd[n];
	for(rg i=n-1;i>=1;i--)
	{
		s=0;
		l=i;r=n;
		while(l<r)
		{
			mid=(l+r+1)>>1;
			if(mid==n)break;
			if(sd[mid-1]-sd[i-1]>=a)r=mid-1;
			else l=mid;
		}
		s+=sd[l-1]-sd[i-1];
		for(rg j=l+1;j<=n;j++)
		{
			s+=d[j-1];
			if(j==n)
			{
				f[i]=s;
				break;
			}
			if(s%c>=a)
			{
				f[i]=f[j]+s-s%c+c;
				break;
			}
		}
	}
	cin>>q;
	while(q--)
	{
		scanf("%lld",&t);s=t;
		l=1;r=n-1;
		while(l<r)
		{
			mid=(l+r+1)>>1;
			if(mid==n-1)break;
			if(sd[mid-1]+s>=a)r=mid-1;
			else l=mid;
		}
		s+=sd[l-1];
		for(rg i=l;i<n;i++)
		{
			s+=d[i];
			if(i==n-1)
			{
				ans=s;
				break;
			}
			if(s%c>=a)
			{
				ans=f[i+1]+s-s%c+c;
				break;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}