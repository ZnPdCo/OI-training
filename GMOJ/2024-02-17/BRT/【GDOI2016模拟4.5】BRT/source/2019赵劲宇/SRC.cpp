#include<cstdio>
#include<iostream>
#include<cstring>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,b,a) for(int i=b;i>=a;i--)
#define ll long long
#define N 100007
#define INF
using namespace std;
int n,g,r;
ll l[N],f[N],m;
int main(){
	scanf("%d%lld%lld",&n,&g,&r);
	int p=g+r;
	fo(i,1,n+1) scanf("%lld",&l[i]),l[i]+=l[i-1];
	fd(i,n,1){
		fo(j,i+1,n+1){
			int md=l[j]-l[i];
			md%=p;
			if(j==n+1){
				f[i]=l[n+1]-l[i];
				break;
			}
			if(md>=g){
				f[i]=l[j]-l[i]+f[j]+(p-md);
				break;
			}
		}
	}
	scanf("%d",&m);
	while(m--){
		ll x;
		scanf("%lld",&x);
		ll o=x%p;
		fo(i,1,n+1){
			int md=o+l[i];
			md%=p;
			if(i==n+1){
				printf("%lld\n",l[i]+x);
				break;
			}
			if(md>=g){
				printf("%lld\n",f[i]+(p-md)+l[i]+x);
				break; 
			}
		}
	}
}