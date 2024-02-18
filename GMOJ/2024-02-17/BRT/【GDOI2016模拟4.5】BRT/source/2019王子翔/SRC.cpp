//#sumragma GCC optimize(2)
#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
int read(){
	int res=0,f=1;
	char ch=getchar();
	if(ch=='-')	f=-1,ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') res=res*10+ch-'0',ch=getchar();
	return res*f;
}
int i,j,k,n,m,q;
ll t[N],f[N],ans,s,sum,g,r;
int main(){
	scanf("%d%lld%lld",&n,&g,&r);
	sum=g+r;
	for(i=1;i<=n+1;++i)
		t[i]=read();
	for(i=n;i>=1;--i,s=0)
		for(j=i+1;j<=n;++j){
			s=(s+t[j])%sum;
			f[i]+=t[j];
			if(s>=g){
				f[i]+=f[j]+sum-s;break;
			}
		}
	q=read();
	for(;q;--q){
		m=read(),s=m%sum;
		ans=m+t[n+1];
		for(i=1;i<=n;++i){
			s=(s+t[i])%sum;
			ans+=t[i];
			if(s>=g){
				ans+=sum-s+f[i];
				break;
			}
		}
		printf("%lld\n",ans);
	}
}