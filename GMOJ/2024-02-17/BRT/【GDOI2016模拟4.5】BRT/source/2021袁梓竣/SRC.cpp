#include <bits/stdc++.h>
#define ll long long
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
using namespace std;
const int N = 100005;
const int NN = 100000;
int n,Green,Red,tot;
ll a[N],qzh[N],f[N];
int mintree[N*4],maxtree[N*4];
void build(int l,int r,int index)
{
	if(l == r)
	{
		mintree[index] = qzh[l];
		maxtree[index] = qzh[l];
		return ;
	}
	int mid = (l+r)/2;
	build(l,mid,index*2);
	build(mid+1,r,index*2+1);
	mintree[index] = min(mintree[index*2],mintree[index*2+1]);
	maxtree[index] = max(maxtree[index*2],maxtree[index*2+1]);
	return ;
}
int askval,askl,askr;
const int INF = 2147483647;
//Ñ¯ÎÊÂú×ãÌõ¼þµÄ×îÇ°ÃæµÄµã 
int mod1(ll x)
{
	if(x < 0) return x+tot;
	if(x >= tot) return x-tot;
	return x;
}
int askmin(int l,int r,int index)
{
	if(l > askr or r < askl) return INF;
	if(mintree[index] > askval) return INF;
	if(l == r) return l;
	int mid = (l+r)/2;
	int res1 = askmin(l,mid,index*2);
	if(res1 != INF) return res1;
	return askmin(mid+1,r,index*2+1);
}
int askmax(int l,int r,int index)
{
	if(l > askr or r < askl) return INF;
	if(maxtree[index] < askval) return INF;
	if(l == r) return l;
	int mid = (l+r)/2;
	int res1 = askmax(l,mid,index*2);
	if(res1 != INF) return res1;
	return askmax(mid+1,r,index*2+1);
}
int T;
int main()
{
	scanf("%d%d%d",&n,&Green,&Red);tot = Green+Red;
	for(int i = 1;i <= n+1;i++) scanf("%lld",&a[i]);
	f[n] = a[n+1];
	for(int i = n-1;i >= 1;i--)
	{
		ll now = a[i+1]%tot,wat = a[i+1];
		for(int j = i+1;j <= n;j++)
		{
			if(now >= Green) {f[i]=(wat/tot+1)*tot+f[j];break;}
			now = (now+a[j+1])%tot,wat += a[j+1];
		}
		if(!f[i]) f[i]=wat;
	}
	for(int i = 1;i <= n;i++) qzh[i]=(qzh[i-1]+a[i])%tot;
	build(1,NN,1);
	scanf("%d",&T);
	while(T--)
	{
		ll x;
		scanf("%lld",&x);
		ll now = x,fl=0;
		for(int i = 1;i <= n;i++)
		{
			now += a[i];
			if(now%tot >= Green)
			{
				now = (now/tot+1)*tot+f[i];
				printf("%lld\n",now);
				fl=1;
				break;
			}
		}
		if(!fl) printf("%lld\n",now+a[n+1]);
	}
	return 0;
}
