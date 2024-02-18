#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<iostream>
#include<algorithm>

using namespace std;

#define fo(i,a,b) for (int i=a;i<=b;i++)
#define fd(i,a,b) for (int i=a;i>=b;i--)
	
typedef long long ll;

const int maxn=2100000;
const int INF=1<<30;

int N,G,R,L,Q,tot,id,a[maxn],lch[maxn],rch[maxn],mn[maxn];
ll ans,sum[maxn],s[maxn];

void modify(int pos,int x,int y,int a,int b)
{
	if (x==y)
	{
		mn[pos]=b;
		return;
	}
	int mid=(x+y)/2;
	if (a<=mid)
	{
		if (!lch[pos]) lch[pos]=++tot;
		modify(lch[pos],x,mid,a,b);
	}
	else
	{
		if (!rch[pos]) rch[pos]=++tot;
		modify(rch[pos],mid+1,y,a,b);
	}
	mn[pos]=b;
}

int query(int pos,int x,int y,int xx,int yy)
{
	if (!pos) return INF;
	if (x==xx&&y==yy) return mn[pos];
	int mid=(x+y)/2;
	if (yy<=mid) return query(lch[pos],x,mid,xx,yy);
	else
	if (xx>mid) return query(rch[pos],mid+1,y,xx,yy);
	else return min(query(lch[pos],x,mid,xx,mid),query(rch[pos],mid+1,y,mid+1,yy));
}

int main()
{
	scanf("%d%d%d",&N,&G,&R);
	L=G+R;
	fo(i,1,N+1) scanf("%d",&a[i]),s[i]=s[i-1]+a[i];
	tot=1;
	fd(i,N,1)
	{
		int l,r;
		l=max(G+(int)(s[i]%L),0);
		r=min(L+(int)(s[i]%L-1),INF);
		if (l<=r) id=query(1,0,INF,l,r);
		l=max(G-L+(int)(s[i]%L),0);
		r=min((int)(s[i]%L-1),INF);
		if (l<=r) id=min(id,query(1,0,INF,l,r));
		if (id==INF) sum[i]=s[N+1]-s[i];
		else sum[i]=sum[id]+((s[id]-s[i])/L+((s[id]-s[i])%L!=0))*L;
		modify(1,0,INF,(int)(s[i]%L),i);
	}
	scanf("%d",&Q);
	while (Q--)
	{
		int x,l,r;
		scanf("%d",&x);
		l=max(G-x%L,0);
		r=min(L-1-x%L,INF);
		if (l<=r) id=query(1,0,INF,l,r);
		l=max(G+L-x%L,0);
		r=min(L+L-x%L-1,INF);
		if (l<=r) id=min(id,query(1,0,INF,l,r));
		if (id==INF) ans=s[N+1]+x;
		else ans=sum[id]+((x+s[id])/L+((x+s[id])%L!=0))*L;
		printf("%lld\n",ans);
	}
}