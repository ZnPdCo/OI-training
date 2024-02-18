#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
long long n,g,r,a[N],f[N];
int Q;
int main()
{
	scanf("%lld%lld%lld",&n,&g,&r);
	for(int i=1;i<=n+1;i++)scanf("%lld",&a[i]);
	for(int i=n;i;i--)
	{
		int s=0;
		for(int j=i+1;j<=n;j++)
		{
			s=(s+a[j])%(g+r);
			f[i]+=a[j];
			if(s>=g)
			{
				f[i]+=f[j]+g+r-s;break;
			}
		}
	}
	scanf("%d",&Q);
	while(Q--)
	{
		long long s,ans=0;
		scanf("%lld",&s);ans=s+a[n+1],s%=(g+r);
		for(int i=1;i<=n;i++)
		{
			s=(s+a[i])%(r+g);
			ans+=a[i];
			if(s>=g)
			{
				ans+=r+g-s+f[i];break;
			}
		}
		printf("%lld\n",ans);
	}
}