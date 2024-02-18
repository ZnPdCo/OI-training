#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define maxn 100005
#define ll long long
#define oo 1e9
using namespace std;

struct seg{
	int lson,rson,mi;
}t[maxn * 50];

ll n,q,g,r,m,L;

int root,poi;

ll a[maxn],s[maxn],p[maxn];

ll ask[maxn];

ll wait[maxn];

void insert(int &rt,int l,int r,int x,int y){
	if (!rt) rt=++poi;
	if (l==r) {
		if (t[rt].mi==0 || t[rt].mi>y) t[rt].mi=y;
		return ;
	}
	int mid=(l+r) >> 1;
	if (x<=mid) insert(t[rt].lson,l,mid,x,y);
	else insert(t[rt].rson,mid+1,r,x,y);
	t[rt].mi=oo;
	if (t[t[rt].lson].mi!=0) t[rt].mi=min(t[rt].mi,t[t[rt].lson].mi);
	if (t[t[rt].rson].mi!=0) t[rt].mi=min(t[rt].mi,t[t[rt].rson].mi);
}

int query(int rt,int l,int r,int x,int y){
	if (x>y) return oo;
	if (rt==0) return oo;
	if (l==x && r==y) return t[rt].mi;
	int mid=(l+r) >> 1;
	if (y<=mid) return query(t[rt].lson,l,mid,x,y);
	else if (x>mid) return query(t[rt].rson,mid+1,r,x,y);
	else return min(query(t[rt].lson,l,mid,x,mid),query(t[rt].rson,mid+1,r,mid+1,y));
}

int main(){
	scanf("%lld%lld%lld",&n,&g,&r);
	root=poi=1;
	L=g+r;
	fo(i,1,n+1) scanf("%lld",&a[i]),s[i]=s[i-1]+a[i],p[i]=s[i] % L;
	scanf("%lld",&m);
	fo(i,1,m) scanf("%lld",&ask[i]);
	wait[n]=0;
	insert(root,0,L-1,p[n],n);
	fd(i,n-1,1) {
		int next=oo;
		next=min(next,query(root,0,L-1,p[i]+g,L-1));
		next=min(next,query(root,0,L-1,max(0ll,g+p[i]-L),p[i]-1));
		if (next==oo) {
			wait[i]=0;
		}
		else {
			wait[i]=wait[next]+L-(s[next]-s[i]) % (L);
		}
		insert(root,0,L-1,p[i],i);
	}
	fo(i,1,m) {
		ll tmp=ask[i] % L;
		int next=oo;
		ll w=0;
		next=min(next,query(1,0,L-1,max(0ll,g-tmp),L-1-tmp));
		next=min(next,query(1,0,L-1,max(L+1-tmp,L+g-tmp),L-1));
		if (next==oo) {
			w=0;
		}
		else {
			w=wait[next]+L-(s[next]+tmp) % (L);
		}
		printf("%lld\n",ask[i]+w+s[n+1]);
	}
	return 0;
}