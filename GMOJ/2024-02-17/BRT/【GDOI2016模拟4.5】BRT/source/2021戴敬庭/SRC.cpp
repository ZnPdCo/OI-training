//#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define rg register int
#define ll long long
using namespace std;
const int N=100011;
int n,g,r,T;
int a[N];
ll f[N];
int main()
{
//	freopen("a.in","r",stdin);
//	freopen("","w",stdout);
	scanf("%d%d%d",&n,&g,&r);
	for(rg i=1;i<=n+1;i++) scanf("%d",&a[i]);
	for(rg i=n-1;i>=1;i--)
	{
		ll t=0;
		for(rg j=i+1;j<=n;j++)
		{
			t+=a[j];
			int now=t%(g+r);
			if(now>=g) 
			{
				t+=g+r-now+f[j];
				break;
			}
		}
		f[i]=t;
	}
//	printf("%d\n",f[1]);
//	return 0;
	scanf("%d",&T);
	while(T--)
	{
		ll t;
		scanf("%lld",&t);
//		t=723;
		for(rg i=1;i<=n;i++)
		{
			t+=a[i];
			int now=t%(g+r);
			if(now>=g) 
			{
				t+=g+r-now+f[i];
				break;
			}
		}
		t+=a[n+1];
		printf("%lld\n",t);
//		return 0;
	}
	return 0;
}
