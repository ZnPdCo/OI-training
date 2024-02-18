#include<bits/stdc++.h>
using namespace std;
#define re register
#define inl inline
#define ll long long
ll ffff;inl void read(ll &ret){ret=0;ffff=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')ffff=-ffff;
	ch=getchar();}while(ch>='0'&&ch<='9'){ret=(ret<<1)+(ret<<3)+ch-'0';ch=getchar();}ret*=ffff;}
ll a[100005],t[100005][2],f[100005][2],sum;
int main()
{
	ll n,g,r,q;
	read(n),read(g),read(r);
	for(re int i=1;i<=n+1;i++)
	{
		read(a[i]);
	}
	read(q);
	ll x;
	while(q--)
	{
		read(x);
		sum=0;
		for(re int i=1;i<=n+1;i++)
		{
			x+=a[i];
			if(x%(g+r)>=g)
			{
				x=(x/(g+r)+1)*(g+r);
				if(t[i][0])
				{
					x=t[i][0]+x-t[i][1];
					break;
				}
				else
				f[++sum][0]=i,f[sum][1]=x;
			}
		}
		for(int i=1;i<=sum;i++)
		{
			t[f[i][0]][0]=x;
			t[f[i][0]][1]=f[i][1];
		}
		printf("%lld\n",x);
	}
	return 0;
}