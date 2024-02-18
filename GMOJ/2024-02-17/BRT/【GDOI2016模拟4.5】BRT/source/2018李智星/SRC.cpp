#include<cstdio>
#define N 100005
#define ll long long
ll n,g,r,a[N],pre[N],f[N];
inline ll read()
{
	int ret=0,f=1;
	char ch=getchar();
	for (;ch<'0'||ch>'9';) f=ch=='-'?-1:1,ch=getchar();
	for (;ch>='0'&&ch<='9';) ret=ret*10+(ch^'0'),ch=getchar();
	return ret*f;
}
int main()
{
	n=read()+1,g=read(),r=read()+g;
	for (int i=1;i<=n;++i) a[i]=read();
	for (int i=n;i>=1;--i) pre[i]=pre[i+1]+a[i];
	int T=read();
	f[n-1]=a[n];
	for (int i=n-2;i;--i)
	{
		f[i]=pre[i+1];
		for (int j=i+1;j<n;++j)
		if ((pre[i+1]-pre[j+1])%r>=g)
		{
			f[i]=pre[i+1]-pre[j+1]+r-(pre[i+1]-pre[j+1])%r+f[j];
			break;
		}
	}
	for (;T--;)
	{
		ll w=read(),p=w%r,sum=0;
		for (int i=1;i<n;++i)
		{
			p+=a[i],p%=r,sum+=a[i];
			if (p>=g)
			{
				w+=f[i]+r-p-a[n];
				break;
			}
		}
		printf("%lld\n",w+sum+a[n]);
	}
	return 0;
}