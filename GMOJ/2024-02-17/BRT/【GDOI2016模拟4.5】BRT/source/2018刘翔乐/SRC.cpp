#include<cstdio>
using ll=long long;
constexpr ll inf=2147483647;
char buf[4194304];
inline ll Read()
{
	static char *p=buf;
	while(*p<'0')
	{
		++p;
	}
	ll ans=*p^48;
	while(*(++p)>='0')
	{
		ans=ans*10+(*p^48);
	}
	return ans;
}
inline int Min(const int a,const int b)
{
	return a<b?a:b;
}
struct Node
{
	int data;
	Node *lc,*rc;
	Node():data(inf),lc(nullptr),rc(nullptr){}
	~Node()
	{
		delete lc;
		delete rc;
	}
	inline void Update(const int l,const int r,const int pos,const int val)
	{
		data=val;
		if(l<r)
		{
			const int mid=(l+r)/2;
			if(pos<=mid)
			{
				if(lc==nullptr)
				{
					lc=new Node;
				}
				lc->Update(l,mid,pos,val);
			}
			else
			{
				if(rc==nullptr)
				{
					rc=new Node;
				}
				rc->Update(mid+1,r,pos,val);
			}
		}
		return;
	}
	inline int Query(const int l,const int r,const int L,const int R)const
	{
		if(l==L&&R==r)
		{
			return data;
		}
		const int mid=(l+r)/2;
		if(R<=mid)
		{
			return lc==nullptr?inf:lc->Query(l,mid,L,R);
		}
		if(mid<L)
		{
			return rc==nullptr?inf:rc->Query(mid+1,r,L,R);
		}
		return Min((lc==nullptr?inf:lc->Query(l,mid,L,mid)),(rc==nullptr?inf:rc->Query(mid+1,r,mid+1,R)));
	}
};
ll a[100001],f[100001];
int main()
{
	fread(buf,1,4194304,stdin);
	const ll n=Read(),g=Read(),r=Read(),turn=g+r,size=turn-1;
	for(ll i=1;i<=n;++i)
	{
		a[i]=Read()+a[i-1];
	}
	Node *tr=new Node;
	for(ll i=n;i>=1;--i)
	{
		tr->Update(0,size,a[i]%turn,i);
		const ll &val=a[i-1],l=(g+val)%turn,r=(size+val)%turn;
		const int upd=(l<=r?tr->Query(0,size,l,r):Min(tr->Query(0,size,l,size),tr->Query(0,size,0,r)));
		f[i]=(upd==inf?a[n]-val:((a[upd]-val)/turn+1)*turn+(upd<n?f[upd+1]:0));
	}
	const ll add=Read();
	ll T=Read();
	while(T--)
	{
		const ll val=Read(),l=((g-val)%turn+turn)%turn,r=size-val%turn,upd=(l<=r?tr->Query(0,size,l,r):Min(tr->Query(0,size,l,size),tr->Query(0,size,0,r)));
		printf("%lld\n",(upd==inf?a[n]+val:((a[upd]+val)/turn+1)*turn+(upd<n?f[upd+1]:0))+add);
	}
	delete tr;
	return 0;
}