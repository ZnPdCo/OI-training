#include<cstdio>
#include<iostream>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

typedef long long ll;

const int maxn=(1e5)+5;

int n;
ll g,r,a[maxn],Sa[maxn],Sam[maxn],L;

int sum,son[20*maxn][2];
ll tr[20*maxn];
void dfsxg(int k,ll l,ll r,ll x,ll wz)
{
	if (l==r)
	{
		tr[k]=wz;
		return;
	}
	int t1=(l+r)>>1;
	if (x<=t1)
	{
		if (!son[k][0]) son[k][0]=++sum, tr[sum]=n+1;
		dfsxg(son[k][0],l,t1,x,wz);
	} else
	{
		if (!son[k][1]) son[k][1]=++sum, tr[sum]=n+1;
		dfsxg(son[k][1],t1+1,r,x,wz);
	}
	tr[k]=min(tr[k],min(tr[son[k][0]],tr[son[k][1]]));
}
int dfscx(int k,ll l,ll r,ll x,ll y)
{
	if (x>y || !k) return n+1;
	if (l==x && r==y) return tr[k];
	int sl=son[k][0], sr=son[k][1], t1=(l+r)>>1;
	if (y<=t1) return dfscx(sl,l,t1,x,y);
		else if (x>t1) return dfscx(sr,t1+1,r,x,y);
			else return min(dfscx(sl,l,t1,x,t1),dfscx(sr,t1+1,r,t1+1,y));
}

ll RE[maxn];
void Pre()
{
	tr[0]=n+1;
	sum=1;
	fd(i,n,1)
	{
		int wz=min(dfscx(1,0,L-1,g+Sam[i],L-1),
				   dfscx(1,0,L-1,max(g+Sam[i]-L,(ll)0),Sam[i]-1) );
		if (wz>n) RE[i]=Sa[wz]-Sa[i];
			else RE[i]=Sa[wz]-Sa[i]+ L-(Sa[wz]-Sa[i])%L +RE[wz];
		dfsxg(1,0,L-1,Sam[i],i);
	}
}

int Q,st;
int main()
{
	scanf("%d %d %d",&n,&g,&r);
	L=g+r;
	fo(i,0,n)
	{
		scanf("%lld",&a[i]);
		if (i) Sa[i]=Sa[i-1]+a[i-1], Sam[i]=(Sam[i-1]+a[i-1])%L;
	}
	Sa[n+1]=Sa[n]+a[n];
	Sam[n+1]=(Sam[n]+a[n])%L;
	
	Pre();
	
	scanf("%d",&Q);
	while (Q--)
	{
		scanf("%lld",&st);
		ll stm=st%L;
		int wz=min(dfscx(1,0,L-1,max(g-stm,(ll)0),L-1-stm),
				   dfscx(1,0,L-1,max(L+g-stm,(ll)0),min(2*L-1-stm,L-1)) );
		if (wz>n) printf("%lld\n",st+Sa[n+1]);
			else printf("%lld\n",st+Sa[wz]+ L-(st+Sa[wz])%L +RE[wz]);
	}
}