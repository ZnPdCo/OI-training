#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int i,j,k,n,m,t;
long long a[200000],f[200000],bz[600000],ans,s,p,g,r;
int main(){  
	scanf("%d%lld%lld",&n,&g,&r);p=g+r;
	for (i=1;i<=n+1;i++){
		scanf("%lld",&a[i]);
	}
	for (i=n;i>=1;i--){
		k=0;s=0;
		for (j=i+1;j<=n;j++){
			s=(s+a[j])%p;
			f[i]+=a[j];
			if (s>=g) {
				f[i]+=f[j]+p-s;break;
			}
		} 
	}
	scanf("%d",&t);
	while (t--){
		scanf("%d",&m);s=m%p; ans=m+a[n+1]; 
		for (i=1;i<=n;i++){
			s=(s+a[i])%p;
			ans+=a[i];
			if (s>=g){
				ans+=p-s+f[i];break; 
			}
		} 
		printf("%lld\n",ans);
	}
}