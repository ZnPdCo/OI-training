#include<bits/stdc++.h>
#define rg register
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
mt19937 rnd(time(0));
long long a[1000005];int w;
long long mp[1000005];	int n,g,r;
long long dg(rg long long x,rg int st,rg int ed)
{
	if(st==ed+1)
	{
		return x;
	}
	rg int c=(x%w);
	if(c>=g)
	{
		x+=(w-c);
		if(mp[st]>0)
		{
			return x+mp[st];
		}
		mp[st]=dg(0,st,ed);
		return x+mp[st];
	}
	x+=a[st];
	return dg(x,st+1,ed);
}
int main()
{

	scanf("%d%d%d",&n,&g,&r);
	w=g+r;
	for(rg int i=0;i<=n;i++) scanf("%lld",&a[i]);
	rg int q;
	scanf("%lld",&q);
	while(q--)
	{
		rg long long x;
		scanf("%lld",&x);
		x+=a[0];
		long long k=dg(x,1,n);
//		for(long long i=1;i<=n;i++) printf("%lld ",mp[i]);
//		printf("\n");
		printf("%lld\n",k);
	}
	return 0;
}
