#include<cstdio>
using namespace std;
int n,g,r,q,all,a[100010],sum;
long long t,f[100010];
int main()
{
	scanf("%d%d%d",&n,&g,&r);all=g+r;
	for (int i=1;i<=n+1;i++) scanf("%d",&a[i]);
	f[n]=a[n+1];
	for (int i=n-1;i>=1;i--)
	{
		sum=0;
		for (int j=i+1;j<=n;j++)
		{
			sum+=a[j];
			if (sum%all>=g)
			{
				f[i]=sum+(all-sum%all)+f[j];
				break;
			}
		}
		if (sum%all<g) f[i]=sum+a[n+1];
	}
	scanf("%d",&q);
	for (int i=1;i<=q;i++)
	{
		scanf("%d",&t);
		for (int j=1;j<=n;j++)
		{
			t+=a[j];
			if (t%all>=g)
			{
				printf("%lld\n",t+(all-t%all)+f[j]);
				break;
			}
		}
		if (t%all<g) printf("%lld\n",t+a[n+1]);
	}
	return 0;
}