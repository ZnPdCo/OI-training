# include <bits/stdc++.h>
using namespace std;

# define fo(i,a,b) for(i=a;i<=b;++i)
# define fd(i,a,b) for(i=a;i>=b;--i)

const int maxn=2000005;

long long pre[maxn],t[maxn],rem[maxn],cnt=1;

struct tree
{
	int num,lson,rson;
}tr[maxn<<4];

inline void down(int k)
{
	if(!tr[k].lson) tr[k].lson=++cnt;
	if(!tr[k].rson) tr[k].rson=++cnt;
	tr[tr[k].lson].num=tr[k].num;
	tr[tr[k].rson].num=tr[k].num;
	tr[k].num=0;
}

void ins(int k,int l,int r,int x,int y,int z)
{
	if(x<=l && y>=r)
	{
		tr[k].num=z;
	//if(x==0) cout<<k<<" "<<l<<" "<<r<<" "<<x<<" "<<y<<" "<<z<<" "<<tr[k].num<<"\n";
		return;
	}
	if(tr[k].num) down(k);
	int mid=(l+r)>>1;
	if(x<=mid) 
	{
		if(!tr[k].lson) tr[k].lson=++cnt;
		ins(tr[k].lson,l,mid,x,y,z);
	}
	if(y>mid) 
	{
		if(!tr[k].rson) tr[k].rson=++cnt;
		ins(tr[k].rson,mid+1,r,x,y,z); 
	}
}

int find(int k,int l,int r,int x)
{
	if(tr[k].num) return tr[k].num;
	int mid=(l+r)>>1;
	if(x<=mid && tr[k].lson) return find(tr[k].lson,l,mid,x);
	else if(x>mid && tr[k].rson) return find(tr[k].rson,mid+1,r,x);
	return 0;
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL);
	int n,m,g,r,i,tmp,tmp2;
	long long x,ans;
	cin>>n>>g>>r;
	fo(i,1,n+1)
	{
		cin>>t[i];
		pre[i]=pre[i-1]+t[i];
	}
	fd(i,n,1)
	{
		tmp2=(g+r-pre[i]%(g+r))%(g+r);
		tmp=find(1,0,g+r-1,tmp2);
		if(tmp==0) rem[i]=pre[n+1]-pre[i];
		else rem[i]=g+r-(tmp2+pre[tmp])%(g+r)+rem[tmp]+pre[tmp]-pre[i];
		tmp=pre[i]%(g+r);
		if(tmp<=g) ins(1,0,g+r-1,g-tmp,g+r-1-tmp,i);
		else
		{
			ins(1,0,g+r-1,0,g+r-1-tmp,i);
			ins(1,0,g+r-1,g+r-tmp+g,g+r-1,i);
		}
	}
	cin>>m;
	fo(i,1,m)
	{
		cin>>x;
		tmp=find(1,0,g+r-1,x%(g+r));
		if(tmp==0) ans=pre[n+1]+x;
		else ans=x+pre[tmp]+g+r-(x+pre[tmp])%(g+r)+rem[tmp];
		cout<<ans<<"\n";
	}
	return 0;
}