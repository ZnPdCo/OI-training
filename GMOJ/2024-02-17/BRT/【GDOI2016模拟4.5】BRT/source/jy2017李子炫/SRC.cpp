#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long n,m,k,l,R,G,Q,a[200001],ans[200001],qz[200001],x,res;
long long pd(int x)
{
	long long res=0,cnt=0;
	for(register int i=x+1;i<=n;++i)
	{
		res+=a[i];cnt+=a[i];if(res>=(G+R)) res%=(G+R);
		if(res>=G) return ans[i]+cnt+(G+R-res);
	}
	return cnt+ans[n];	
}
int main()
{
	//freopen("a.in","r",stdin);
	scanf("%lld%lld%lld",&n,&G,&R);
	for(register int i=1;i<=n+1;++i) scanf("%lld",&a[i]);
	ans[n]=a[n+1];
	for(register int i=n-1;i>=1;--i) ans[i]=pd(i);
	scanf("%d",&m);
	for(register int i=1;i<=m;++i)
	{
		scanf("%lld",&x);
		int pd=1;res=x;
		for(register int j=1;j<=n;++j)
		{
			x+=a[j];res+=a[j];if(res>=(G+R)) res%=(G+R);
			if(res>=G){pd=0; printf("%lld\n",ans[j]+x+(G+R-res));break;}
		}
		if(pd==1)printf("%lld\n",x+a[n+1]);
	}
}