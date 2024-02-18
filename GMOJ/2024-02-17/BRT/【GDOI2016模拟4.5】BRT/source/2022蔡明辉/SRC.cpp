#include<cstdio>
#include<iostream>
using namespace std;
const long long N=1e6+10;
long long n,q,g,rr,a[N],i,j,b[N],l[N],r[N],num[N],ans[N];
void qsort(long long l,long long r)
{
	long long i=l,j=r,mid=b[(l+r)/2];
	while(i<=j)
	{
		while(b[i]<mid) i++;
		while(b[j]>mid) j--;
		if(i<=j)
		{
			swap(num[i],num[j]);
			swap(b[i++],b[j--]);
		}
	}
	if(i<r) qsort(i,r);
	if(l<j) qsort(l,j);
}
void qsort1(long long l,long long r)
{
	long long i=l,j=r,mid=num[(l+r)/2];
	while(i<=j)
	{
		while(num[i]<mid) i++;
		while(num[j]>mid) j--;
		if(i<=j)
		{
			swap(num[i],num[j]);
			swap(ans[i++],ans[j--]);
		}
	}
	if(i<r) qsort1(i,r);
	if(l<j) qsort1(l,j);
}
int main()
{
    scanf("%lld%lld%lld",&n,&g,&rr);
    for(i=0;i<=n;i++) scanf("%lld",&a[i]);
    scanf("%lld",&q);
    for(i=1;i<=q;i++) num[i]=l[i]=r[i]=i;
    for(i=1;i<=q;i++) scanf("%lld",&b[i]);
    qsort(1,q);
    b[0]=q;
    for(i=0;i<n;i++)
    {
    	long long tmp=0;
    	for(j=1;j<=b[0];j++)
    	{
    		b[j]+=a[i];
    		if(b[j]%(g+rr)>=g) b[j]=((b[j]-1)/(g+rr)+1)*(g+rr);
    		if(b[tmp]!=b[j])
    		{
    			b[++tmp]=b[j];
    			l[tmp]=l[j],r[tmp]=r[j];
			}
			else r[tmp]=r[j];
		}
		for(j=tmp+1;j<=b[0];j++) b[j]=l[j]=r[j]=0;
		b[0]=tmp;
	}
	for(i=1;i<=b[0];i++)
	{
		for(j=l[i];j<=r[i];j++) ans[j]=b[i];
	}
	qsort1(1,q);
	for(i=1;i<=q;i++) printf("%lld\n",ans[i]+a[n]);
    return 0;
}