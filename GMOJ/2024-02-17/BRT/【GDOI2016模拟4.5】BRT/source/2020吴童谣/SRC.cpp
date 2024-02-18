#include<iostream>
#include<cstdio>
#define re register int
#define il inline
using namespace std;
const int N=1e5+10;
int n,Q;
long long sum[N],st,tm[N],g,r;
int main(){
	scanf("%d%lld%lld",&n,&g,&r);
	for(re i=1;i<=n+1;i++)
		scanf("%d",&tm[i]);
	sum[n]=tm[n+1];
	for(re i=n-1;i>=1;i--){
		long long res=0,res1=0;
		bool gg=0;
		for(re j=i+1;j<=n;j++){
			res+=tm[j];
			res1+=tm[j];
			res=res%(g+r);
			if(res==0)res=g+r;
			if(res>=g){
				gg=1;
				sum[i]=res1+g+r-res+sum[j];
				break;
			}
		}
		if(!gg){
			sum[i]=res1+tm[n+1];
		}
	}
	scanf("%d",&Q);
	while(Q--){
		scanf("%lld",&st);
		long long res=st,res1=st,ans=0;
		for(re i=1;i<=n;i++){
			res+=tm[i];
			res1+=tm[i];
			res=res%(g+r);
			if(res==0)res=g+r;
			if(res>=g){
				ans=sum[i]+res1+g+r-res;
				break;
			}
		}
		if(ans==0)ans=res1+tm[n+1];
		printf("%lld\n",ans);
	}
	return 0;
}